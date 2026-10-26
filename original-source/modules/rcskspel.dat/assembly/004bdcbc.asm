; 004bdcbc FUN_004bdcbc
004bdcbc	8b412c	MOV EAX,dword ptr [ECX + 0x2c]
004bdcbf	ff00	INC dword ptr [EAX]
004bdcc1	8b411c	MOV EAX,dword ptr [ECX + 0x1c]
004bdcc4	8300fe	ADD dword ptr [EAX],-0x2
004bdcc7	8b411c	MOV EAX,dword ptr [ECX + 0x1c]
004bdcca	8b00	MOV EAX,dword ptr [EAX]
004bdccc	c3	RET
