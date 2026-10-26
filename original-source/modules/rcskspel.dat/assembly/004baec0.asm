; 004baec0 FUN_004baec0
004baec0	8b4c2404	MOV ECX,dword ptr [ESP + 0x4]
004baec4	b824ba6a00	MOV EAX,0x6aba24
004baec9	3948fc	CMP dword ptr [EAX + -0x4],ECX
004baecc	7505	JNZ 0x004baed3
004baece	833800	CMP dword ptr [EAX],0x0
004baed1	7519	JNZ 0x004baeec
004baed3	394858	CMP dword ptr [EAX + 0x58],ECX
004baed6	7507	JNZ 0x004baedf
004baed8	8b505c	MOV EDX,dword ptr [EAX + 0x5c]
004baedb	85d2	TEST EDX,EDX
004baedd	750d	JNZ 0x004baeec
004baedf	83c008	ADD EAX,0x8
004baee2	3d64ba6a00	CMP EAX,0x6aba64
004baee7	7ce0	JL 0x004baec9
004baee9	33c0	XOR EAX,EAX
004baeeb	c3	RET
004baeec	b801000000	MOV EAX,0x1
004baef1	c3	RET
