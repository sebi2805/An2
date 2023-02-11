section .bss
x resw 1
SECTION .data
fmt:    db "%d",10, 0

SECTION .text
        extern printf
	extern exit
        global main

main:
push rbp
mov rbp, rsp
	mov edx, 0
 	mov eax, 2
	mov ebx,  2
	div ebx
	mov [x], eax
	 
	mov rsi, qword[x]
	mov rax, 0
	mov rdi, fmt
	call printf
	 
	syscall
mov rsp, rbp
pop rbp 
call exit
