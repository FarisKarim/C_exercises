#include <stdio.h>
#include <stdint.h>

int main(void) {
    char buf[64];

    char *p = buf;                 // p is an 8-byte pointer (address)
    printf("sizeof(char*) = %zu\n", sizeof(char*));
    printf("sizeof(int*)  = %zu\n", sizeof(int*));
    printf("sizeof(void*) = %zu\n", sizeof(void*));
    printf("sizeof(p)     = %zu\n\n", sizeof(p));

    // Address values (pointer arithmetic depends on pointer type)
    printf("base p                = %p\n", (void*)p);
    printf("p + 7 (char*)         = %p  (adds 7 bytes)\n", (void*)(p + 7));

    // Cast has higher precedence than +
    printf("(int*)p + 7           = %p  (adds 7 * 4 = 28 bytes)\n", (void*)(((int*)p) + 7));
    printf("(int*)(p + 7)         = %p  (adds 7 bytes, then casts)\n\n", (void*)((int*)(p + 7)));

    buf[0] = 0x11;
    buf[1] = 0x22;
    buf[2] = 0x33;
    buf[3] = 0x44;

    unsigned char c = *(unsigned char*)p;   // reads 1 byte
    int x = *(int*)p;                       // reads 4 bytes (same address)
    printf("*p as unsigned char = 0x%02x\n", c);
    printf("*p as int           = 0x%x\n", x);

    return 0;
}
