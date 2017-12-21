//
// Created by Dreamer on 17/12/2017.
//

#ifndef MEMORY_ALLOCATOR_MEM_H
#define MEMORY_ALLOCATOR_MEM_H

#define _USE_MISC
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdbool.h>
#define HEAP_START ((void*)0x04040000)

struct mem;
#pragma pack(push, 1)
struct mem {
    struct mem* next;
    size_t capacity;
    bool is_free;
};
#pragma pack(pop)
void* _malloc( size_t query );
void _free( void* mem );
void* heap_init( size_t initial_size );
#define DEBUG_FIRST_BYTES 4
void malloc_debug_struct_info(FILE* f, struct mem const* const address);
void malloc_debug_heap(FILE* f);

#endif //MEMORY_ALLOCATOR_MEM_H
