//
// Created by Dreamer on 17/12/2017.
//

#include "mem.h"

void mark_chunk(size_t size, struct mem* chunk)
{
    struct mem chunk_header;
    chunk_header.next = NULL;
    chunk_header.capacity = size;
    chunk_header.is_free = true;
    *chunk = chunk_header;
}
//Initializing heap of memory
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

void* _malloc( size_t query )
{
    /*
     * Check size of query. Modify if too small.
     * There is no point in allocating small amount of memory.
     */
    if (query<MINIMAL_BLOCK_SIZE)
    {
        query = MINIMAL_BLOCK_SIZE;
    }

    struct mem *node = (struct mem*)HEAP_START;

    while (node)
    {
        if(node->is_free && node->capacity>query+MINIMAL_BLOCK_SIZE)
        {
            size_t remainder = node->capacity-query;
//            printf("%d", (int)remainder);
            node->capacity = remainder;
            struct mem *current = (struct mem*)((void*)node + node->capacity + sizeof(struct mem));
            mark_chunk(query, current);
            current->is_free = false;
            current->next = node->next;
            node->next = current;
            return current;

        }
        if (!node->next)
        {
            void* next_chunk = mmap(node+node->capacity, query, PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_FIXED,-1,0);
            if (next_chunk==MAP_FAILED)
                next_chunk = mmap(0, query, PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_FIXED,-1,0);
            if (next_chunk==MAP_FAILED)
                return NULL;
            node->next = (struct mem*) next_chunk;
        }
        node = node->next;
    }

    void _free(void* mem)
    {
        mem-=sizeof(struct mem);
        struct mem* iterate = (struct mem*)mem;
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

}

