#include <stdio.h>

#include "mem.h"

static void create_debug_file(const char* path) {
    FILE* f = fopen(path, "w");
    malloc_debug_heap(f);
    fclose(f);
}

int main() {

    void* first = _malloc(257);

    create_debug_file("after_first_malloc.txt");

    void* second = _malloc(64);

    create_debug_file("before_free.txt");

    _free(second);

    create_debug_file("after_free_second.txt");

    _free(first);

    create_debug_file("after_free_first.txt");

    if(_malloc(4096) == NULL) {
        printf("Allocation error!\n");
        return 1;
    }
    create_debug_file("page_alloc.txt");

    if(_malloc(3) == NULL) {
        printf("Allocation error!\n");
        return 1;
    }
    create_debug_file("small_alloc.txt");

    if(_malloc(1024 * 16) == NULL) {
        printf("Allocation error!\n");
        return 1;
    }
    create_debug_file("medium_alloc.txt");

    for(int i = 0; i < 100; i++) {
        if(_malloc(16) == NULL) {
            printf("Allocation error!\n");
            return 1;
        }
    }
    create_debug_file("many_small_allocs.txt");

    for(int i = 0; i < 1000; i++) {
        if(_malloc(333) == NULL) {
            printf("Allocation error!\n");
            return 1;
        }
    }
    create_debug_file("insane.txt");
    return 0;
}