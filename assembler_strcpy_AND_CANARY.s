; SEE: https://www.youtube.com/watch?v=u5dpW6Nesug&list=PLyqSpQzTE6M-q0Xgn0icEHvUS7WQxvenv&index=5

; ################## Use of a stack canary ########################

	.file	"strcpy.c"



	.text
	.section	.rodata
.LC0:
	.string	"c is now: %s\n"




	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$144, %rsp






	movq	%fs:40, %rax					;this is a stack canary (compiler inserts this)
	movq	%rax, -8(%rbp)					;then stores it here...for cmp at the end..
	xorl	%eax, %eax

	movabsq	$35662932501832, %rax
	movl	$0, %edx
	movq	%rax, -144(%rbp)
	movq	%rdx, -136(%rbp)
	movl	$0, -128(%rbp)
	movabsq	$36715199885143, %rax
	movl	$0, %edx
	movq	%rax, -112(%rbp)
	movq	%rdx, -104(%rbp)
	movq	$0, -96(%rbp)
	movq	$0, -88(%rbp)
	movq	$0, -80(%rbp)
	leaq	-144(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	leaq	-112(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax

	movq	-8(%rbp), %rcx					;the canary value is now fetched
	xorq	%fs:40, %rcx					;and compared to original fs:40 value
	je	.L3
	call	__stack_chk_fail@PLT			;if canary values don't match = stack_check_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc




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
