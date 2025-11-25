#include <stdio.h>

// swap function
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

// reverse
void reverse_array_wrong(int a[], int cnt) {
    int first, last;
    // Note: The condition first <= last contains the bug for odd arrays
    for (first = 0, last = cnt-1; first <= last; first++, last--) {
        printf("First: %d last: %d  \n", first, last);
        inplace_swap(&a[first], &a[last]);
    }
}
void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt-1; first < last; first++, last--) {
        printf("First: %d last: %d  \n", first, last);
        inplace_swap(&a[first], &a[last]);
    }
}

// print array
void print_array(int a[], int length) {
    printf("[ ");
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

int main() {
    // --- Test Case 1: Even Length (4 elements) ---
    int even_array[] = {1, 2, 3, 4};
    int even_len = 4;

    printf("Test 1 (Even Length - 4):\n");
    printf("Before: ");
    print_array(even_array, even_len);
    
    reverse_array_wrong(even_array, even_len);
    
    printf("After:  ");
    print_array(even_array, even_len);
    printf("\n");

    // --- Test Case 2: Odd Length (5 elements) ---
    // This will fail because when first and last are the same (first <= last), 
    // inplace_swap will operate on the same number.
    // and x ^ x = 0. So the middle number will always be 0 for odd arrays
    int odd_array[] = {1, 2, 3, 4, 5};
    int odd_len = 5;

    printf("Test 2 (Odd Length - 5):\n");
    printf("Before: ");
    print_array(odd_array, odd_len);

    reverse_array_wrong(odd_array, odd_len);

    printf("After:  ");
    print_array(odd_array, odd_len);

    int odd_array_2[] = {1, 2, 3, 4, 5};
    printf("Test 3 - Correct (Odd Length - 5):\n");
    printf("Before: ");
    print_array(odd_array_2, odd_len);

    reverse_array(odd_array_2, odd_len);

    printf("After:  ");
    print_array(odd_array_2, odd_len);
    
    return 0;
}

// 2.12
// A.) x & 0xFF --> 0x00000021
// B.) x ^ 0xFFF