; 004bdd7e FUN_004bdd7e
004bdd7e	8d5114	LEA EDX,[ECX + 0x14]
004bdd81	8d4104	LEA EAX,[ECX + 0x4]
004bdd84	89511c	MOV dword ptr [ECX + 0x1c],EDX
004bdd87	8d5118	LEA EDX,[ECX + 0x18]
004bdd8a	895120	MOV dword ptr [ECX + 0x20],EDX
004bdd8d	8d5124	LEA EDX,[ECX + 0x24]
004bdd90	89512c	MOV dword ptr [ECX + 0x2c],EDX
004bdd93	8d5128	LEA EDX,[ECX + 0x28]
004bdd96	89410c	MOV dword ptr [ECX + 0xc],EAX
004bdd99	8d4108	LEA EAX,[ECX + 0x8]
004bdd9c	895130	MOV dword ptr [ECX + 0x30],EDX
004bdd9f	33d2	XOR EDX,EDX
004bdda1	894110	MOV dword ptr [ECX + 0x10],EAX
004bdda4	8910	MOV dword ptr [EAX],EDX
004bdda6	8b4120	MOV EAX,dword ptr [ECX + 0x20]
004bdda9	8910	MOV dword ptr [EAX],EDX
004bddab	8b4130	MOV EAX,dword ptr [ECX + 0x30]
004bddae	8910	MOV dword ptr [EAX],EDX
004bddb0	8b410c	MOV EAX,dword ptr [ECX + 0xc]
004bddb3	8910	MOV dword ptr [EAX],EDX
004bddb5	8b411c	MOV EAX,dword ptr [ECX + 0x1c]
004bddb8	8910	MOV dword ptr [EAX],EDX
004bddba	8b412c	MOV EAX,dword ptr [ECX + 0x2c]
004bddbd	8910	MOV dword ptr [EAX],EDX
004bddbf	c3	RET
