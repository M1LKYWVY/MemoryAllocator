#include <stdio.h>
#include "mem.h"

int main() {
    heap_init(4096);
    int* test = _malloc(128);
    test[0] = 1;
    test[1] = 2;
    printf("%d %d\n", test[0], test[1]);
    printf("Hello, World!\n");
    return 0;
}