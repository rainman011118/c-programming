#this is the assembly dump for a simple c program which declares 4 ints and performs a loop to print out i. After this it sums x and y and prints it out.

	.file	"aaa.c"

	.text
	.section	.rodata
.LC0:
	.string	"%d\n"

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
	subq	$32, %rsp							#make room for 4 ints(16b) and main(args = 2 x 8b pointers) 

	movl	%edi, -20(%rbp)						#argc and argv arguments
	movq	%rsi, -32(%rbp)						#argc and argv arguments
	movl	$5, -16(%rbp)								#initialisation of int x
	movl	$10, -12(%rbp)								#initialisation of int y
	movl	$0, -8(%rbp)								#initialisation of int i
	jmp	.L2
.L3:													#CARRY OUT LOOP BODY AND INCREMENT i
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)								#increments i
.L2:													#START OF LOOP CONDITION
	cmpl	$9, -8(%rbp)
	jle	.L3												#jump if 0 < 9#
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
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
