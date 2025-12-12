// INFO:
// void decode1(long *xp, long *yp, long *zp)
// xp in %rdi, yp in %rsi, zp in %rdx
// ASSEMBLY:
// decode1:
// movq (%rdi), %r8
// movq (%rsi), %rcx
// movq (%rdx), %rax
// movq %r8, (%rsi)
// movq %rcx, (%rdx)
// movq %rax, (%rdi)
// ret
// TASK: Write C code that is equivalent to the assembly instructions
void decode1(long *xp, long *yp, long *zp) {
    long a = *xp;
    long b = *yp;
    long c = *zp;
    // move a (val in mem address stored in xp) into val at mem address stored in yp
    *yp = a;
    // move b (val in memory address stored in old yp) into memory address zp
    *zp = b;
    // move c(val in memory address stored in old zp) into memory address xp
    *xp = c;
}