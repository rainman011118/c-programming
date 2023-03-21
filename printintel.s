	.file	"aaa.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"Hello World!"
.LC1:
	.string	"the sum of %d + %d = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	endbr64
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	DWORD PTR -20[rbp], edi
	mov	QWORD PTR -32[rbp], rsi

	mov	DWORD PTR -8[rbp], 10
	mov	DWORD PTR -4[rbp], 99
	lea	rdi, .LC0[rip]
	call	puts@PLT

	mov	edx, DWORD PTR -8[rbp]
	mov	eax, DWORD PTR -4[rbp]
	lea	ecx, [rdx+rax]
	mov	edx, DWORD PTR -4[rbp]
	mov	eax, DWORD PTR -8[rbp]
	mov	esi, eax
	lea	rdi, .LC1[rip]
	mov	eax, 0
	call	printf@PLT
	mov	eax, 7
	leave
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
