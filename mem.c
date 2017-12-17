//
// Created by Dreamer on 17/12/2017.
//

#include "mem.h"
#define MIN_BLOCK_SIZE 64

/*
 * Modify chopped chunk to get ready for next work.
 */
static void mark_chunk(size_t size, struct mem* chunk)
{
    struct mem new_chunk;
    new_chunk.next = NULL;
    /*
     * Setting up capacity of chunk.
     */
    new_chunk.capacity = size;
    new_chunk.is_free = true;
    *chunk = new_chunk;
}
/*
 * Simple memory allocator.
 */
void* _malloc(size_t query)
{
    /*
     * Checking size of query.
     */
    if(query < MIN_BLOCK_SIZE)
        query = MIN_BLOCK_SIZE;
    /*
     * Initializing start of heap.
     */
    struct mem *node = (struct mem*) HEAP_START;
    while(node) {
        if (node->is_free && node->capacity >= query) {
            /*
             * Setting up remainder of current chunk.
             */
            size_t remainder = node->capacity - query - sizeof(struct mem);
            /*
             * Setting up memory of returning chunk.
             */
            node->capacity = query + sizeof(struct mem);
            /*
             * Setting up address of new (not returning) chunk.
             */
            struct mem *new = (struct mem *) ((void *) node + node->capacity);
            *new = *node;
            new->capacity = remainder;
            node->next = new;
            node->is_free = false;
            /*
             * Element of list looks like
             * ptr to next ____ sizeof(struct) ____ amount of memory.
             * we take ptr to next and add sizeof(struct) to return only address of requested amount of memory.
             * In other words, there is no doubt in returning address - (sizeof(struct)), because it is useless and silly.
             */
            return (void *) node + sizeof(struct mem);
        }

        if (!node->next) {
            /*
             * If we can not find chunk, allocating more memory from OS from pointer, on which we has stopped.
             */
            void *pointer = mmap((void *) node + node->capacity, query, PROT_READ | PROT_WRITE,
                           MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
            if (pointer == MAP_FAILED) {
                /*
                 * "If addr is NULL, then the kernel chooses the address at which to
                 * create the mapping; this is the most portable method of creating a
                 * new mapping."
                 * Copied from man page: http://man7.org/linux/man-pages/man2/mmap.2.html
                 */
                pointer = mmap(0, query, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
                if (pointer == MAP_FAILED)
                    return NULL;
            }
            mark_chunk(query, pointer);
            node->next = pointer;
        }
        node = node->next;
    }
}

void _free(void* mem)
{
    /*
     * Getting pointer to a structure from pointer to chunk of memory.
     * ptr to next ____ sizeof(struct) ____ amount of memory.
     * we need to pointer to struct.
     */
    mem -= sizeof(struct mem);
    struct mem *chunk = (struct mem*)mem;
    chunk->is_free = true;
    /*
     * Getting address of pointer to next. We need to check it on (is_free) field.
     */
    struct mem *pointer = chunk->next;
    while(pointer->is_free)
    {
        chunk->capacity += pointer->capacity;
        /*
         * Continue only if ptr to next === address of this + capacity of this + sizeof(struct)
         */
        pointer = (void*)chunk+chunk->capacity+ sizeof(struct mem);
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


