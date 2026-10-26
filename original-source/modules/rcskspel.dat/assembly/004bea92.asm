; 004bea92 FUN_004bea92
004bea92	55	PUSH EBP
004bea93	8bec	MOV EBP,ESP
004bea95	83ec20	SUB ESP,0x20
004bea98	8b4508	MOV EAX,dword ptr [EBP + 0x8]
004bea9b	56	PUSH ESI
004bea9c	8945e8	MOV dword ptr [EBP + -0x18],EAX
004bea9f	8945e0	MOV dword ptr [EBP + -0x20],EAX
004beaa2	8d4510	LEA EAX,[EBP + 0x10]
004beaa5	c745ec42000000	MOV dword ptr [EBP + -0x14],0x42
004beaac	50	PUSH EAX
004beaad	8d45e0	LEA EAX,[EBP + -0x20]
004beab0	ff750c	PUSH dword ptr [EBP + 0xc]
004beab3	c745e4ffffff7f	MOV dword ptr [EBP + -0x1c],0x7fffffff
004beaba	50	PUSH EAX
004beabb	e8d1370000	CALL 0x004c2291
004beac0	83c40c	ADD ESP,0xc
004beac3	ff4de4	DEC dword ptr [EBP + -0x1c]
004beac6	8bf0	MOV ESI,EAX
004beac8	7808	JS 0x004bead2
004beaca	8b45e0	MOV EAX,dword ptr [EBP + -0x20]
004beacd	802000	AND byte ptr [EAX],0x0
004bead0	eb0d	JMP 0x004beadf
004bead2	8d45e0	LEA EAX,[EBP + -0x20]
004bead5	50	PUSH EAX
004bead6	6a00	PUSH 0x0
004bead8	e89f360000	CALL 0x004c217c
004beadd	59	POP ECX
004beade	59	POP ECX
004beadf	8bc6	MOV EAX,ESI
004beae1	5e	POP ESI
004beae2	c9	LEAVE
004beae3	c3	RET
