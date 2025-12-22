#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

struct Original {
    int *a;    // 8
    float b;   // 4
    char c;    // 1
    short d;   // 2
    long e;    // 8
    double f;  // 8
    int g;     // 4
    char *h;   // 8
};

struct Reordered {
    int *a;    // 8
    char *h;   // 8
    long e;    // 8
    double f;  // 8
    float b;   // 4
    int g;     // 4
    short d;   // 2
    char c;    // 1
};

static void print_layout_original(void) {
    printf("Original sizeof=%zu\n", sizeof(struct Original));
    printf("  a: %2zu\n", offsetof(struct Original, a));
    printf("  b: %2zu\n", offsetof(struct Original, b));
    printf("  c: %2zu\n", offsetof(struct Original, c));
    printf("  d: %2zu\n", offsetof(struct Original, d));
    printf("  e: %2zu\n", offsetof(struct Original, e));
    printf("  f: %2zu\n", offsetof(struct Original, f));
    printf("  g: %2zu\n", offsetof(struct Original, g));
    printf("  h: %2zu\n", offsetof(struct Original, h));
}

static void print_layout_reordered(void) {
    printf("Reordered sizeof=%zu\n", sizeof(struct Reordered));
    printf("  a: %2zu\n", offsetof(struct Reordered, a));
    printf("  h: %2zu\n", offsetof(struct Reordered, h));
    printf("  e: %2zu\n", offsetof(struct Reordered, e));
    printf("  f: %2zu\n", offsetof(struct Reordered, f));
    printf("  b: %2zu\n", offsetof(struct Reordered, b));
    printf("  g: %2zu\n", offsetof(struct Reordered, g));
    printf("  d: %2zu\n", offsetof(struct Reordered, d));
    printf("  c: %2zu\n", offsetof(struct Reordered, c));
}

int main(void) {
    print_layout_original();
    puts("");
    print_layout_reordered();
    return 0;
}
