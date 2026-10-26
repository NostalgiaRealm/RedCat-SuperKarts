; 0046a288 TfrmDisplaySettings_lblBrightnessLightClick
0046a288	b201	MOV DL,0x1
0046a28a	8b80e8020000	MOV EAX,dword ptr [EAX + 0x2e8]
0046a290	8b08	MOV ECX,dword ptr [EAX]
0046a292	ff91b8000000	CALL dword ptr [ECX + 0xb8]
0046a298	c3	RET
