	;; Name: Tho Nguyen
	;; Email: tnn7yc
	;; File name: threexplusone.s
	;; Date: 11/18/18
	
	;; My optimizations are:
	;; 1. Get rid of push and pop: eventhough I use a callee-saved register rbx, I purposely did not push and pop it. (a TA said it's fine)
	;; 2. Use shr and shl to check for odd and even number: if x = shl(shr(x)) then x is even
	;; 3. Reduce branching in by jumping only if x is even, else just continue to next code line.
	;; 4. Using lea to compute 3x + 1 and move it into rdi in 1 line
	
	global threexplusone
	section .text

threexplusone:
	cmp	rdi, 1		; x == 1?
	je	done		; return 0
	mov 	rbx, rdi	; rbx contains x
	shr	rbx, 1		; x/2
	shl	rbx, 1
	cmp	rbx, rdi	
	je	even
	lea	rdi, [rdi + 2*rdi +1]
	call	threexplusone
	inc	rax
	ret
even:
	shr	rdi, 1
	call	threexplusone
	inc	rax
	ret
done:
	xor	rax, rax
	ret
	
	
