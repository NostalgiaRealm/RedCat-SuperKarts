; 004bebab FUN_004bebab
004bebab	55	PUSH EBP
004bebac	8bec	MOV EBP,ESP
004bebae	83ec14	SUB ESP,0x14
004bebb1	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bebb4	8365ec00	AND dword ptr [EBP + -0x14],0x0
004bebb8	8b4d08	MOV ECX,dword ptr [EBP + 0x8]
004bebbb	8945f4	MOV dword ptr [EBP + -0xc],EAX
004bebbe	8b4514	MOV EAX,dword ptr [EBP + 0x14]
004bebc1	c745f0ffeb4b00	MOV dword ptr [EBP + -0x10],0x4bebff
004bebc8	40	INC EAX
004bebc9	894df8	MOV dword ptr [EBP + -0x8],ECX
004bebcc	8945fc	MOV dword ptr [EBP + -0x4],EAX
004bebcf	64a100000000	MOV EAX,FS:[0x0]
004bebd5	8945ec	MOV dword ptr [EBP + -0x14],EAX
004bebd8	8d85ecffffff	LEA EAX,[EBP + 0xffffffec]
004bebde	64a300000000	MOV FS:[0x0],EAX
004bebe4	ff7518	PUSH dword ptr [EBP + 0x18]
004bebe7	51	PUSH ECX
004bebe8	ff7510	PUSH dword ptr [EBP + 0x10]
004bebeb	e820480000	CALL 0x004c3410
004bebf0	8bc8	MOV ECX,EAX
004bebf2	8b45ec	MOV EAX,dword ptr [EBP + -0x14]
004bebf5	64a300000000	MOV FS:[0x0],EAX
004bebfb	8bc1	MOV EAX,ECX
004bebfd	c9	LEAVE
004bebfe	c3	RET
