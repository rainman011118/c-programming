section .text

		extern printf
		extern strncpy
		global main
main:
		push rbp
		mov rbp, rsp
		sub rsp, 48

; ***********   NOTE: the 'lea' instructions to pass the buffer address...  ********************

		lea rax, [rel name]			; load name
		mov [rbp-40], rax			; save name
		mov rcx, [rbp-40]			; name into rcx
		lea rax, [rbp-32]			; load buffer address

; strncpy args
		mov rdx, 24					; size 
		mov rsi, rcx				; name
		mov rdi, rax				; buffer
		call strncpy wrt ..plt

; printf args
		xor rax, rax
		lea rsi, [rbp-32]			; load buffer address
		lea rdi, [rel fmt]			; load format string
		xor rax, rax
		call printf wrt ..plt

; end
		mov rax, 7
		mov rsp, rbp
		pop rbp
		ret

section .data
name: db "Michael Jackson", 0			; Deffo have to NULL terminate!
fmt: db "name is: %s", 10, 0
