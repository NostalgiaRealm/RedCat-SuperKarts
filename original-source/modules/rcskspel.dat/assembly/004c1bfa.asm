; 004c1bfa __cfltcvt
004c1bfa	55	PUSH EBP
004c1bfb	8bec	MOV EBP,ESP
004c1bfd	837d1065	CMP dword ptr [EBP + 0x10],0x65
004c1c01	7432	JZ 0x004c1c35
004c1c03	837d1045	CMP dword ptr [EBP + 0x10],0x45
004c1c07	742c	JZ 0x004c1c35
004c1c09	837d1066	CMP dword ptr [EBP + 0x10],0x66
004c1c0d	7513	JNZ 0x004c1c22
004c1c0f	ff7514	PUSH dword ptr [EBP + 0x14]
004c1c12	ff750c	PUSH dword ptr [EBP + 0xc]
004c1c15	ff7508	PUSH dword ptr [EBP + 0x8]
004c1c18	e81afeffff	CALL 0x004c1a37
004c1c1d	83c40c	ADD ESP,0xc
004c1c20	5d	POP EBP
004c1c21	c3	RET
004c1c22	ff7518	PUSH dword ptr [EBP + 0x18]
004c1c25	ff7514	PUSH dword ptr [EBP + 0x14]
004c1c28	ff750c	PUSH dword ptr [EBP + 0xc]
004c1c2b	ff7508	PUSH dword ptr [EBP + 0x8]
004c1c2e	e8e2feffff	CALL 0x004c1b15
004c1c33	eb11	JMP 0x004c1c46
004c1c35	ff7518	PUSH dword ptr [EBP + 0x18]
004c1c38	ff7514	PUSH dword ptr [EBP + 0x14]
004c1c3b	ff750c	PUSH dword ptr [EBP + 0xc]
004c1c3e	ff7508	PUSH dword ptr [EBP + 0x8]
004c1c41	e8edfcffff	CALL 0x004c1933
004c1c46	83c410	ADD ESP,0x10
004c1c49	5d	POP EBP
004c1c4a	c3	RET
