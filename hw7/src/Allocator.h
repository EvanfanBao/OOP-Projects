#pragma once

#include <stddef.h>
#include <limits>
#include "memoryPool.h"

template <class T>
class Allocator
{
public:

    // Typedefs
    using value_type = T;
    using pointer = value_type* ;
    using const_pointer =  const value_type* ;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using data_type = unsigned char;
    using data_pointer = unsigned char*;
    
    template<typename U>
    struct rebind { typedef Allocator<U> other; };

    // Default constructor
    Allocator() = default;
    ~Allocator() = default;
    template <class U>
    Allocator(const Allocator<U>&) noexcept {};
    
    // Address information
    pointer address(reference r) { return &r; }
    const_pointer address(const_reference r) { return &r; }

    // Max size
    size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    // void construct(pointer p, const T& t) { new(p) T(t); }
    // void destroy(pointer p) { p->~T(); }

    // == and != operators
    template<class U>
    bool operator==(const Allocator<U>&) const noexcept{return true;};
    template<class U>
    bool operator!=(const Allocator<U>&) const noexcept{return false;};

    // Allocate memory, return the pointer if success
    pointer allocate(size_type n, const_pointer hint = 0){
        return reinterpret_cast<pointer>(mempool.allocate(sizeof(T) * n));
    };

    // Deallocate the memory
    void deallocate(pointer p, size_type n){
        mempool.deallocate(reinterpret_cast<data_pointer>(p));
    };
private:
    static MemoryPool mempool;  // MemoryPool
};
template <typename T> MemoryPool Allocator<T>::mempool;


