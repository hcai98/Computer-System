// Name: Haoyang Cai
// Contact: hc2283@nyu.edu
// Purpose: to replicate the given bar function
long bar( long a, long b ) {

    // first translation attempt:
    // rdx = a
    // rax = 0
    // rcx = a*5
    // rcx = a + rcx *2
    // a = b
    // a << 4
    // rcx =  rcx + 2* b
    // rcx = rcx - a
    // rcx = rcx + 1
    // while (rdx <= b) {rdx = rdx +1; rax = rax + rcx;}
    // return rax

    // Original Code:
    // long c = a;
    // long d = 0;
    // long e = a * 11;
    // a = b*16;
    // e = e + 2*b - a + 1;
    // while(c <= b){
    //     c+=1;
    //     d += e;
    // }
    // return d;

    // Shortened code
    long d = 0; 
    long c = a;
    long e = a*11 - 14*b + 1;
    while(c <= b){
        c += 1;
        d += e;
    }
    return d;

} 

/* 
Diassembled codes
0000000000000000 bar:
       0: 48 89 fa                      movq    %rdi, %rdx
       3: b8 00 00 00 00                movl    $0, %eax
       8: 48 8d 0c bf                   leaq    (%rdi,%rdi,4), %rcx
       c: 48 8d 0c 4f                   leaq    (%rdi,%rcx,2), %rcx
      10: 48 89 f7                      movq    %rsi, %rdi
      13: 48 c1 e7 04                   shlq    $4, %rdi
      17: 48 8d 0c 71                   leaq    (%rcx,%rsi,2), %rcx
      1b: 48 29 f9                      subq    %rdi, %rcx
      1e: 48 83 c1 01                   addq    $1, %rcx
      22: eb 07                         jmp     7 <bar+0x2b>
      24: 48 83 c2 01                   addq    $1, %rdx
      28: 48 01 c8                      addq    %rcx, %rax
      2b: 48 39 f2                      cmpq    %rsi, %rdx
      2e: 7e f4                         jle     -12 <bar+0x24>
      30: f3 c3                         rep             retq
*/
