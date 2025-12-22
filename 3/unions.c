#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef enum { IS_INT, IS_DOUBLE } kind_t;

typedef struct {
    kind_t kind;  // the tag
    union {
        int i;
        double d;
    } u;          // shared storage
} Value;

static void dump_bytes(const void *p, size_t n) {
    const unsigned char *b = (const unsigned char*)p;
    for (size_t i = 0; i < n; i++) printf("%02x ", b[i]);
    printf("\n");
}

int main(void) {
    Value v;

    printf("Memory Layout\n");
    printf("Address of v.u (Union start): %p\n", (void*)&v.u);
    printf("Address of v.u.i            : %p\n", (void*)&v.u.i);
    printf("Address of v.u.d            : %p\n", (void*)&v.u.d);
    printf("\n\n");

    v.kind = IS_INT;
    v.u.i = 42;
    printf("Stored int 42\n");
    printf("  tag=%d, u.i=%d\n", v.kind, v.u.i);
    printf("  raw bytes: ");
    dump_bytes(&v.u, sizeof(v.u));

    v.kind = IS_DOUBLE;
    v.u.d = 3.14;
    printf("\nStored double 3.14 (overwrites same bytes)\n");
    printf("  tag=%d, u.d=%f\n", v.kind, v.u.d);
    printf("  reading u.i now gives garbage: u.i=%d\n", v.u.i);
    printf("  raw bytes: ");
    dump_bytes(&v.u, sizeof(v.u));

    // Correct usage pattern: check tag before reading
    printf("\nSafe read using tag:\n");
    if (v.kind == IS_INT) printf("  int=%d\n", v.u.i);
    else                 printf("  double=%f\n", v.u.d);

    return 0;
}