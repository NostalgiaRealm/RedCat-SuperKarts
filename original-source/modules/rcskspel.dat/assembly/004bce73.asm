; 004bce73 FUN_004bce73
004bce73	8b4130	MOV EAX,dword ptr [ECX + 0x30]
004bce76	ff08	DEC dword ptr [EAX]
004bce78	8b4920	MOV ECX,dword ptr [ECX + 0x20]
004bce7b	8b01	MOV EAX,dword ptr [ECX]
004bce7d	8d5001	LEA EDX,[EAX + 0x1]
004bce80	8911	MOV dword ptr [ECX],EDX
004bce82	c3	RET
