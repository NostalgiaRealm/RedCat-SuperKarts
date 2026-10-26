; 004bfe36 exception::~exception
004bfe36	83790800	CMP dword ptr [ECX + 0x8],0x0
004bfe3a	c7013c374d00	MOV dword ptr [ECX],0x4d373c
004bfe40	7409	JZ 0x004bfe4b
004bfe42	ff7104	PUSH dword ptr [ECX + 0x4]
004bfe45	e806c3ffff	CALL 0x004bc150
004bfe4a	59	POP ECX
004bfe4b	c3	RET
