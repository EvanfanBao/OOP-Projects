#pragma once

#include <cstddef>

// MemoryPool Chunk
struct Chunk
{
    unsigned char isFree;   // If this chunk is free
    Chunk* preChunk;        // Previous chunk in the same block 
    size_t size;            // Storage size of a chunk(excluding the metadata header,i.e the struct Chunk it self)
    // Doubly free list node
    Chunk* preNode;         // Previous node in doubly linked list
    Chunk* nxtNode;         // Next node in doubly linked list
};

class MemoryPool
{
public:

    // Typedefs
    using pointer = void*;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using data_type = unsigned char;
    using data_pointer = unsigned char*;

    // Allocate memory of size size
    // Return the pointer
    pointer allocate(size_type size);

    // Deallocate memory pointed by ptr
    void deallocate(data_pointer ptr);

    // Constructor
    MemoryPool();
    
    // Destructor
    ~MemoryPool();

private:
    // Free list head
    Chunk* header;

    // Allocate block of memory from OS
    // According to the size, this function
    // allocate memory of integer times of BlockSize
    // and return the pointer
    data_pointer allocateMemory(size_type size, size_type& realSize);

    // Insert chunk after preNode in the linked list
    void insertNode(Chunk* chunk, Chunk* preNode);

    // Remove chunk from free linked list
    void removeNode(Chunk* chunk);

    // Merge chunk with its next chunk
    void mergeChunk(Chunk* chunk);

    // Maintain free list
    void maintainList();
};

