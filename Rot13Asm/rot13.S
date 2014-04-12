[BITS 64]

	section .rodata
rotLOW:	db 'nopqrstuvwxyzabcdefghijklm'
rotUP:	db 'NOPQRSTUVWXYZABCDEFGHIJKLM'

;; ------------------------
	
	section .text
	global rot13

rot13:
	push rdi
	cmp rdi, 0
	jz end
	
loop:
	cmp byte [rdi], 0
	jz end
	call need_change
	inc rdi
	jmp loop

end:
	pop rdi
	ret

;; ------------------------

need_change:
	cmp byte [rdi], 96
	jg check_change_LOW
	cmp byte [rdi], 64
	jg check_change_UP
	ret

check_change_UP:
	cmp byte [rdi], 91
	jl change_UP
	ret
	
check_change_LOW:	
	cmp byte [rdi], 123
	jl change_LOW
	ret

change_UP:
	xor rax, rax
	mov al, [rdi]
	sub rax, 65
	mov rax, [rotUP + rax]
	mov byte [rdi], al
	ret
	
change_LOW:
	xor rax, rax
	mov al, [rdi]
	sub rax, 97
	mov al, [rotLOW + rax]
	mov byte [rdi], al
	ret

