#include "memoryPool.h"
#include <stdlib.h>
#include <vector>
// Size of metadata of a chunk
const size_t HEADER_SIZE = sizeof(Chunk);

// BlockSize
// We get memory size integer times of BlockSize
const size_t BLOCK_SIZE = 4096;

// Flag: end of a block
const unsigned char BLOCK_FLAG = 0xEE;

// Constructor
MemoryPool::MemoryPool():header(NULL){}

// Destructor
MemoryPool::~MemoryPool()
{
    if (header == NULL)
        return;
    std::vector<void*> Delete;
    Chunk* chunk = header->nxtNode;
    // chunk->preChunk == NULL 
    // means this is the first address
    // of the block that is allocated from OS
    if(header->preChunk == NULL)
        Delete.push_back(reinterpret_cast<void*>(header));
    while(chunk != header)
    {
        if (chunk->preChunk == NULL)
            Delete.push_back(reinterpret_cast<void*>(chunk));
        chunk = chunk->nxtNode;
    }
    for (auto ptr : Delete)
        free(ptr);
}

// Allocate memory from OS
// Memory size is integer times of BlockSize
MemoryPool::data_pointer MemoryPool::allocateMemory(size_type size, size_type& totalSize)
{
    totalSize = (size + HEADER_SIZE + sizeof(BLOCK_FLAG) + BLOCK_SIZE - 1) / BLOCK_SIZE * BLOCK_SIZE;
    data_pointer ret = reinterpret_cast<data_pointer>(malloc(totalSize));
    ret[totalSize - sizeof(BLOCK_FLAG)] = BLOCK_FLAG;     // Set BLOCK_FLAG
    return ret;
}


// Allocate memory from memory pool
// Size is the size of memory that you intend to allocate from MemoryPool
MemoryPool::pointer MemoryPool::allocate(size_type size)
{
    // If not allocated or not enough space
    if (header == NULL || header->size < size)
    {
        // Allocate new block from OS
        size_type totalSize; // The total memory allocated from OS, integer times of BlockSize
        data_pointer ptr = allocateMemory(size, totalSize);
        Chunk* chunk = reinterpret_cast<Chunk*>(ptr);

        chunk->isFree = 1;      // Available chunk
        chunk->preChunk = NULL; // preChunk = NULL means this is the first address of block
        chunk->size = totalSize - HEADER_SIZE - sizeof(BLOCK_FLAG);  // Memory size to store data
        // Insert chunk into free list
        insertNode(chunk, header);
        header = chunk;   // New header of free list
    }

    // Return address
    pointer ret = reinterpret_cast<pointer>(
        reinterpret_cast<data_pointer>(header) + HEADER_SIZE
    );

    // Left chunk after part of the original chunk is allocated
    Chunk* chunk = reinterpret_cast<Chunk*>(
        reinterpret_cast<data_pointer>(header) + HEADER_SIZE + size
    );
    
    // Next chunk of the original chunk in the same block
    // If only one chunk, Block_END is met
    Chunk* nxtChunk = reinterpret_cast<Chunk*>(
        reinterpret_cast<data_pointer>(header) + HEADER_SIZE + header->size
    );

    header->isFree = 0;       // Chunk is used--to be returned
    if (header->size > size + HEADER_SIZE)    // If left enough space
    {
        chunk->isFree = 1;                    // Left chunk is the new free chunk
        chunk->preChunk = header;             // Its preChunk
        chunk->size = header->size - size - HEADER_SIZE; // Left size

        header->size = size;                  // ret chunk size
        if (*reinterpret_cast<data_pointer>(nxtChunk) != BLOCK_FLAG)
            nxtChunk->preChunk = chunk;     // Update link

        Chunk* oldHead = header;      
        insertNode(chunk, oldHead);        // Insert new free chunk into free list
        removeNode(oldHead);               // Delete used chunk
    }
    else
        removeNode(header);                  // The chunk is used up

    // Maintain the free list, try to keep it largest chunk in header
    maintainList();                 
    return ret;
}

// Release memory, recycle to memorypool
void MemoryPool::deallocate(data_pointer ptr)
{
    Chunk* chunk = reinterpret_cast<Chunk*>(ptr - HEADER_SIZE); // Chunk information
    Chunk* preChunk = chunk->preChunk;      // Previous chunk in the same block     
    Chunk* nxtChunk = reinterpret_cast<Chunk*>(ptr + chunk->size);// Next chunk in the same block
    // Set free
    chunk->isFree = 1;
    // Merge next neighboring chunk if the next chunk is free
    if (*reinterpret_cast<data_pointer>(nxtChunk) != BLOCK_FLAG && nxtChunk->isFree)
    {
        mergeChunk(chunk);      // Merge next chunk
        removeNode(nxtChunk);
    }
    // Merge previous neighboring chunk if the previous chunk is free
    if (preChunk != NULL && preChunk->isFree)
        mergeChunk(preChunk);
    else
        insertNode(chunk, header);
    maintainList();
}



// Insert chunk after preNode in free list
void MemoryPool::insertNode(Chunk* chunk, Chunk* preNode)
{
    if (preNode == NULL)        // Empty list
    {
        chunk->preNode = chunk->nxtNode = chunk;  // Doubly linked list
        header = chunk;
    }
    else{
        chunk->preNode = preNode;
        chunk->nxtNode = preNode->nxtNode;
        preNode->nxtNode->preNode = chunk;
        preNode->nxtNode = chunk;
    }
}

// Remove chunk from free list
void MemoryPool::removeNode(Chunk* chunk)
{
    if (header == chunk)
        header = header->nxtNode;   // Next Node

    if (chunk->preNode == chunk && chunk->nxtNode == chunk)
        header = NULL;            // One node list
    else
    {   // Change the link relation
        chunk->preNode->nxtNode = chunk->nxtNode;
        chunk->nxtNode->preNode = chunk->preNode;
    }
}

// Merge chunk with its next chunk
void MemoryPool::mergeChunk(Chunk* chunk)
{
    data_pointer ptr = reinterpret_cast<data_pointer>(chunk);
    Chunk* nxtChunk = reinterpret_cast<Chunk*>(ptr + HEADER_SIZE + chunk->size); // Next Chunk
    chunk->size += HEADER_SIZE + nxtChunk->size;    // New chunk size

    ptr = reinterpret_cast<data_pointer>(nxtChunk);
    if (ptr[HEADER_SIZE + nxtChunk->size] != BLOCK_FLAG)
    {
        nxtChunk = reinterpret_cast<Chunk*>(ptr + HEADER_SIZE + nxtChunk->size); // Next next chunk
        nxtChunk->preChunk = chunk;
    }
}

// Maintain free list
void MemoryPool::maintainList()
{
    if (header == NULL)
        return;
    if (header->size < header->nxtNode->size)
        header = header->nxtNode;
    else if (header->size > header->nxtNode->size && header->nxtNode->nxtNode != header)
    {
        Chunk* chunk = header->nxtNode;
        removeNode(chunk);
        insertNode(chunk, header->preNode);
    }
}
