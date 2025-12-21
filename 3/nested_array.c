#include <stdio.h>
#include <stdint.h>

int main(void) {
    int A[5][3];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            A[i][j] = 1000 + 10*i + j;

    int i = 3, j = 1;
    int *base = &A[0][0];

    // cast pointer to int to generic pointer
    printf("base &A[0][0] = %p\n", (void*)base);
    printf("&A[%d][%d]    = %p\n", i, j, (void*)&A[i][j]);

    // formula: &A[i][j] = base + (C*i + j), scaled by sizeof(int) ( X 4)
    int C = 3;
    int *calc = base + (C*i + j);

    printf("calc address  = %p (base + (3*%d + %d) ints)\n", calc, i, j);
    printf("A[%d][%d] = %d\n", i, j, A[i][j]);

    return 0;
}
