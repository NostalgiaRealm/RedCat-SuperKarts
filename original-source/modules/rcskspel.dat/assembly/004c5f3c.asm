; 004c5f3c FUN_004c5f3c
004c5f3c	52	PUSH EDX
004c5f3d	83ec30	SUB ESP,0x30
004c5f40	db7c2418	FSTP extended double ptr [ESP + 0x18]
004c5f44	db3c24	FSTP extended double ptr [ESP]
004c5f47	33d2	XOR EDX,EDX
004c5f49	8b442406	MOV EAX,dword ptr [ESP + 0x6]
004c5f4d	a90000ff7f	TEST EAX,0x7fff0000
004c5f52	740a	JZ 0x004c5f5e
004c5f54	e8ddfdffff	CALL 0x004c5d36
004c5f59	83c430	ADD ESP,0x30
004c5f5c	5a	POP EDX
004c5f5d	c3	RET
004c5f5e	db2c24	FLD extended double ptr [ESP]
004c5f61	db6c2418	FLD extended double ptr [ESP + 0x18]
004c5f65	8b0424	MOV EAX,dword ptr [ESP]
004c5f68	0b442404	OR EAX,dword ptr [ESP + 0x4]
004c5f6c	7479	JZ 0x004c5fe7
004c5f6e	d9c9	FXCH
004c5f70	db7c240c	FSTP extended double ptr [ESP + 0xc]
004c5f74	db2c24	FLD extended double ptr [ESP]
004c5f77	d9c9	FXCH
004c5f79	83ca02	OR EDX,0x2
004c5f7c	d97c2424	FNSTCW word ptr [ESP + 0x24]
004c5f80	8b442424	MOV EAX,dword ptr [ESP + 0x24]
004c5f84	0d3f030000	OR EAX,0x33f
004c5f89	89442428	MOV dword ptr [ESP + 0x28],EAX
004c5f8d	d96c2428	FLDCW word ptr [ESP + 0x28]
004c5f91	8b442420	MOV EAX,dword ptr [ESP + 0x20]
004c5f95	25ff7f0000	AND EAX,0x7fff
004c5f9a	3dbe7f0000	CMP EAX,0x7fbe
004c5f9f	7718	JA 0x004c5fb9
004c5fa1	83ca01	OR EDX,0x1
004c5fa4	dc0db4305000	FMUL double ptr [0x005030b4]
004c5faa	db7c2418	FSTP extended double ptr [ESP + 0x18]
004c5fae	dc0db4305000	FMUL double ptr [0x005030b4]
004c5fb4	db3c24	FSTP extended double ptr [ESP]
004c5fb7	eb20	JMP 0x004c5fd9
004c5fb9	d97c2424	FNSTCW word ptr [ESP + 0x24]
004c5fbd	8b442424	MOV EAX,dword ptr [ESP + 0x24]
004c5fc1	0d00030000	OR EAX,0x300
004c5fc6	89442428	MOV dword ptr [ESP + 0x28],EAX
004c5fca	d96c2428	FLDCW word ptr [ESP + 0x28]
004c5fce	ddd8	FSTP ST0
004c5fd0	dc0db4305000	FMUL double ptr [0x005030b4]
004c5fd6	db3c24	FSTP extended double ptr [ESP]
004c5fd9	d96c2424	FLDCW word ptr [ESP + 0x24]
004c5fdd	e854fdffff	CALL 0x004c5d36
004c5fe2	83c430	ADD ESP,0x30
004c5fe5	5a	POP EDX
004c5fe6	c3	RET
004c5fe7	d9f8	FPREM
004c5fe9	83c430	ADD ESP,0x30
004c5fec	5a	POP EDX
004c5fed	c3	RET
