#include <stdio.h>

// The Buggy Function
float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;
    printf("  length is: %u\n", length);
    printf("  length - 1 calculates to: %u\n", length - 1);
    printf("\n");

    // (Will run forever until crash)
    for (i = 0; i <= length-1; i++) {
        // printf("Accessing array at index [%d]\n", i);
        result += a[i];
    }
    return result;
}

int main() {
    float my_array[] = {1.0};
    printf("Starting test with length = 0...\n");
    sum_elements(my_array, 0);
    
    printf("Worked\n");
    return 0;
}