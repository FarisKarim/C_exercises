long rfact(long n)
{
    long result;
    if (n <= 1)
        result = 1;
    else
        result = n * rfact(n - 1);
    return result;
}
// (Generated assembly code
// long rfact(long n)
// n in %rdi

// 1 rfact:
// 2    pushq %rbx                  Save %rbx
// 3    movq %rdi, %rbx             Store n in callee-saved register (so when rfact called again, n from current level is saved)
// 4    movl $1, %eax               Set return value = 1
// 5    cmpq $1, %rdi               Compare n:1 (base case)
// 6    jle .L35                    If <=, goto done
// 7    leaq -1(%rdi), %rdi         Compute n-1 (store in argument 1 register)
// 8    call rfact                  Call rfact(n-1)
// 9    imulq %rbx, %rax            Multiply result by n
// 10 .L35:                         done
// 11   popq %rbx                   Restore %rbx (for previous level to multiply by %rax (return value) for this level)
// 12   ret Return