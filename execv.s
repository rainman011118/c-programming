// Simple c program to spawn a shell "/bin/sh" using execv

	.file	"execv.c"				

	.text
	.section	.rodata
.LC0:
	.string	"/bin/sh"				# Tested with 2 slashes also, assembly code was identical


	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp

		// Has to make room for char* binaryPath[] = "/bin/sh" = 8
		// And char* args[] = {binaryPath, NULL} = 16

	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax

	// char* binaryPath = "//bin/sh";

	leaq	.LC0(%rip), %rax				//store '/bin/sh' (binaryPath) on stack
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	
	movq	%rax, -32(%rbp)					//store '/bin/sh' (as the first arg in args to execve)
	movq	$0, -24(%rbp)					//store 'NULL' (as the 2nd arg in args to execve)

	// execv(binaryPath, args);

	leaq	-32(%rbp), %rdx					//load '/bin/sh' into rdx for later move into rsi
	movq	-40(%rbp), %rax					//load '/bin/sh' into rax for later move into rdi
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	execv@PLT

	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	ret
