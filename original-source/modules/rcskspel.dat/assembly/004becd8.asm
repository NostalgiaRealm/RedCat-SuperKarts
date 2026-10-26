; 004becd8 FUN_004becd8
004becd8	55	PUSH EBP
004becd9	8bec	MOV EBP,ESP
004becdb	53	PUSH EBX
004becdc	56	PUSH ESI
004becdd	57	PUSH EDI
004becde	fc	CLD
004becdf	8b4508	MOV EAX,dword ptr [EBP + 0x8]
004bece2	8b4004	MOV EAX,dword ptr [EAX + 0x4]
004bece5	83e066	AND EAX,0x66
004bece8	85c0	TEST EAX,EAX
004becea	740f	JZ 0x004becfb
004becec	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004becef	c7402401000000	MOV dword ptr [EAX + 0x24],0x1
004becf6	6a01	PUSH 0x1
004becf8	58	POP EAX
004becf9	eb4d	JMP 0x004bed48
004becfb	6a01	PUSH 0x1
004becfd	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bed00	ff7014	PUSH dword ptr [EAX + 0x14]
004bed03	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bed06	ff7010	PUSH dword ptr [EAX + 0x10]
004bed09	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bed0c	ff7008	PUSH dword ptr [EAX + 0x8]
004bed0f	6a00	PUSH 0x0
004bed11	ff7510	PUSH dword ptr [EBP + 0x10]
004bed14	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bed17	ff700c	PUSH dword ptr [EAX + 0xc]
004bed1a	ff7508	PUSH dword ptr [EBP + 0x8]
004bed1d	e8063f0000	CALL 0x004c2c28
004bed22	83c420	ADD ESP,0x20
004bed25	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bed28	83782400	CMP dword ptr [EAX + 0x24],0x0
004bed2c	750b	JNZ 0x004bed39
004bed2e	ff7508	PUSH dword ptr [EBP + 0x8]
004bed31	ff750c	PUSH dword ptr [EBP + 0xc]
004bed34	e8edfdffff	CALL 0x004beb26
004bed39	8b5d0c	MOV EBX,dword ptr [EBP + 0xc]
004bed3c	8b631c	MOV ESP,dword ptr [EBX + 0x1c]
004bed3f	8b6b20	MOV EBP,dword ptr [EBX + 0x20]
004bed42	ff6318	JMP dword ptr [EBX + 0x18]
004bed48	5f	POP EDI
004bed49	5e	POP ESI
004bed4a	5b	POP EBX
004bed4b	5d	POP EBP
004bed4c	c3	RET
