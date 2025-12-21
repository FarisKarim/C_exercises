#include <stdio.h>
#include <stdint.h>

int main(void) {
    int E[10];
    for (int i = 0; i < 10; i++) E[i] = 100 + i;

    int i = 3;
    printf("&E[0] = %p\n", (void*)&E[0]);
    printf("&E[%d] = %p (should be base + %zu bytes)\n",
           i, (void*)&E[i], (size_t)i * sizeof(int));

    printf("E[%d] = %d\n", i, E[i]);

    printf("E[5] = %d\n", E[5]);
    printf("&E[5] = %p (should be base + 20 bytes, or &E[3] + 8 bytes)\n", (void*)&E[5]);
    
    // &E[i] is a pointer to an int, compiler divides by size of int
    printf("Total bytes: %zu\n", &E[10] - &E[0]);
    printf("Total bytes: %zu\n", (char*)&E[10] - (char*)&E[0]);

    return 0;
}
