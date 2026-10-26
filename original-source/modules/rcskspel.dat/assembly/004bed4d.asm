; 004bed4d FUN_004bed4d
004bed4d	55	PUSH EBP
004bed4e	8bec	MOV EBP,ESP
004bed50	51	PUSH ECX
004bed51	53	PUSH EBX
004bed52	56	PUSH ESI
004bed53	837d0c00	CMP dword ptr [EBP + 0xc],0x0
004bed57	57	PUSH EDI
004bed58	8b7d08	MOV EDI,dword ptr [EBP + 0x8]
004bed5b	8b770c	MOV ESI,dword ptr [EDI + 0xc]
004bed5e	8b5f10	MOV EBX,dword ptr [EDI + 0x10]
004bed61	8bc6	MOV EAX,ESI
004bed63	897508	MOV dword ptr [EBP + 0x8],ESI
004bed66	8945fc	MOV dword ptr [EBP + -0x4],EAX
004bed69	7c39	JL 0x004beda4
004bed6b	83feff	CMP ESI,-0x1
004bed6e	7505	JNZ 0x004bed75
004bed70	e85d3e0000	CALL 0x004c2bd2
004bed75	8b4d10	MOV ECX,dword ptr [EBP + 0x10]
004bed78	4e	DEC ESI
004bed79	8d04b6	LEA EAX,[ESI + ESI*0x4]
004bed7c	394c8304	CMP dword ptr [EBX + EAX*0x4 + 0x4],ECX
004bed80	8d0483	LEA EAX,[EBX + EAX*0x4]
004bed83	7d05	JGE 0x004bed8a
004bed85	3b4808	CMP ECX,dword ptr [EAX + 0x8]
004bed88	7e05	JLE 0x004bed8f
004bed8a	83feff	CMP ESI,-0x1
004bed8d	750c	JNZ 0x004bed9b
004bed8f	8b4508	MOV EAX,dword ptr [EBP + 0x8]
004bed92	ff4d0c	DEC dword ptr [EBP + 0xc]
004bed95	8945fc	MOV dword ptr [EBP + -0x4],EAX
004bed98	897508	MOV dword ptr [EBP + 0x8],ESI
004bed9b	837d0c00	CMP dword ptr [EBP + 0xc],0x0
004bed9f	7dca	JGE 0x004bed6b
004beda1	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
004beda4	8b4d14	MOV ECX,dword ptr [EBP + 0x14]
004beda7	46	INC ESI
004beda8	8931	MOV dword ptr [ECX],ESI
004bedaa	8b4d18	MOV ECX,dword ptr [EBP + 0x18]
004bedad	8901	MOV dword ptr [ECX],EAX
004bedaf	3b470c	CMP EAX,dword ptr [EDI + 0xc]
004bedb2	7704	JA 0x004bedb8
004bedb4	3bf0	CMP ESI,EAX
004bedb6	7605	JBE 0x004bedbd
004bedb8	e8153e0000	CALL 0x004c2bd2
004bedbd	8d04b6	LEA EAX,[ESI + ESI*0x4]
004bedc0	5f	POP EDI
004bedc1	5e	POP ESI
004bedc2	8d0483	LEA EAX,[EBX + EAX*0x4]
004bedc5	5b	POP EBX
004bedc6	c9	LEAVE
004bedc7	c3	RET
