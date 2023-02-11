section .bss
        x resq 1
	y resq 1
	ak resq 1
	bk resq 1
	ak1 resq 1
	bk1 resq 1
section .data
	a: dq -5
	b: dq 1000
	contor: dq 15
	fmt1: db "x curent este:%d",10, 0  
	fmt4: db "f(x) curent este:%d",10, 0  
	fmt2: db "a curent este:%d",10, 0  
	fmt3: db "b curent este:%d",10, 10, 0  

section .text
	extern printf
	extern exit
	global main

main:
	push rbp
	mov rbp, rsp
 
 
	mov rdx, 00
	mov rax, [a]
	mov [ak], rax
	mov rbx, [b]
	mov [bk], rbx
	xor rbx, rbx
	add rax, [b]
	mov rbx, 2
	idiv rbx
	mov [x], rax

	jloop:
	mov rax, [contor]
	dec rax
	cmp rax, 0
	je exit
	mov [contor], rax
	xor rax, rax 
	
	mov rax, 0
	mov rdi, fmt1
	mov rsi, [x]
	call printf
	xor rax, rax
	mov rax, 00
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
 	xor rbx, rbx
	
	mov rax, 0
	mov rdi, fmt4
	mov rsi, [y]
	call printf
	
	xor eax, eax
	xor ax, ax
	xor al, al
	xor ah, ah
	xor rax, rax
	mov rax, [y]
	 
	sub al,  0
	je exit
	 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	xor rax, rax
	mov rax, 0
	sub rax, 6
	mov [ak1], rax
	xor rax, rax
	mov rax, [ak]
	mov rbx, 5
	imul rbx
	add [ak1], rax
	xor rax, rax
	xor rbx, rbx
	
	mov rax, [ak]
	mov rbx, [ak]
	imul rbx
	add [ak1], rax
	xor rax, rax
		
	 
	mov rax, 0
	mov rdi, fmt2
	mov rsi, [ak]
	call printf
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 
		
	 
	mov rax, 0
	mov rdi, fmt3
	mov rsi, [bk]
	call printf
;;;;;;;;;;;;;;;;;;;;;;;;;;;
	xor rax, rax
	xor rbx, rbx
	mov rax, [y]
	mov rbx, [ak1]
	imul rbx
	cmp rax, 0
	jle prima_ramura
	jmp doua_ramura	
	 	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	prima_ramura:
	mov rdx, 0
	xor rax, rax
	 
	 
 
	mov rax, [x]
	mov [bk], rax
	xor rax, rax
	mov rax, [ak]
	add rax, [bk]
	mov rbx, 2
	add rax, 1
	idiv rbx
	 
	mov [x], rax
	jmp jloop
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    	doua_ramura:
	mov rdx, 0
	xor rax, rax
	 
	 
	 
	mov rax, [x]
	mov [ak], rax
	xor rax, rax
	mov rax, [ak]
	add rax, [bk]
	add rax, 1
	mov rbx, 2
	idiv rbx
	
	mov [x], rax
	jmp jloop	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 	exit:
	xor rax, rax
	xor rbx, rbx
	mov rsp, rbp
	pop rbp
     ret