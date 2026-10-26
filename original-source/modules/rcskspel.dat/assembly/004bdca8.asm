; 004bdca8 FUN_004bdca8
004bdca8	8b412c	MOV EAX,dword ptr [ECX + 0x2c]
004bdcab	8b542404	MOV EDX,dword ptr [ESP + 0x4]
004bdcaf	2910	SUB dword ptr [EAX],EDX
004bdcb1	8b411c	MOV EAX,dword ptr [ECX + 0x1c]
004bdcb4	8d0c12	LEA ECX,[EDX + EDX*0x1]
004bdcb7	0108	ADD dword ptr [EAX],ECX
004bdcb9	c20400	RET 0x4
