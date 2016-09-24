	.text
	.code64
	.global array
	.global interruptHandler

commonInterruptHandler:
	pushq %rax
	pushq %rcx
	pushq %rdx
	pushq %rsi
	pushq %rdi
	pushq %r8
	pushq %r9
	pushq %r10
	pushq %r11
	
	movq 72(%rsp), %rdi
	
	call interruptHandler
	
	popq %r11
	popq %r10
	popq %r9
	popq %r8
	popq %rdi
	popq %rsi
	popq %rdx
	popq %rcx
	popq %rax
	
	addq $16, %rsp
	
	iretq

#define buildHandler(n) \
interruptHandler ## n: \
	pushq $0; \
	pushq $n; \
	jmp commonInterruptHandler

#define buildHandlerWithoutErrorCode(n) \
interruptHandler ## n: \
	pushq $n; \
	jmp commonInterruptHandler


buildHandler(0)
buildHandler(1)
buildHandler(2)
buildHandler(3)
buildHandler(4)
buildHandler(5)
buildHandler(6)
buildHandler(7)
buildHandlerWithoutErrorCode(8)
buildHandler(9)
buildHandlerWithoutErrorCode(10)
buildHandlerWithoutErrorCode(11)
buildHandlerWithoutErrorCode(12)
buildHandlerWithoutErrorCode(13)
buildHandlerWithoutErrorCode(14)
buildHandler(15)
buildHandler(16)
buildHandlerWithoutErrorCode(17)
buildHandler(18)
buildHandler(19)
buildHandler(20)
buildHandler(21)
buildHandler(22)
buildHandler(23)
buildHandler(24)
buildHandler(25)
buildHandler(26)
buildHandler(27)
buildHandler(28)
buildHandler(29)
buildHandler(30)
buildHandler(31)
buildHandler(32)
buildHandler(33)
buildHandler(34)
buildHandler(35)
buildHandler(36)
buildHandler(37)
buildHandler(38)
buildHandler(39)
buildHandler(40)
buildHandler(41)
buildHandler(42)
buildHandler(43)
buildHandler(44)
buildHandler(45)
buildHandler(46)
buildHandler(47)

array:
	.quad interruptHandler0
	.quad interruptHandler1
	.quad interruptHandler2
	.quad interruptHandler3
	.quad interruptHandler4
	.quad interruptHandler5
	.quad interruptHandler6
	.quad interruptHandler7
	.quad interruptHandler8
	.quad interruptHandler9
	.quad interruptHandler10
	.quad interruptHandler11
	.quad interruptHandler12
	.quad interruptHandler13
	.quad interruptHandler14
	.quad interruptHandler15
	.quad interruptHandler16
	.quad interruptHandler17
	.quad interruptHandler18
	.quad interruptHandler19
	.quad interruptHandler20
	.quad interruptHandler21
	.quad interruptHandler22
	.quad interruptHandler23
	.quad interruptHandler24
	.quad interruptHandler25
	.quad interruptHandler26
	.quad interruptHandler27
	.quad interruptHandler28
	.quad interruptHandler29
	.quad interruptHandler30
	.quad interruptHandler31
	.quad interruptHandler32
	.quad interruptHandler33
	.quad interruptHandler34
	.quad interruptHandler35
	.quad interruptHandler36
	.quad interruptHandler37
	.quad interruptHandler38
	.quad interruptHandler39
	.quad interruptHandler40
	.quad interruptHandler41
	.quad interruptHandler42
	.quad interruptHandler43
	.quad interruptHandler44
	.quad interruptHandler45
	.quad interruptHandler46
	.quad interruptHandler47






