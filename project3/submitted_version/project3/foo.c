// Name: Haoyang Cai
// Contact: hc2283@nyu.edu
// Purpose: to replicate the given foo function

long foo ( long a, long b ) {
    // shorten version of the code
    return 188*b - 43*a;

    // // Original Version
    // // rax = a + 2 * a
    // long c = 3 * a;
    // // rax = a + 4 * rax
    // c = a + 4 * c;
    // // rax << 2
    // c = c*4;
    // // rcx = b + 2 * b
    // long d = 3 * b;
    // // rdx = rcx
    // long e = d; 
    // // rdx << 5 (rdx = rdx * 32)
    // e = e*32;
    // // rdx = rdx - rcx
    // e = e - d;
    // // rax = rax + rdx
    // c = c + e;
    // // b = b - a
    // b = b - a;
    // // rdx = 3*b
    // e = 3*b;
    // // rdx << 5 (rdx = rdx * 32)
    // e = e*32
    // // rdx = rdx - b
    // e = e - b
    // // rax = rax + rdx
    // c  = c + e;
}


/*
Disassembled codes for foo()
   0x0000000000400594 <+0>:	lea    (%rdi,%rdi,2),%rax
   0x0000000000400598 <+4>:	lea    (%rdi,%rax,4),%rax
   0x000000000040059c <+8>:	shl    $0x2,%rax
   0x00000000004005a0 <+12>:	lea    (%rsi,%rsi,2),%rcx
   0x00000000004005a4 <+16>:	mov    %rcx,%rdx
   0x00000000004005a7 <+19>:	shl    $0x5,%rdx
   0x00000000004005ab <+23>:	sub    %rcx,%rdx
   0x00000000004005ae <+26>:	add    %rdx,%rax
   0x00000000004005b1 <+29>:	sub    %rdi,%rsi
   0x00000000004005b4 <+32>:	lea    (%rsi,%rsi,2),%rdx
   0x00000000004005b8 <+36>:	shl    $0x5,%rdx
   0x00000000004005bc <+40>:	sub    %rsi,%rdx
   0x00000000004005bf <+43>:	add    %rdx,%rax
   0x00000000004005c2 <+46>:	retq
*/