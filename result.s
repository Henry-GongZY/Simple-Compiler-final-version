.section .rodata
STRING0:
	.string "%d\n"

	.bss
_a:
	.zero 4
	.align 4
_b:
	.zero 4
	.align 4

	.text
	.globl main
	.type main, @function
main:
	movl $10,_a
	movl $1,_b
	movl _a,%eax
	movl $0,%edx
	movl _b,%ebx
	idiv %ebx
	movl %eax,_a
	pushl _a
	pushl $STRING0
	call printf
	addl $8,%esp
