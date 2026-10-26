; 004ccbc1 FUN_004ccbc1
004ccbc1	ff742404	PUSH dword ptr [ESP + 0x4]
004ccbc5	ff1578214d00	CALL dword ptr [0x004d2178]
004ccbcb	83f8ff	CMP EAX,-0x1
004ccbce	7511	JNZ 0x004ccbe1
004ccbd0	ff15a4204d00	CALL dword ptr [0x004d20a4]
004ccbd6	50	PUSH EAX
004ccbd7	e875a2ffff	CALL 0x004c6e51
004ccbdc	59	POP ECX
004ccbdd	83c8ff	OR EAX,0xffffffff
004ccbe0	c3	RET
004ccbe1	a801	TEST AL,0x1
004ccbe3	741d	JZ 0x004ccc02
004ccbe5	f644240802	TEST byte ptr [ESP + 0x8],0x2
004ccbea	7416	JZ 0x004ccc02
004ccbec	c705e8666b000d000000	MOV dword ptr [0x006b66e8],0xd
004ccbf6	c705ec666b0005000000	MOV dword ptr [0x006b66ec],0x5
004ccc00	ebdb	JMP 0x004ccbdd
004ccc02	33c0	XOR EAX,EAX
004ccc04	c3	RET
