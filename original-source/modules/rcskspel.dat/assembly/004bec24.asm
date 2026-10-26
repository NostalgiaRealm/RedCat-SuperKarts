; 004bec24 FUN_004bec24
004bec24	55	PUSH EBP
004bec25	8bec	MOV EBP,ESP
004bec27	83ec34	SUB ESP,0x34
004bec2a	53	PUSH EBX
004bec2b	56	PUSH ESI
004bec2c	57	PUSH EDI
004bec2d	8365d800	AND dword ptr [EBP + -0x28],0x0
004bec31	c745dcd8ec4b00	MOV dword ptr [EBP + -0x24],0x4becd8
004bec38	8b4518	MOV EAX,dword ptr [EBP + 0x18]
004bec3b	8945e0	MOV dword ptr [EBP + -0x20],EAX
004bec3e	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bec41	8945e4	MOV dword ptr [EBP + -0x1c],EAX
004bec44	8b451c	MOV EAX,dword ptr [EBP + 0x1c]
004bec47	8945e8	MOV dword ptr [EBP + -0x18],EAX
004bec4a	8b4520	MOV EAX,dword ptr [EBP + 0x20]
004bec4d	8945ec	MOV dword ptr [EBP + -0x14],EAX
004bec50	8365f000	AND dword ptr [EBP + -0x10],0x0
004bec54	8365f400	AND dword ptr [EBP + -0xc],0x0
004bec58	8365f800	AND dword ptr [EBP + -0x8],0x0
004bec5c	8365fc00	AND dword ptr [EBP + -0x4],0x0
004bec60	c745f0aaec4b00	MOV dword ptr [EBP + -0x10],0x4becaa
004bec67	8965f4	MOV dword ptr [EBP + -0xc],ESP
004bec6a	896df8	MOV dword ptr [EBP + -0x8],EBP
004bec6d	64a100000000	MOV EAX,FS:[0x0]
004bec73	8945d8	MOV dword ptr [EBP + -0x28],EAX
004bec76	8d85d8ffffff	LEA EAX,[EBP + 0xffffffd8]
004bec7c	64a300000000	MOV FS:[0x0],EAX
004bec82	c745cc01000000	MOV dword ptr [EBP + -0x34],0x1
004bec89	8b4508	MOV EAX,dword ptr [EBP + 0x8]
004bec8c	8945d0	MOV dword ptr [EBP + -0x30],EAX
004bec8f	8b4510	MOV EAX,dword ptr [EBP + 0x10]
004bec92	8945d4	MOV dword ptr [EBP + -0x2c],EAX
004bec95	8d45d0	LEA EAX,[EBP + -0x30]
004bec98	50	PUSH EAX
004bec99	8b4508	MOV EAX,dword ptr [EBP + 0x8]
004bec9c	ff30	PUSH dword ptr [EAX]
004bec9e	ff1574676b00	CALL dword ptr [0x006b6774]
004beca4	59	POP ECX
004beca5	59	POP ECX
004beca6	8365cc00	AND dword ptr [EBP + -0x34],0x0
004becaa	837dfc00	CMP dword ptr [EBP + -0x4],0x0
004becae	7417	JZ 0x004becc7
004becb0	648b1d00000000	MOV EBX,dword ptr FS:[0x0]
004becb7	8b03	MOV EAX,dword ptr [EBX]
004becb9	8b5dd8	MOV EBX,dword ptr [EBP + -0x28]
004becbc	8903	MOV dword ptr [EBX],EAX
004becbe	64891d00000000	MOV dword ptr FS:[0x0],EBX
004becc5	eb09	JMP 0x004becd0
004becc7	8b45d8	MOV EAX,dword ptr [EBP + -0x28]
004becca	64a300000000	MOV FS:[0x0],EAX
004becd0	8b45cc	MOV EAX,dword ptr [EBP + -0x34]
004becd3	5f	POP EDI
004becd4	5e	POP ESI
004becd5	5b	POP EBX
004becd6	c9	LEAVE
004becd7	c3	RET
