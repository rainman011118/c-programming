	.file	"getchar.c"
	#####################################################
	.text
	.section	.rodata
.LC0:
	.string	"Big %c\n"
.LC1:
	.string	"Little %c\n"
.LC2:
	.string	"Anaconda begins with %c\n"
.LC3:
	.string	"Enter a name of something: "
	#########################################################
	.text
	.globl	main
	.type	main, @function

main:
// declare and define int ch and first 3 printf statements
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
		// This must be both int ch and int c!! and 'q' means 2 x 8bytes(64bit) = $16
	subq	$16, %rsp
	
		//push 'a' onto stack, cp it to eax, cp it to edi:
	movl	$97, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %edi

		//converts value in eax 'a' to 'A'
	call	toupper@PLT

		//move NEW 'A' into esi, load format string0, SYS_READ into eax, call printf	
	movl	%eax, %esi								
	leaq	.LC0(%rip), %rdi						
	movl	$0, %eax							
	call	printf@PLT

		//move 'a' into eax again, cp it to esi, call tolower()
	movl	-8(%rbp), %eax					
	movl	%eax, %edi
	call	tolower@PLT

		//move 'a' into esi, load format string1, SYS_READ into eax, call printf
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT

		//move 'a' into eax, cp it to esi, load format string2, SYS_READ into eax, call printf.
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT

		// NOTE: Everytime after any call, the value in eax changed....??????
	
		// declare int c(uninitialised)...but where is this....
		// load format string3 ready for user input, call puts
	leaq	.LC3(%rip), %rdi
	call	puts@PLT

.L2:

		// user input: abc\n
	call	getchar@PLT	

		// save 'a' on stack, cp it to eax, cp it to edi.
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi

		// convert 'a' to 'A' inside eax. Save 'A' on stack, cp to eax, cp to rdi.
	call	toupper@PLT
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi

		// print contents of rdi to screen. (rdi changes after this, eax stays the same)
	call	putchar@PLT

		// compare saved value 'A' to '\n'. Jump back to start .L2 if not equal.
	cmpl	$10, -4(%rbp)
	jne	.L2

		// move 0 into eax (for return 0), leave = epilogue
	movl	$0, %eax
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
