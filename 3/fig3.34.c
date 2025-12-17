long P(long x, long y)
{
    long u = Q(y);
    long v = Q(x);
    return u + v;
}

// x in %rdi, y in %rsi
// 1 P:
// 2    pushq %rbp              Save %rbp (callee saved, P saves registers from function calling P)
// 3    pushq %rbx              Save %rbx (callee saved)
// 4    subq $8, %rsp           Align stack frame
// 5    movq %rdi, %rbp         Save x (callee saved register rbp, Q must preserve its val upon return)
// 6    movq %rsi, %rdi         Move y to first argument (%rdi first arg register)
// 7    call Q                  Call Q(y)
// 8    movq %rax, %rbx         Save result (return val from Q in $rax) rbx --> (callee saved, Q must preserve its val upon return)
// 9    movq %rbp, %rdi         Move x to first argument
// 10   call Q                  Call Q(x)
// 11   addq %rbx, %rax         Add saved Q(y) to Q(x)
// 12   addq $8, %rsp           Deallocate last part of stack
// 13   popq %rbx               Restore %rbx (read address %rsp is pointing to, copy val into %rbx, increment %rsp by 8)
// 14   popq %rbp               Restore %rbp
// 15   ret