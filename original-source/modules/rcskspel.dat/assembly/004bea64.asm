; 004bea64 FUN_004bea64
004bea64	8b65e8	MOV ESP,dword ptr [EBP + -0x18]
004bea67	834dfcff	OR dword ptr [EBP + -0x4],0xffffffff
004bea6b	8b4df0	MOV ECX,dword ptr [EBP + -0x10]
004bea6e	64890d00000000	MOV dword ptr FS:[0x0],ECX
004bea75	5f	POP EDI
004bea76	5e	POP ESI
004bea77	5b	POP EBX
004bea78	c9	LEAVE
004bea79	c21000	RET 0x10
