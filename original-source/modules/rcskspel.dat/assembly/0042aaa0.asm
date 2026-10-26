; 0042aaa0 FUN_0042aaa0
0042aaa0	8bc1	MOV EAX,ECX
0042aaa2	8b4c2404	MOV ECX,dword ptr [ESP + 0x4]
0042aaa6	3bc1	CMP EAX,ECX
0042aaa8	742f	JZ 0x0042aad9
0042aaaa	8b11	MOV EDX,dword ptr [ECX]
0042aaac	c7400401000000	MOV dword ptr [EAX + 0x4],0x1
0042aab3	8910	MOV dword ptr [EAX],EDX
0042aab5	8b5108	MOV EDX,dword ptr [ECX + 0x8]
0042aab8	895008	MOV dword ptr [EAX + 0x8],EDX
0042aabb	8a5114	MOV DL,byte ptr [ECX + 0x14]
0042aabe	885014	MOV byte ptr [EAX + 0x14],DL
0042aac1	8a5115	MOV DL,byte ptr [ECX + 0x15]
0042aac4	885015	MOV byte ptr [EAX + 0x15],DL
0042aac7	8a5116	MOV DL,byte ptr [ECX + 0x16]
0042aaca	885016	MOV byte ptr [EAX + 0x16],DL
0042aacd	8a5117	MOV DL,byte ptr [ECX + 0x17]
0042aad0	885017	MOV byte ptr [EAX + 0x17],DL
0042aad3	8a4918	MOV CL,byte ptr [ECX + 0x18]
0042aad6	884818	MOV byte ptr [EAX + 0x18],CL
0042aad9	c20400	RET 0x4
