				;Name: Tho Nguyen
				;Email ID: tnn7yc
				;File name: mathlib.s
				;Date: 11/5/18

	global product
	global power

	section .text

product:
	xor 	rax, rax	; zero out the return register
	xor 	r10, r10	; zero out the counter i

loop:
	cmp 	r10, rsi	; does i < y
	jge	done
	add	rax, rdi	; rax = rax + x
	inc	r10		; i++
	jmp 	loop

power:
	cmp	rsi, 0		; y == 0?
	je 	ret1		; return 1
	dec	rsi		; y -= 1
	call	power
	mov	rsi, rax
	call 	product
	mov	rsi, rax
	jmp	done
	
ret1:
	mov 	rax, 1
	ret
	
done:
	ret
	

