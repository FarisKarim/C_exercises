#include <stdio.h>
#include <stdint.h>

static int var_ele(long n, int A[n][n], long i, long j) {
    return A[i][j];
}

int main(void) {
    long n = 7;
    int A[n][n];

    for (long i = 0; i < n; i++)
        for (long j = 0; j < n; j++)
            A[i][j] = (int)(1000 + 10*i + j);

    long i = 4, j = 2;
    int val = var_ele(n, A, i, j);

    printf("A[%ld][%ld] = %d\n", i, j, val);

    // verify formula with addresses
    int *base = &A[0][0];
    int *addr = &A[i][j];
    int *calc = base + (n*i + j);

    printf("base          = %p\n", (void*)base);
    printf("&A[i][j]      = %p\n", (void*)addr);
    printf("calc (n*i+j)  = %p\n", (void*)calc);

    return 0;
}
