; 004bdcf1 FUN_004bdcf1
004bdcf1	8b4130	MOV EAX,dword ptr [ECX + 0x30]
004bdcf4	ff08	DEC dword ptr [EAX]
004bdcf6	8b4920	MOV ECX,dword ptr [ECX + 0x20]
004bdcf9	8b01	MOV EAX,dword ptr [ECX]
004bdcfb	8d5002	LEA EDX,[EAX + 0x2]
004bdcfe	8911	MOV dword ptr [ECX],EDX
004bdd00	c3	RET
