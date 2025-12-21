#include <stdio.h>
#include <stdint.h>

int main(void) {
    long n = 5;
    int B[n][n];

    for (long i = 0; i < n; i++)
        for (long j = 0; j < n; j++)
            B[i][j] = (int)(100*i + j);

    long k = 2; // fixed column
    int *Bptr = &B[0][k];

    printf("Walking down column k=%ld using Bptr += n:\n", k);
    for (long j = 0; j < n; j++) {
        printf("j=%ld  Bptr=%p  *Bptr=%d\n", j, Bptr, *Bptr);
        // Bptr++, jump to next int, +4 bytes
        Bptr += n; // jump to next row same column
    }

    return 0;
}
