; 0044af64 FUN_0044af64
0044af64	55	PUSH EBP
0044af65	8bec	MOV EBP,ESP
0044af67	83c4d8	ADD ESP,-0x28
0044af6a	53	PUSH EBX
0044af6b	8b5d08	MOV EBX,dword ptr [EBP + 0x8]
0044af6e	8b5bfc	MOV EBX,dword ptr [EBX + -0x4]
0044af71	8b4308	MOV EAX,dword ptr [EBX + 0x8]
0044af74	8945f8	MOV dword ptr [EBP + -0x8],EAX
0044af77	8b4304	MOV EAX,dword ptr [EBX + 0x4]
0044af7a	8945fc	MOV dword ptr [EBP + -0x4],EAX
0044af7d	8b03	MOV EAX,dword ptr [EBX]
0044af7f	8945f0	MOV dword ptr [EBP + -0x10],EAX
0044af82	8b430c	MOV EAX,dword ptr [EBX + 0xc]
0044af85	8945f4	MOV dword ptr [EBP + -0xc],EAX
0044af88	8b4508	MOV EAX,dword ptr [EBP + 0x8]
0044af8b	8b50f4	MOV EDX,dword ptr [EAX + -0xc]
0044af8e	8b4508	MOV EAX,dword ptr [EBP + 0x8]
0044af91	8b40f8	MOV EAX,dword ptr [EAX + -0x8]
0044af94	8b4010	MOV EAX,dword ptr [EAX + 0x10]
0044af97	e820ccfcff	CALL 0x00417bbc
0044af9c	8b45f0	MOV EAX,dword ptr [EBP + -0x10]
0044af9f	8945d8	MOV dword ptr [EBP + -0x28],EAX
0044afa2	8b45f4	MOV EAX,dword ptr [EBP + -0xc]
0044afa5	8945dc	MOV dword ptr [EBP + -0x24],EAX
0044afa8	8b03	MOV EAX,dword ptr [EBX]
0044afaa	8945e0	MOV dword ptr [EBP + -0x20],EAX
0044afad	8b4304	MOV EAX,dword ptr [EBX + 0x4]
0044afb0	8945e4	MOV dword ptr [EBP + -0x1c],EAX
0044afb3	8b45f8	MOV EAX,dword ptr [EBP + -0x8]
0044afb6	8945e8	MOV dword ptr [EBP + -0x18],EAX
0044afb9	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044afbc	8945ec	MOV dword ptr [EBP + -0x14],EAX
0044afbf	8d55d8	LEA EDX,[EBP + -0x28]
0044afc2	8b4508	MOV EAX,dword ptr [EBP + 0x8]
0044afc5	8b40f8	MOV EAX,dword ptr [EAX + -0x8]
0044afc8	b902000000	MOV ECX,0x2
0044afcd	e86ad6fcff	CALL 0x0041863c
0044afd2	8b4508	MOV EAX,dword ptr [EBP + 0x8]
0044afd5	8b500c	MOV EDX,dword ptr [EAX + 0xc]
0044afd8	8b4508	MOV EAX,dword ptr [EBP + 0x8]
0044afdb	8b40f8	MOV EAX,dword ptr [EAX + -0x8]
0044afde	8b4010	MOV EAX,dword ptr [EAX + 0x10]
0044afe1	e8d6cbfcff	CALL 0x00417bbc
0044afe6	ff4df0	DEC dword ptr [EBP + -0x10]
0044afe9	8b45f8	MOV EAX,dword ptr [EBP + -0x8]
0044afec	8945d8	MOV dword ptr [EBP + -0x28],EAX
0044afef	8b45fc	MOV EAX,dword ptr [EBP + -0x4]
0044aff2	8945dc	MOV dword ptr [EBP + -0x24],EAX
0044aff5	8b4308	MOV EAX,dword ptr [EBX + 0x8]
0044aff8	8945e0	MOV dword ptr [EBP + -0x20],EAX
0044affb	8b430c	MOV EAX,dword ptr [EBX + 0xc]
0044affe	8945e4	MOV dword ptr [EBP + -0x1c],EAX
0044b001	8b45f0	MOV EAX,dword ptr [EBP + -0x10]
0044b004	8945e8	MOV dword ptr [EBP + -0x18],EAX
0044b007	8b45f4	MOV EAX,dword ptr [EBP + -0xc]
0044b00a	8945ec	MOV dword ptr [EBP + -0x14],EAX
0044b00d	8d55d8	LEA EDX,[EBP + -0x28]
0044b010	8b4508	MOV EAX,dword ptr [EBP + 0x8]
0044b013	8b40f8	MOV EAX,dword ptr [EAX + -0x8]
0044b016	b902000000	MOV ECX,0x2
0044b01b	e81cd6fcff	CALL 0x0041863c
0044b020	5b	POP EBX
0044b021	8be5	MOV ESP,EBP
0044b023	5d	POP EBP
0044b024	c3	RET
