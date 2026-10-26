; 00463bb0 FUN_00463bb0
00463bb0	83ec0c	SUB ESP,0xc
00463bb3	56	PUSH ESI
00463bb4	8bf1	MOV ESI,ECX
00463bb6	57	PUSH EDI
00463bb7	8b7c2418	MOV EDI,dword ptr [ESP + 0x18]
00463bbb	d9467c	FLD float ptr [ESI + 0x7c]
00463bbe	d84f0c	FMUL float ptr [EDI + 0xc]
00463bc1	d95e54	FSTP float ptr [ESI + 0x54]
00463bc4	8b470c	MOV EAX,dword ptr [EDI + 0xc]
00463bc7	d98680000000	FLD float ptr [ESI + 0x80]
00463bcd	894650	MOV dword ptr [ESI + 0x50],EAX
00463bd0	d84f14	FMUL float ptr [EDI + 0x14]
00463bd3	d95e58	FSTP float ptr [ESI + 0x58]
00463bd6	e8f547ffff	CALL 0x004583d0
00463bdb	d900	FLD float ptr [EAX]
00463bdd	d84f10	FMUL float ptr [EDI + 0x10]
00463be0	8bce	MOV ECX,ESI
00463be2	d807	FADD float ptr [EDI]
00463be4	d95e44	FSTP float ptr [ESI + 0x44]
00463be7	e8e447ffff	CALL 0x004583d0
00463bec	d94004	FLD float ptr [EAX + 0x4]
00463bef	d84f14	FMUL float ptr [EDI + 0x14]
00463bf2	8bce	MOV ECX,ESI
00463bf4	d84704	FADD float ptr [EDI + 0x4]
00463bf7	d95e48	FSTP float ptr [ESI + 0x48]
00463bfa	e8d147ffff	CALL 0x004583d0
00463bff	d94008	FLD float ptr [EAX + 0x8]
00463c02	d84708	FADD float ptr [EDI + 0x8]
00463c05	8b16	MOV EDX,dword ptr [ESI]
00463c07	8bce	MOV ECX,ESI
00463c09	d95e4c	FSTP float ptr [ESI + 0x4c]
00463c0c	ff5220	CALL dword ptr [EDX + 0x20]
00463c0f	d94718	FLD float ptr [EDI + 0x18]
00463c12	d808	FMUL float ptr [EAX]
00463c14	d95c2408	FSTP float ptr [ESP + 0x8]
00463c18	d9471c	FLD float ptr [EDI + 0x1c]
00463c1b	d84804	FMUL float ptr [EAX + 0x4]
00463c1e	8b4c2408	MOV ECX,dword ptr [ESP + 0x8]
00463c22	d95c240c	FSTP float ptr [ESP + 0xc]
00463c26	d94720	FLD float ptr [EDI + 0x20]
00463c29	d84808	FMUL float ptr [EAX + 0x8]
00463c2c	8b54240c	MOV EDX,dword ptr [ESP + 0xc]
00463c30	8d465c	LEA EAX,[ESI + 0x5c]
00463c33	894e5c	MOV dword ptr [ESI + 0x5c],ECX
00463c36	d95c2410	FSTP float ptr [ESP + 0x10]
00463c3a	8b4c2410	MOV ECX,dword ptr [ESP + 0x10]
00463c3e	895004	MOV dword ptr [EAX + 0x4],EDX
00463c41	894808	MOV dword ptr [EAX + 0x8],ECX
00463c44	8bce	MOV ECX,ESI
00463c46	e8a547ffff	CALL 0x004583f0
00463c4b	d900	FLD float ptr [EAX]
00463c4d	d84724	FADD float ptr [EDI + 0x24]
00463c50	83c668	ADD ESI,0x68
00463c53	d95c2408	FSTP float ptr [ESP + 0x8]
00463c57	d94728	FLD float ptr [EDI + 0x28]
00463c5a	d84004	FADD float ptr [EAX + 0x4]
00463c5d	8b542408	MOV EDX,dword ptr [ESP + 0x8]
00463c61	d95c240c	FSTP float ptr [ESP + 0xc]
00463c65	d9472c	FLD float ptr [EDI + 0x2c]
00463c68	d84008	FADD float ptr [EAX + 0x8]
00463c6b	8b44240c	MOV EAX,dword ptr [ESP + 0xc]
00463c6f	8916	MOV dword ptr [ESI],EDX
00463c71	5f	POP EDI
00463c72	d95c240c	FSTP float ptr [ESP + 0xc]
00463c76	8b4c240c	MOV ECX,dword ptr [ESP + 0xc]
00463c7a	894604	MOV dword ptr [ESI + 0x4],EAX
00463c7d	894e08	MOV dword ptr [ESI + 0x8],ECX
00463c80	5e	POP ESI
00463c81	83c40c	ADD ESP,0xc
00463c84	c20400	RET 0x4
