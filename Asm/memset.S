[BITS 64]
	
;; ------ !MEMSET

	global memset:function

memset:
	push rdi		; use the stack to save the first adress
	cmp rdx, 0		; rdx = nbe de caractères
	jle end
	
loop:
	mov [rdi], sil 		; last right byte of rsi
	inc rdi
	dec rdx
	cmp rdx, 0
	je end
	jmp loop

end:
	pop rax			; get back the first adress saved on the stack
	ret

;; ------ !MEMSET


