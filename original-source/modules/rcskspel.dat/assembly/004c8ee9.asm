; 004c8ee9 FUN_004c8ee9
004c8ee9	8b442408	MOV EAX,dword ptr [ESP + 0x8]
004c8eed	25fffff7ff	AND EAX,0xfff7ffff
004c8ef2	50	PUSH EAX
004c8ef3	ff742408	PUSH dword ptr [ESP + 0x8]
004c8ef7	e8b8ffffff	CALL 0x004c8eb4
004c8efc	59	POP ECX
004c8efd	59	POP ECX
004c8efe	c3	RET
