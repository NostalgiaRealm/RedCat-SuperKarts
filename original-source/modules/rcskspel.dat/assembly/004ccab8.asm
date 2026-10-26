; 004ccab8 FUN_004ccab8
004ccab8	55	PUSH EBP
004ccab9	8bec	MOV EBP,ESP
004ccabb	837d100a	CMP dword ptr [EBP + 0x10],0xa
004ccabf	750c	JNZ 0x004ccacd
004ccac1	837d0800	CMP dword ptr [EBP + 0x8],0x0
004ccac5	7d06	JGE 0x004ccacd
004ccac7	6a01	PUSH 0x1
004ccac9	6a0a	PUSH 0xa
004ccacb	eb05	JMP 0x004ccad2
004ccacd	6a00	PUSH 0x0
004ccacf	ff7510	PUSH dword ptr [EBP + 0x10]
004ccad2	ff750c	PUSH dword ptr [EBP + 0xc]
004ccad5	ff7508	PUSH dword ptr [EBP + 0x8]
004ccad8	e808000000	CALL 0x004ccae5
004ccadd	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004ccae0	83c410	ADD ESP,0x10
004ccae3	5d	POP EBP
004ccae4	c3	RET
