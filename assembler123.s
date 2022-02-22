# I test compiled this with: gcc assembler_123.s and the a.out runs perfectly.
# So follow this general template when it comes to writing at&t assembly.

	.file	"aaa.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d, %d, %d\n"
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
	subq	$32, %rsp

	# These next 2 commands are the (int argc, char** argv) - argc should be 4bytes and argv is 8bytes = 12.
	movl	%edi, -20(%rbp)						
	movq	%rsi, -32(%rbp)

	movl	$1, -12(%rbp)
	movl	$2, -8(%rbp)
	movl	$3, -4(%rbp)
	movl	-4(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
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
