; 0041e8b0 FUN_0041e8b0
0041e8b0	8bc1	MOV EAX,ECX
0041e8b2	8b4c2404	MOV ECX,dword ptr [ESP + 0x4]
0041e8b6	8b11	MOV EDX,dword ptr [ECX]
0041e8b8	8910	MOV dword ptr [EAX],EDX
0041e8ba	8b5104	MOV EDX,dword ptr [ECX + 0x4]
0041e8bd	895004	MOV dword ptr [EAX + 0x4],EDX
0041e8c0	8b5108	MOV EDX,dword ptr [ECX + 0x8]
0041e8c3	895008	MOV dword ptr [EAX + 0x8],EDX
0041e8c6	8b490c	MOV ECX,dword ptr [ECX + 0xc]
0041e8c9	89480c	MOV dword ptr [EAX + 0xc],ECX
0041e8cc	c20400	RET 0x4
