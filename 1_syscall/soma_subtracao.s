.file	"soma_subtracao.c"
.text
.section	.rodata
.LC0:
.string	"%d"
.LC1:
.string	"%d %d"
.align 8
.LC2:
.string	"O valor da soma \303\251 igual a: %d\n"
.align 8
.LC3:
.string	"O valor da subtra\303\247\303\243o \303\251 igual a: %d\n"
.text
.globl	main
.type	main, @function
main:
.LFB6:
.cfi_startproc
endbr64
pushq	%rbp
.cfi_def_cfa_offset 16
.cfi_offset 6, -16
movq	%rsp, %rbp
.cfi_def_cfa_register 6
subq	$224, %rsp
movq	%fs:40, %rax
movq	%rax, -8(%rbp)
xorl	%eax, %eax
movabsq	$3539940857772206404, %rax
movabsq	$8030798163434631200, %rdx
movq	%rax, -192(%rbp)
movq	%rdx, -184(%rbp)
movabsq	$8079512846219633005, %rax
movabsq	$8386394593442230881, %rdx
movq	%rax, -176(%rbp)
movq	%rdx, -168(%rbp)
movabsq	$751999723522711922, %rax
movq	%rax, -160(%rbp)
movb	$0, -152(%rbp)
leaq	-192(%rbp), %rax
movl	$40, %edx
movq	%rax, %rsi
movl	$1, %edi
call	write@PLT
leaq	-202(%rbp), %rax
movl	$10, %edx
movq	%rax, %rsi
movl	$0, %edi
call	read@PLT
movl	%eax, -212(%rbp)
cmpl	$0, -212(%rbp)
jg	.L2
movl	$1, %eax
jmp	.L12
.L2:
movl	-212(%rbp), %eax
subl	$1, %eax
cltq
movb	$0, -202(%rbp,%rax)
leaq	-224(%rbp), %rdx
leaq	-202(%rbp), %rax
leaq	.LC0(%rip), %rcx
movq	%rcx, %rsi
movq	%rax, %rdi
movl	$0, %eax
call	__isoc99_sscanf@PLT
jmp	.L4
.L7:
movabsq	$2337212511586796366, %rax
movabsq	$7235433718372265577, %rdx
movq	%rax, -80(%rbp)
movq	%rdx, -72(%rbp)
movabsq	$8388349483303316591, %rax
movabsq	$7021781903228346469, %rdx
movq	%rax, -64(%rbp)
movq	%rdx, -56(%rbp)
movabsq	$2334307584681407264, %rax
movabsq	$8295737657505357874, %rdx
movq	%rax, -48(%rbp)
movq	%rdx, -40(%rbp)
movabsq	$-4348292091903450507, %rax
movq	%rax, -32(%rbp)
movl	$171601827, -24(%rbp)
movb	$0, -20(%rbp)
leaq	-80(%rbp), %rax
movl	$60, %edx
movq	%rax, %rsi
movl	$1, %edi
call	write@PLT
leaq	-202(%rbp), %rax
movl	$10, %edx
movq	%rax, %rsi
movl	$0, %edi
call	read@PLT
movl	%eax, -212(%rbp)
cmpl	$0, -212(%rbp)
jg	.L5
movl	$1, %eax
jmp	.L12
.L5:
movl	-212(%rbp), %eax
subl	$1, %eax
cltq
movb	$0, -202(%rbp,%rax)
leaq	-224(%rbp), %rdx
leaq	-202(%rbp), %rax
leaq	.LC0(%rip), %rcx
movq	%rcx, %rsi
movq	%rax, %rdi
movl	$0, %eax
call	__isoc99_sscanf@PLT
.L4:
movl	-224(%rbp), %eax
cmpl	$1, %eax
je	.L6
movl	-224(%rbp), %eax
cmpl	$2, %eax
jne	.L7
.L6:
movl	-224(%rbp), %eax
cmpl	$1, %eax
jne	.L8
movabsq	$8007511688123738436, %rax
movabsq	$8243115341881679987, %rdx
movq	%rax, -80(%rbp)
movq	%rdx, -72(%rbp)
movabsq	$8243121275877225327, %rax
movabsq	$7233182801974029669, %rdx
movq	%rax, -64(%rbp)
movq	%rdx, -56(%rbp)
movabsq	$7021223364339463023, %rax
movabsq	$8029953815763771762, %rdx
movq	%rax, -48(%rbp)
movq	%rdx, -40(%rbp)
movabsq	$-6358131113316769678, %rax
movq	%rax, -32(%rbp)
movl	$171583855, -24(%rbp)
movb	$0, -20(%rbp)
leaq	-80(%rbp), %rax
movl	$60, %edx
movq	%rax, %rsi
movl	$1, %edi
call	write@PLT
leaq	-202(%rbp), %rax
movl	$10, %edx
movq	%rax, %rsi
movl	$0, %edi
call	read@PLT
movl	%eax, -212(%rbp)
cmpl	$0, -212(%rbp)
jg	.L9
movl	$1, %eax
jmp	.L12
.L9:
movl	-212(%rbp), %eax
subl	$1, %eax
cltq
movb	$0, -202(%rbp,%rax)
leaq	-216(%rbp), %rcx
leaq	-220(%rbp), %rdx
leaq	-202(%rbp), %rax
leaq	.LC1(%rip), %rsi
movq	%rax, %rdi
movl	$0, %eax
call	__isoc99_sscanf@PLT
movl	-220(%rbp), %edx
movl	-216(%rbp), %eax
addl	%edx, %eax
movl	%eax, -208(%rbp)
movl	-208(%rbp), %edx
leaq	-144(%rbp), %rax
movl	%edx, %ecx
leaq	.LC2(%rip), %rdx
movl	$50, %esi
movq	%rax, %rdi
movl	$0, %eax
call	snprintf@PLT
leaq	-144(%rbp), %rax
movq	%rax, %rdi
call	strlen@PLT
movq	%rax, %rdx
leaq	-144(%rbp), %rax
movq	%rax, %rsi
movl	$1, %edi
call	write@PLT
jmp	.L10
.L8:
movabsq	$8007511688123738436, %rax
movabsq	$8243115341881679987, %rdx
movq	%rax, -80(%rbp)
movq	%rdx, -72(%rbp)
movabsq	$8243121275877225327, %rax
movabsq	$8247325074204421477, %rdx
movq	%rax, -64(%rbp)
movq	%rdx, -56(%rbp)
movabsq	$2891366432143337825, %rax
movabsq	$8026647579769988467, %rdx
movq	%rax, -48(%rbp)
movq	%rdx, -40(%rbp)
movabsq	$8315087962877468787, %rax
movabsq	$736947048561205616, %rdx
movq	%rax, -32(%rbp)
movq	%rdx, -24(%rbp)
movb	$0, -16(%rbp)
leaq	-80(%rbp), %rax
movl	$64, %edx
movq	%rax, %rsi
movl	$1, %edi
call	write@PLT
leaq	-202(%rbp), %rax
movl	$10, %edx
movq	%rax, %rsi
movl	$0, %edi
call	read@PLT
movl	%eax, -212(%rbp)
cmpl	$0, -212(%rbp)
jg	.L11
movl	$1, %eax
jmp	.L12
.L11:
movl	-212(%rbp), %eax
subl	$1, %eax
cltq
movb	$0, -202(%rbp,%rax)
leaq	-216(%rbp), %rcx
leaq	-220(%rbp), %rdx
leaq	-202(%rbp), %rax
leaq	.LC1(%rip), %rsi
movq	%rax, %rdi
movl	$0, %eax
call	__isoc99_sscanf@PLT
movl	-220(%rbp), %eax
movl	-216(%rbp), %edx
subl	%edx, %eax
movl	%eax, -208(%rbp)
movl	-208(%rbp), %edx
leaq	-144(%rbp), %rax
movl	%edx, %ecx
leaq	.LC3(%rip), %rdx
movl	$50, %esi
movq	%rax, %rdi
movl	$0, %eax
call	snprintf@PLT
leaq	-144(%rbp), %rax
movq	%rax, %rdi
call	strlen@PLT
movq	%rax, %rdx
leaq	-144(%rbp), %rax
movq	%rax, %rsi
movl	$1, %edi
call	write@PLT
.L10:
movl	$0, %edi
call	exit@PLT
.L12:
movq	-8(%rbp), %rdx
subq	%fs:40, %rdx
je	.L13
call	__stack_chk_fail@PLT
.L13:
leave
.cfi_def_cfa 7, 8
ret
.cfi_endproc
.LFE6:
.size	main, .-main
.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
.section	.note.GNU-stack,"",@progbits
.section	.note.gnu.property,"a"
.align 8
.long	1f - 0f
.long	4f - 1f
.long	5
0:
.string	"GNU"
1:
.align 8
.long	0xc0000002
.long	3f - 2f
2:
.long	0x3
3:
.align 8
4: