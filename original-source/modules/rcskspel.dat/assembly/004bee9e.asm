; 004bee9e FUN_004bee9e
004bee9e	53	PUSH EBX
004bee9f	51	PUSH ECX
004beea0	bb88295000	MOV EBX,0x502988
004beea5	8b4d08	MOV ECX,dword ptr [EBP + 0x8]
004beea8	894b08	MOV dword ptr [EBX + 0x8],ECX
004beeab	894304	MOV dword ptr [EBX + 0x4],EAX
004beeae	896b0c	MOV dword ptr [EBX + 0xc],EBP
004beeb1	59	POP ECX
004beeb2	5b	POP EBX
004beeb3	c20400	RET 0x4
