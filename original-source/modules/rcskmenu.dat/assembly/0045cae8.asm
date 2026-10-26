; 0045cae8 FUN_0045cae8
0045cae8	55	PUSH EBP
0045cae9	8bec	MOV EBP,ESP
0045caeb	83c4e8	ADD ESP,-0x18
0045caee	33c0	XOR EAX,EAX
0045caf0	8945f0	MOV dword ptr [EBP + -0x10],EAX
0045caf3	8945f4	MOV dword ptr [EBP + -0xc],EAX
0045caf6	668945f8	MOV word ptr [EBP + -0x8],AX
0045cafa	dd4508	FLD double ptr [EBP + 0x8]
0045cafd	d83530cb4500	FDIV float ptr [0x0045cb30]
0045cb03	dd5de8	FSTP double ptr [EBP + -0x18]
0045cb06	9b	WAIT
0045cb07	dd45e8	FLD double ptr [EBP + -0x18]
0045cb0a	d81d34cb4500	FCOMP float ptr [0x0045cb34]
0045cb10	dfe0	FNSTSW AX
0045cb12	9e	SAHF
0045cb13	7612	JBE 0x0045cb27
0045cb15	dd45e8	FLD double ptr [EBP + -0x18]
0045cb18	d83538cb4500	FDIV float ptr [0x0045cb38]
0045cb1e	e8655efaff	CALL 0x00402988
0045cb23	db7df0	FSTP extended double ptr [EBP + -0x10]
0045cb26	9b	WAIT
0045cb27	db6df0	FLD extended double ptr [EBP + -0x10]
0045cb2a	8be5	MOV ESP,EBP
0045cb2c	5d	POP EBP
0045cb2d	c20800	RET 0x8
