; 004bceaa FUN_004bceaa
004bceaa	837c240801	CMP dword ptr [ESP + 0x8],0x1
004bceaf	56	PUSH ESI
004bceb0	8bf1	MOV ESI,ECX
004bceb2	0f94c0	SETZ AL
004bceb5	837c240c00	CMP dword ptr [ESP + 0xc],0x0
004bceba	884648	MOV byte ptr [ESI + 0x48],AL
004bcebd	751b	JNZ 0x004bceda
004bcebf	57	PUSH EDI
004bcec0	8d7e4c	LEA EDI,[ESI + 0x4c]
004bcec3	8bcf	MOV ECX,EDI
004bcec5	e822f9ffff	CALL 0x004bc7ec
004bceca	85ff	TEST EDI,EDI
004bcecc	7407	JZ 0x004bced5
004bcece	8bcf	MOV ECX,EDI
004bced0	e8f8f8ffff	CALL 0x004bc7cd
004bced5	83664400	AND dword ptr [ESI + 0x44],0x0
004bced9	5f	POP EDI
004bceda	8bce	MOV ECX,ESI
004bcedc	e89d0e0000	CALL 0x004bdd7e
004bcee1	8b442408	MOV EAX,dword ptr [ESP + 0x8]
004bcee5	85c0	TEST EAX,EAX
004bcee7	741e	JZ 0x004bcf07
004bcee9	807e4800	CMP byte ptr [ESI + 0x48],0x0
004bceed	7518	JNZ 0x004bcf07
004bceef	8d4808	LEA ECX,[EAX + 0x8]
004bcef2	89461c	MOV dword ptr [ESI + 0x1c],EAX
004bcef5	894e0c	MOV dword ptr [ESI + 0xc],ECX
004bcef8	894e10	MOV dword ptr [ESI + 0x10],ECX
004bcefb	8d4804	LEA ECX,[EAX + 0x4]
004bcefe	894620	MOV dword ptr [ESI + 0x20],EAX
004bcf01	894e2c	MOV dword ptr [ESI + 0x2c],ECX
004bcf04	894e30	MOV dword ptr [ESI + 0x30],ECX
004bcf07	894650	MOV dword ptr [ESI + 0x50],EAX
004bcf0a	a1506a6b00	MOV EAX,[0x006b6a50]
004bcf0f	894640	MOV dword ptr [ESI + 0x40],EAX
004bcf12	a1506a6b00	MOV EAX,[0x006b6a50]
004bcf17	83663800	AND dword ptr [ESI + 0x38],0x0
004bcf1b	89463c	MOV dword ptr [ESI + 0x3c],EAX
004bcf1e	5e	POP ESI
004bcf1f	c20800	RET 0x8
