section .bss
        x resq 1
	y resq 1
	ak resq 1
	bk resq 1
section .data
	a: dq 0
	b: dq 4
	contor: dq 10
	fmt1: db "x curent este:%d", 0   
	fmt2: db "a curent este:%d", 0  
	fmt3: db "b curent este:%d", 0  

section .text
	extern printf
	extern exit
	global main

main:
	push rbp
	mov rbp, rsp
	
	mov rdx, 0
	mov rax, [a]
	add rax, [b]
	mov rbx, 2
	idiv rbx
	mov [x], rax
	 	 

	jloop:
	mov rdX, 0
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
	xor rax, rax
	mov rax, 0
	mov rdi, fmt1
	mov rsi, [x]
	call printf
	mov rcx, contor
	sub rcx, 1
	mov [contor], rcx
	
	
	cmp rbx, 0
	je exit
	
	cmp rcx, 0
	je exit
	xor rcx, rcx
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	xor rax, rax
	mov rax, 0
	sub rax, 6
	mov [ak], rax
	xor rax, rax
	mov rax, [a]
	mov rbx, 5
	imul rbx
	add [a], rax
	xor rax, rax
	xor rbx, rbx
	
	mov rax, [a]
	mov rbx, [a]
	imul rbx
	add [ak], rax
	xor rax, rax
	xor rbx, rbx	
	 
	mov rax, 0
	mov rdi, fmt2
	mov rsi, [ak]
	call printf
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	xor rax, rax
	mov rax, 0
	sub rax, 6
	mov [bk], rax
	xor rax, rax
	mov rax, [b]
	mov rbx, 5
	imul rbx
	add [b], rax
	xor rax, rax
	xor rbx, rbx
	
	mov rax, [b]
	mov rbx, [b]
	imul rbx
	add [bk], rax
	xor rax, rax
	xor rbx, rbx	
	 
	mov rax, 0
	mov rdi, fmt3
	mov rsi, [bk]
	call printf
;;;;;;;;;;;;;;;;;;;;;;;;;;;
	xor rax, rax
	xor rbx, rbx
	mov rax, [x]
	mov rbx, [ak]
	imul rbx
	cmp rax, 0
	jl prima_ramura
	jmp doua_ramura	
	 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	prima_ramura:
	xor rax, rax
	mov rax, [ak]
	mov [a], rax
	xor rax, rax
	mov rax, [x]
	mov [b], rax
	xor rax, rax
	xor rbx, rbx
	mov rdx, 0
	mov rax, [a]
	add rax, [b]
	mov rbx, 2
	idiv rbx
	mov [x], rax
	jmp jloop
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    	doua_ramura:
	xor rax, rax
	xor rbx, rbx
	mov rax, [bk]
	mov [b], rax
	xor rax, rax
	mov rax, [x]
	mov [a], rax
	xor rax, rax
	xor rbx, rbx
	mov rdx, 0
	mov rax, [a]
	add rax, [b]
	mov rbx, 2
	idiv rbx
	mov [x], rax
	xor rbx, rbx
	jmp jloop	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 	exit:
	mov rsp, rbp
	pop rbp
     call exit
 
 