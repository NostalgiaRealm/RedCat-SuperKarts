; 004c1fa7 __startOneArgErrorHandling
004c1fa7	55	PUSH EBP
004c1fa8	8bec	MOV EBP,ESP
004c1faa	83c4e0	ADD ESP,-0x20
004c1fad	8945e0	MOV dword ptr [EBP + -0x20],EAX
004c1fb0	dd5df8	FSTP double ptr [EBP + -0x8]
004c1fb3	894de4	MOV dword ptr [EBP + -0x1c],ECX
004c1fb6	8b4510	MOV EAX,dword ptr [EBP + 0x10]
004c1fb9	8b4d14	MOV ECX,dword ptr [EBP + 0x14]
004c1fbc	8945e8	MOV dword ptr [EBP + -0x18],EAX
004c1fbf	894dec	MOV dword ptr [EBP + -0x14],ECX
004c1fc2	8d4508	LEA EAX,[EBP + 0x8]
004c1fc5	8d4de0	LEA ECX,[EBP + -0x20]
004c1fc8	50	PUSH EAX
004c1fc9	51	PUSH ECX
004c1fca	52	PUSH EDX
004c1fcb	e8d0750000	CALL 0x004c95a0
004c1fd0	83c40c	ADD ESP,0xc
004c1fd3	dd45f8	FLD double ptr [EBP + -0x8]
004c1fd6	66817d087f02	CMP word ptr [EBP + 0x8],0x27f
004c1fdc	7403	JZ 0x004c1fe1
004c1fde	d96d08	FLDCW word ptr [EBP + 0x8]
004c1fe1	c9	LEAVE
004c1fe2	c3	RET
