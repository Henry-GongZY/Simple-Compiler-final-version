.section .rodata
STRING0:
	.string "test:%d %d %d\n"

	.bss
_a:
	.zero 4
	.align 4
_b:
	.zero 4
	.align 4
_c:
	.zero 4
	.align 4

	.text
	.globl main
	.type main, @function
main:
	movl $3,_c
	movl $3,_b
	movl $3,_a
	pushl _a
	pushl _b
	pushl _c
	pushl $STRING0
	call printf
	addl $16,%esp
	movl $0,%eax
	ret
