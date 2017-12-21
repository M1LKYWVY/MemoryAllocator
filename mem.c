//
// Created by Dreamer on 17/12/2017.
//

#include <unistd.h>
#include "mem.h"
#define MIN_BLOCK_SIZE 256

static struct mem* heap = NULL;
static struct mem* heap_end = NULL;

static long default_page_size = 4096;
void *heap_start = (void *) 0x04040000;

static struct mem* split_block(struct mem* src, size_t target_capacity) {

    struct mem* rem;
    rem = (void*)src + sizeof(struct mem) + target_capacity;

    rem->is_free = true;
    rem->capacity = src->capacity - sizeof(struct mem) - target_capacity;
    rem->next = src->next;

    src->capacity = target_capacity;
    src->next = rem;

    return rem;
}

    void* heap_init(size_t initial_size)
    {
    heap = mmap(heap_start, initial_size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0);
    if(heap == MAP_FAILED)
        return MAP_FAILED;
    heap->capacity = initial_size - sizeof(struct mem);
    heap->next = NULL;
    heap->is_free = true;
    heap_end = heap;
    return heap;
    }

    static void* find_block(size_t query)
    {
    struct mem* block = heap;
    for(; block; block = block->next) {
        if(block->is_free && block->capacity >= query)
        {
            return block;
        }
    }

    return NULL;
    }

    void* _malloc(size_t query)
    {

        if((!heap || heap == MAP_FAILED))
        {
//            default_page_size = (size_t)sysconf(_SC_PAGESIZE);

            if(heap_init((size_t) default_page_size) == MAP_FAILED)
            {
                return NULL;
            }
        }
        if (query<MIN_BLOCK_SIZE)
            query = MIN_BLOCK_SIZE;
        struct mem* block = find_block(query);
        if (block)
        {
            if (query + MIN_BLOCK_SIZE + sizeof(struct mem)<=block->capacity)
            {
                struct mem* rem = split_block(block, query);
                if(block == heap_end) {
                    heap_end = rem;
                }
            }
            block->is_free = false;
            return (void*)block + sizeof(struct mem);
        }
        void* new_address = (void*)heap_end + sizeof(struct mem) + heap_end->capacity;
        int pages_needed = (int)((query+sizeof(struct mem) )/ default_page_size);
        if((query + sizeof(struct mem)) % default_page_size != 0) pages_needed++;
        size_t alloc_size = (size_t)pages_needed * default_page_size;
        block = mmap(new_address, alloc_size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        if(block == MAP_FAILED)
            return NULL;

        if((void*)block == new_address)
        {
            if(heap_end->is_free)
            {
                heap_end->capacity = heap_end->capacity + alloc_size;
                block = heap_end;
            }
            else
            {
                block->capacity = alloc_size - sizeof(struct mem);
                block->next = NULL;
                heap_end->next = block;

                heap_end = block;
            }

            if(query + MIN_BLOCK_SIZE + sizeof(struct mem)<=block->capacity)
            {
                struct mem* rem = split_block(block, query);
                block->is_free = false;
                struct mem* ret = block;
                heap_end = rem;
                return (void*)ret + sizeof(struct mem);
            }

            block->is_free = false;
            return (void*)block + sizeof(struct mem);
        }
        else
        {
            block->capacity = alloc_size - sizeof(struct mem);
            block->next = NULL;
            block->is_free = false;
            heap_end->next = block;
            if(query + MIN_BLOCK_SIZE + sizeof(struct mem)<=block->capacity)
            {
                struct mem* rem = split_block(block, query);
                heap_end = rem;
            }
            else
            {
                heap_end = block;
            }
            return (void*)block + sizeof(struct mem);
        }
    }


void _free(void* mem)
{
    if(mem == NULL) return;

    mem -= sizeof(struct mem);
    struct mem* smem = (struct mem*)mem;
    struct mem* current_block = (struct mem*)mem;

    smem->is_free = true;

    for(; smem; smem = smem->next)
    {
        if(!smem->next) return;

        if(smem->next->is_free)
        {
            if(smem->next == (void*)current_block + sizeof(struct mem) + smem->capacity)
            {
                if(smem->next == heap_end)
                    heap_end = current_block;
                current_block->capacity += sizeof(struct mem) + smem->next->capacity;
                current_block->next = smem->next->next;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

 void malloc_debug_struct_info( FILE* f,
                                        struct mem const* const address ) {
     size_t i;

     fprintf(f, "start: %p\nsize: %lu\nis_free: %d\n", (void*)address, address-> capacity, address-> is_free );

     for (i = 0; i < DEBUG_FIRST_BYTES && i < address-> capacity; ++i)
         fprintf( f, "%hhX", ((char*)address)[sizeof(struct mem) + i]);

     putc('\n', f);
}

void malloc_debug_heap(FILE *f) {
    struct mem* ptr = heap;
    for( ; ptr; ptr = ptr->next ) {
        malloc_debug_struct_info(f, ptr);
    }
}


