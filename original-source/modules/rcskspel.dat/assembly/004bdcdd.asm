; 004bdcdd FUN_004bdcdd
004bdcdd	8b4130	MOV EAX,dword ptr [ECX + 0x30]
004bdce0	8b542404	MOV EDX,dword ptr [ESP + 0x4]
004bdce4	2910	SUB dword ptr [EAX],EDX
004bdce6	8b4120	MOV EAX,dword ptr [ECX + 0x20]
004bdce9	8d0c12	LEA ECX,[EDX + EDX*0x1]
004bdcec	0108	ADD dword ptr [EAX],ECX
004bdcee	c20400	RET 0x4
