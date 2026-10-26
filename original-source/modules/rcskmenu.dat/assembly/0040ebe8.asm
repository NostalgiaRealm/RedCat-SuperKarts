; 0040ebe8 FUN_0040ebe8
0040ebe8	55	PUSH EBP
0040ebe9	8bec	MOV EBP,ESP
0040ebeb	53	PUSH EBX
0040ebec	8b5d08	MOV EBX,dword ptr [EBP + 0x8]
0040ebef	8903	MOV dword ptr [EBX],EAX
0040ebf1	895304	MOV dword ptr [EBX + 0x4],EDX
0040ebf4	894b08	MOV dword ptr [EBX + 0x8],ECX
0040ebf7	8b450c	MOV EAX,dword ptr [EBP + 0xc]
0040ebfa	89430c	MOV dword ptr [EBX + 0xc],EAX
0040ebfd	5b	POP EBX
0040ebfe	5d	POP EBP
0040ebff	c20800	RET 0x8
