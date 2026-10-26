; 004bfc77 __CxxThrowException@8
004bfc77	55	PUSH EBP
004bfc78	8bec	MOV EBP,ESP
004bfc7a	83ec20	SUB ESP,0x20
004bfc7d	8b4508	MOV EAX,dword ptr [EBP + 0x8]
004bfc80	56	PUSH ESI
004bfc81	57	PUSH EDI
004bfc82	6a08	PUSH 0x8
004bfc84	59	POP ECX
004bfc85	be18374d00	MOV ESI,0x4d3718
004bfc8a	8d7de0	LEA EDI,[EBP + -0x20]
004bfc8d	f3a5	MOVSD.REP ES:EDI,ESI
004bfc8f	8945f8	MOV dword ptr [EBP + -0x8],EAX
004bfc92	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bfc95	8945fc	MOV dword ptr [EBP + -0x4],EAX
004bfc98	8d45f4	LEA EAX,[EBP + -0xc]
004bfc9b	50	PUSH EAX
004bfc9c	ff75f0	PUSH dword ptr [EBP + -0x10]
004bfc9f	ff75e4	PUSH dword ptr [EBP + -0x1c]
004bfca2	ff75e0	PUSH dword ptr [EBP + -0x20]
004bfca5	ff1598204d00	CALL dword ptr [0x004d2098]
004bfcab	5f	POP EDI
004bfcac	5e	POP ESI
004bfcad	c9	LEAVE
004bfcae	c20800	RET 0x8
