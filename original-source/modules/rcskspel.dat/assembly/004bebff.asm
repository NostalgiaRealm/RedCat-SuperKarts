; 004bebff FUN_004bebff
004bebff	55	PUSH EBP
004bec00	8bec	MOV EBP,ESP
004bec02	fc	CLD
004bec03	8b450c	MOV EAX,dword ptr [EBP + 0xc]
004bec06	6a00	PUSH 0x0
004bec08	50	PUSH EAX
004bec09	ff7010	PUSH dword ptr [EAX + 0x10]
004bec0c	ff7008	PUSH dword ptr [EAX + 0x8]
004bec0f	6a00	PUSH 0x0
004bec11	ff7510	PUSH dword ptr [EBP + 0x10]
004bec14	ff700c	PUSH dword ptr [EAX + 0xc]
004bec17	ff7508	PUSH dword ptr [EBP + 0x8]
004bec1a	e809400000	CALL 0x004c2c28
004bec1f	83c420	ADD ESP,0x20
004bec22	5d	POP EBP
004bec23	c3	RET
