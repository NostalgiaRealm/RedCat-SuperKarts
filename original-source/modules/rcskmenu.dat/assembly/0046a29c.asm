; 0046a29c TfrmDisplaySettings_lblBrightnessDarkClick
0046a29c	b201	MOV DL,0x1
0046a29e	8b80ec020000	MOV EAX,dword ptr [EAX + 0x2ec]
0046a2a4	8b08	MOV ECX,dword ptr [EAX]
0046a2a6	ff91b8000000	CALL dword ptr [ECX + 0xb8]
0046a2ac	c3	RET
