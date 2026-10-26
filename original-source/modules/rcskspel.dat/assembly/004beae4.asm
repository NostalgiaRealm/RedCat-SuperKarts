; 004beae4 FUN_004beae4
004beae4	55	PUSH EBP
004beae5	8bec	MOV EBP,ESP
004beae7	51	PUSH ECX
004beae8	53	PUSH EBX
004beae9	56	PUSH ESI
004beaea	57	PUSH EDI
004beaeb	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004beaee	83c00c	ADD EAX,0xc
004beaf1	8945fc	MOV dword ptr [EBP + -0x4],EAX
004beaf4	648b1d00000000	MOV EBX,dword ptr FS:[0x0]
004beafb	8b03	MOV EAX,dword ptr [EBX]
004beafd	64a300000000	MOV FS:[0x0],EAX
004beb03	8b4508	MOV EAX,dword ptr [EBP + 0x8]
004beb06	8b5d0c	MOV EBX,dword ptr [EBP + 0xc]
004beb09	8b63fc	MOV ESP,dword ptr [EBX + -0x4]
004beb0c	8b6dfc	MOV EBP,dword ptr [EBP + -0x4]
004beb0f	ffe0	JMP EAX
