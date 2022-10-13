; hello.asm
; @author Jorma Rebane
; @date 27.10.2013
global main
extern printf
section .text
; ----------------------
main:
	; printf("Hello world!\n")
	push	hello
	call	printf
	add	esp, 4
	; return 0
	mov	eax, 0
	ret
; ----------------------
section .data
	hello db 'Hello world!', 10, 0

