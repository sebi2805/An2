section .bss
 
y resq 1
section .data
	 
	fmt: db "%d",10, 0   
	x: dq 2
section .text
	extern printf
	extern exit
	global main

main:
	push rbp
	 mov rbp, rsp
	mov edx, 0
	mov ebx, 4
	mov edx, 0
	xor rax, rax
	mov rax, 0
	sub rax, 6
	mov [y], rax
	xor rax, rax
	mov rax, [x]
	mov rbx, 5
	imul rbx
	add [y], rax
	xor rax, rax
	xor rbx, rbx
	
	mov rax, [x]
	mov rbx, [x]
	imul rbx
	add [y], rax
	xor rax, rax
	mov rax, [y]
	mov [x], rax
	mov rbx, [x]
	mov rax, 0
	mov rdi, fmt
	mov rsi, [x]
	call printf
	mov rsp, rbp
	pop rbp
     call exit
 
	                
	 