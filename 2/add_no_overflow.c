// Determine whether arguments can be added without overflow
// returns 1 if OK , 0 if Overflow occurred //
int uadd_ok(unsigned x, unsigned y) {
    unsigned sum = x + y;
    return sum >= x; 
}

