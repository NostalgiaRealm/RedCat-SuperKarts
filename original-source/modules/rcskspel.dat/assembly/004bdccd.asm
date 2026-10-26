; 004bdccd Gninc
004bdccd	8b412c	MOV EAX,dword ptr [ECX + 0x2c]
004bdcd0	ff08	DEC dword ptr [EAX]
004bdcd2	8b491c	MOV ECX,dword ptr [ECX + 0x1c]
004bdcd5	8b01	MOV EAX,dword ptr [ECX]
004bdcd7	8d5002	LEA EDX,[EAX + 0x2]
004bdcda	8911	MOV dword ptr [ECX],EDX
004bdcdc	c3	RET
