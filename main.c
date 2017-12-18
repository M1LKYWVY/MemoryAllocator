#include <stdio.h>
#include "mem.h"

int main() {
    void * p = heap_init(4096);

    if(p == NULL) {
        fprintf(stderr,"%s", "Cannot initialize heap!");
        return 1;
    }

    int *pointers[80];

    for (size_t i = 20; i < 100 ; ++i) {
        pointers[i-20] = _malloc(i);
        *pointers[i-20] = (int)i;
        if(!pointers[i-20])
            break;
    }


    FILE *f = fopen("heap.txt","w");
    malloc_debug_heap(f,p);
    puts("Debug file \"heap.txt\" created. (After allocating)");
    fclose(f);


    for (int i = 20; i < 100; ++i) {
        _free(pointers[i-20]);
    }

    f = fopen("heap_after_free.txt","w");
    malloc_debug_heap(f,p);
    puts("Debug file \"heap_after_free.txt\" created. (After free)");

    fclose(f);

    return 0;
}