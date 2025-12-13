// // Compiling the actual function with gcc yields the following assembly code:
// short scale3(short x, short y, short z) 
// x in %rdi, y in %rsi, z in %rdx
// scale3:
//  leaq (%rsi,%rsi,9), %rbx
//  leaq (%rbx,%rdx), %rbx
//  leaq (%rbx,%rdi,%rsi), %rbx
//  ret
// Fill in the missing expression in the C code.
// ignores scale factors
short scale3(short x, short y, short z)
{
    short t = 10 * y + z + (x * y);
    return t;
}