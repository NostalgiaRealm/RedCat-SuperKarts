; 004be698 __ftol
004be698	55	PUSH EBP
004be699	8bec	MOV EBP,ESP
004be69b	83c4f4	ADD ESP,-0xc
004be69e	9bd97dfe	FSTCW word ptr [EBP + -0x2]
004be6a2	9b	WAIT
004be6a3	668b45fe	MOV AX,word ptr [EBP + -0x2]
004be6a7	80cc0c	OR AH,0xc
004be6aa	668945fc	MOV word ptr [EBP + -0x4],AX
004be6ae	d96dfc	FLDCW word ptr [EBP + -0x4]
004be6b1	df7df4	FISTP qword ptr [EBP + -0xc]
004be6b4	d96dfe	FLDCW word ptr [EBP + -0x2]
004be6b7	8b45f4	MOV EAX,dword ptr [EBP + -0xc]
004be6ba	8b55f8	MOV EDX,dword ptr [EBP + -0x8]
004be6bd	c9	LEAVE
004be6be	c3	RET
