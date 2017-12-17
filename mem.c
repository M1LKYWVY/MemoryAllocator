//
// Created by Dreamer on 17/12/2017.
//

#include "mem.h"
size_t MIN_BLOCK_SIZE = 64;

static void mark_chunk(size_t size, struct mem* chunk)
{
    struct mem chunk_header;
    chunk_header.next = NULL;
    chunk_header.capacity = size;
    chunk_header.is_free = true;
    *chunk = chunk_header;
}

void* _malloc(size_t query)
{
    if(query < MIN_BLOCK_SIZE)
        query = MIN_BLOCK_SIZE;
    struct mem *node = (struct mem*) HEAP_START;
    while(node)
    {
        if(node->is_free && node->capacity>=query)
        {
            size_t remainder = node->capacity - query - sizeof(struct mem);
            node->capacity = query + sizeof(struct mem);
            struct mem *new = (struct mem*)((void*)node + node->capacity);
            *new = *node;
            new->capacity = remainder;
            node->next = new;
            node->is_free = false;
            return (void*)node + sizeof(struct mem);
        }

        if(!node->next)
        {
            void* p = mmap((void*)node + node->capacity, query,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_FIXED,-1,0);

            if(p == MAP_FAILED)
            {
                p = mmap(0, query,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
                if(p == MAP_FAILED)
                    return NULL;
            }
            mark_chunk(query,p);
            node->next = p;
        }
        node = node->next;
    }
}

void _free(void* mem)
{
    mem -= sizeof(struct mem);
    struct mem *chunk = (struct mem*)mem;
    chunk->is_free = true;
    struct mem *p = (void*)chunk+chunk->capacity;
    while(p->is_free)
    {
        chunk->capacity += p->capacity;
        p = (void*)chunk + chunk->capacity;
    }
}

void* heap_init(size_t initial_size)
{
    if(initial_size < sizeof(struct mem))
        return NULL;
    void* p = mmap(HEAP_START, initial_size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    if(p == MAP_FAILED)
        return NULL;
    mark_chunk(initial_size, p);
    return p;
}


    void malloc_debug_struct_info( FILE* f, struct mem const* const address ) {
        size_t i;
        fprintf( f,
                 "start: %p\nsize: %lu\nis_free: %d\n",
                 (void*)address,
                 address-> capacity,
                 address-> is_free );
        for ( i = 0; i < DEBUG_FIRST_BYTES && i < address-> capacity; ++i )
            fprintf( f, "%hhX",
                     ((char*)address)[ sizeof( struct mem ) + i ] );
        putc( '\n', f );
    }
    void malloc_debug_heap( FILE* f, struct mem const* ptr ) {
        for( ; ptr; ptr = ptr->next )
            malloc_debug_struct_info( f, ptr );
    }


