; 0044bc4c FUN_0044bc4c
0044bc4c	55	PUSH EBP
0044bc4d	8bec	MOV EBP,ESP
0044bc4f	83c4e8	ADD ESP,-0x18
0044bc52	53	PUSH EBX
0044bc53	56	PUSH ESI
0044bc54	57	PUSH EDI
0044bc55	8955f8	MOV dword ptr [EBP + -0x8],EDX
0044bc58	8945fc	MOV dword ptr [EBP + -0x4],EAX
0044bc5b	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bc5e	80784c00	CMP byte ptr [EAX + 0x4c],0x0
0044bc62	0f8409010000	JZ 0x0044bd71
0044bc68	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bc6b	c680f801000001	MOV byte ptr [EAX + 0x1f8],0x1
0044bc72	33d2	XOR EDX,EDX
0044bc74	55	PUSH EBP
0044bc75	686abd4400	PUSH 0x44bd6a
0044bc7a	64ff32	PUSH dword ptr FS:[EDX]
0044bc7d	648922	MOV dword ptr FS:[EDX],ESP
0044bc80	8b45f8	MOV EAX,dword ptr [EBP + -0x8]
0044bc83	8b4004	MOV EAX,dword ptr [EAX + 0x4]
0044bc86	8d7044	LEA ESI,[EAX + 0x44]
0044bc89	8d7de8	LEA EDI,[EBP + -0x18]
0044bc8c	b904000000	MOV ECX,0x4
0044bc91	f3a5	MOVSD.REP ES:EDI,ESI
0044bc93	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bc96	8a404b	MOV AL,byte ptr [EAX + 0x4b]
0044bc99	fec8	DEC AL
0044bc9b	745d	JZ 0x0044bcfa
0044bc9d	fec8	DEC AL
0044bc9f	7472	JZ 0x0044bd13
0044bca1	fec8	DEC AL
0044bca3	7409	JZ 0x0044bcae
0044bca5	fec8	DEC AL
0044bca7	7422	JZ 0x0044bccb
0044bca9	e992000000	JMP 0x0044bd40
0044bcae	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bcb1	83783800	CMP dword ptr [EAX + 0x38],0x0
0044bcb5	0f8585000000	JNZ 0x0044bd40
0044bcbb	8b55f0	MOV EDX,dword ptr [EBP + -0x10]
0044bcbe	2b55e8	SUB EDX,dword ptr [EBP + -0x18]
0044bcc1	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bcc4	e8e731ffff	CALL 0x0043eeb0
0044bcc9	eb75	JMP 0x0044bd40
0044bccb	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bcce	83783800	CMP dword ptr [EAX + 0x38],0x0
0044bcd2	756c	JNZ 0x0044bd40
0044bcd4	8b45f0	MOV EAX,dword ptr [EBP + -0x10]
0044bcd7	2b45e8	SUB EAX,dword ptr [EBP + -0x18]
0044bcda	50	PUSH EAX
0044bcdb	8b55fc	MOV EDX,dword ptr [EBP + -0x4]
0044bcde	8b523c	MOV EDX,dword ptr [EDX + 0x3c]
0044bce1	52	PUSH EDX
0044bce2	8b55fc	MOV EDX,dword ptr [EBP + -0x4]
0044bce5	8b4a34	MOV ECX,dword ptr [EDX + 0x34]
0044bce8	8b55fc	MOV EDX,dword ptr [EBP + -0x4]
0044bceb	8b5230	MOV EDX,dword ptr [EDX + 0x30]
0044bcee	2bd0	SUB EDX,EAX
0044bcf0	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bcf3	8b18	MOV EBX,dword ptr [EAX]
0044bcf5	ff537c	CALL dword ptr [EBX + 0x7c]
0044bcf8	eb46	JMP 0x0044bd40
0044bcfa	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bcfd	83783c00	CMP dword ptr [EAX + 0x3c],0x0
0044bd01	753d	JNZ 0x0044bd40
0044bd03	8b55f4	MOV EDX,dword ptr [EBP + -0xc]
0044bd06	2b55ec	SUB EDX,dword ptr [EBP + -0x14]
0044bd09	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bd0c	e8bf31ffff	CALL 0x0043eed0
0044bd11	eb2d	JMP 0x0044bd40
0044bd13	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bd16	83783c00	CMP dword ptr [EAX + 0x3c],0x0
0044bd1a	7524	JNZ 0x0044bd40
0044bd1c	8b45f4	MOV EAX,dword ptr [EBP + -0xc]
0044bd1f	2b45ec	SUB EAX,dword ptr [EBP + -0x14]
0044bd22	8b55fc	MOV EDX,dword ptr [EBP + -0x4]
0044bd25	8b5238	MOV EDX,dword ptr [EDX + 0x38]
0044bd28	52	PUSH EDX
0044bd29	50	PUSH EAX
0044bd2a	8b55fc	MOV EDX,dword ptr [EBP + -0x4]
0044bd2d	8b4a34	MOV ECX,dword ptr [EDX + 0x34]
0044bd30	2bc8	SUB ECX,EAX
0044bd32	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bd35	8b5030	MOV EDX,dword ptr [EAX + 0x30]
0044bd38	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bd3b	8b18	MOV EBX,dword ptr [EAX]
0044bd3d	ff537c	CALL dword ptr [EBX + 0x7c]
0044bd40	8b55f8	MOV EDX,dword ptr [EBP + -0x8]
0044bd43	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bd46	e8c184ffff	CALL 0x0044420c
0044bd4b	e85479fbff	CALL 0x004036a4
0044bd50	eb2a	JMP 0x0044bd7c
0044bd71	8b55f8	MOV EDX,dword ptr [EBP + -0x8]
0044bd74	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044bd77	e89084ffff	CALL 0x0044420c
0044bd7c	5f	POP EDI
0044bd7d	5e	POP ESI
0044bd7e	5b	POP EBX
0044bd7f	8be5	MOV ESP,EBP
0044bd81	5d	POP EBP
0044bd82	c3	RET
