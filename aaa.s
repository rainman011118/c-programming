/* C code:
int main()
		char buffer[24];
		char* name = "Michael Jackson";
		strncpy(buffer, name, 24);
		printf("name is: %s\n", buffer);
		return 7;
*/

	.file	"aaa.c"
	.text
	.section	.rodata
.LC0:
	.string	"Michael Jackson"
.LC1:
	.string	"name is: %s\n"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp) // save stack canary value on stack bottom

	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, -40(%rbp) // save char pointer on stack top
	movq	-40(%rbp), %rcx // rcx now holds char pointer
	leaq	-32(%rbp), %rax // ?? This must be the buffer.... between -8 32 = 24 bytes..

	// Set up strncpy args:
	movl	$24, %edx		// SIZE of buffer value
	movq	%rcx, %rsi		// char pointer
	movq	%rax, %rdi		// buffer....?
	call	strncpy@PLT


    // Set up printf args
	leaq	-32(%rbp), %rax		// load buffer start rax > rsi
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi	// load format string
	movl	$0, %eax
	call	printf@PLT
	movl	$7, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	ret

