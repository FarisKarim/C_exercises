#include <stdio.h>
#include <string.h>

/* * THE BUGGY FUNCTION
The Logic Error:
 * strlen() returns 'size_t' (unsigned). UNSIGNED overflow is defined behavior (wrap around) unlike signed overflow
//  
 * problem arises when subtracting a bigger # from smaller #
 */
int strlonger(char *s, char *t) {
    return strlen(s) - strlen(t) > 0;
}

int main() {
    char *s = "hi";
    char *t = "hello";
    
    int result = strlonger(s, t);
    
    if (result == 1) {
        printf("Result: TRUE (1)\n");
    } else {
        printf("Result: FALSE (0)\n");
    }

    // cast to size_t to show you exactly what computer saw.
    size_t diff = strlen(s) - strlen(t);
    printf("The computer calculated (2 - 5) as unsigned:\n");
    printf("Value: %zu (This is why it is > 0)\n", diff);

    return 0;
}