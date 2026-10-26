; 004c4ebe FUN_004c4ebe
004c1ec6	ddd8	FSTP ST0
004c1ec8	d9ee	FLDZ
004c1eca	c3	RET
004c4e70	58	POP EAX
004c4e71	d9e4	FTST
004c4e73	9bddbd60ffffff	FSTSW word ptr [EBP + 0xffffff60]
004c4e7a	9b	WAIT
004c4e7b	f68561ffffff01	TEST byte ptr [EBP + 0xffffff61],0x1
004c4e82	750f	JNZ 0x004c4e93
004c4e84	ddd8	FSTP ST0
004c4e86	db2d10305000	FLD extended double ptr [0x00503010]
004c4e8c	0aed	OR CH,CH
004c4e8e	7402	JZ 0x004c4e92
004c4e90	d9e0	FCHS
004c4e92	c3	RET
004c4e93	c68570ffffff04	MOV byte ptr [EBP + 0xffffff70],0x4
004c4e9a	e927d0ffff	JMP 0x004c1ec6
004c4ebe	d9c0	FLD ST0
004c4ec0	d9e1	FABS
004c4ec2	db2d2e305000	FLD extended double ptr [0x0050302e]
004c4ec8	ded9	FCOMPP
004c4eca	9bddbd60ffffff	FSTSW word ptr [EBP + 0xffffff60]
004c4ed1	9b	WAIT
004c4ed2	f68561ffffff41	TEST byte ptr [EBP + 0xffffff61],0x41
004c4ed9	7595	JNZ 0x004c4e70
004c4edb	d9c0	FLD ST0
004c4edd	d9fc	FRNDINT
004c4edf	d9e4	FTST
004c4ee1	9bddbd60ffffff	FSTSW word ptr [EBP + 0xffffff60]
004c4ee8	9b	WAIT
004c4ee9	8a9561ffffff	MOV DL,byte ptr [EBP + 0xffffff61]
004c4eef	d9c9	FXCH
004c4ef1	d8e1	FSUB ST0,ST1
004c4ef3	d9e4	FTST
004c4ef5	9bddbd60ffffff	FSTSW word ptr [EBP + 0xffffff60]
004c4efc	d9e1	FABS
004c4efe	d9f0	F2XM1
004c4f00	c3	RET
