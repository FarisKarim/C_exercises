#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

static uint64_t double_to_bits(double d)
{
    uint64_t u;
    memcpy(&u, &d, sizeof(u)); // portable “bit copy”
    return u;
}

int main(void)
{
    double d = 3.14;
    uint64_t bits = double_to_bits(d);

    printf("d = %f\n", d);
    printf("bits as uint64 = 0x%016" PRIx64 "\n", bits);

    // how the 8 bytes split into two 32-bit words in memory order
    uint32_t w[2];
    memcpy(w, &d, sizeof(w));

    printf("as two uint32 words (memory order): w[0]=0x%08" PRIx32 " w[1]=0x%08" PRIx32 "\n",
           w[0], w[1]);
    uint8_t *p = (uint8_t *)&w[0];
    printf("%02x %02x %02x %02x\n", p[0], p[1], p[2], p[3]);

    return 0;
}
