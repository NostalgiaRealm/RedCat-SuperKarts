; 0045ca84 FUN_0045ca84
0045ca84	55	PUSH EBP
0045ca85	8bec	MOV EBP,ESP
0045ca87	83c4e0	ADD ESP,-0x20
0045ca8a	dd4508	FLD double ptr [EBP + 0x8]
0045ca8d	d835e0ca4500	FDIV float ptr [0x0045cae0]
0045ca93	dd5de8	FSTP double ptr [EBP + -0x18]
0045ca96	9b	WAIT
0045ca97	dd45e8	FLD double ptr [EBP + -0x18]
0045ca9a	d81de4ca4500	FCOMP float ptr [0x0045cae4]
0045caa0	dfe0	FNSTSW AX
0045caa2	9e	SAHF
0045caa3	7626	JBE 0x0045cacb
0045caa5	dd45e8	FLD double ptr [EBP + -0x18]
0045caa8	d835e4ca4500	FDIV float ptr [0x0045cae4]
0045caae	dd5de0	FSTP double ptr [EBP + -0x20]
0045cab1	9b	WAIT
0045cab2	dd45e0	FLD double ptr [EBP + -0x20]
0045cab5	e8e65efaff	CALL 0x004029a0
0045caba	d80de4ca4500	FMUL float ptr [0x0045cae4]
0045cac0	e8c35efaff	CALL 0x00402988
0045cac5	db7df0	FSTP extended double ptr [EBP + -0x10]
0045cac8	9b	WAIT
0045cac9	eb0c	JMP 0x0045cad7
0045cacb	dd45e8	FLD double ptr [EBP + -0x18]
0045cace	e8b55efaff	CALL 0x00402988
0045cad3	db7df0	FSTP extended double ptr [EBP + -0x10]
0045cad6	9b	WAIT
0045cad7	db6df0	FLD extended double ptr [EBP + -0x10]
0045cada	8be5	MOV ESP,EBP
0045cadc	5d	POP EBP
0045cadd	c20800	RET 0x8
