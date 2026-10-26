; 004bcb92 FUN_004bcb92
004bcb92	56	PUSH ESI
004bcb93	8bf1	MOV ESI,ECX
004bcb95	8b461c	MOV EAX,dword ptr [ESI + 0x1c]
004bcb98	8b00	MOV EAX,dword ptr [EAX]
004bcb9a	85c0	TEST EAX,EAX
004bcb9c	7410	JZ 0x004bcbae
004bcb9e	8b4e2c	MOV ECX,dword ptr [ESI + 0x2c]
004bcba1	8b09	MOV ECX,dword ptr [ECX]
004bcba3	03c8	ADD ECX,EAX
004bcba5	3bc1	CMP EAX,ECX
004bcba7	7305	JNC 0x004bcbae
004bcba9	0fb600	MOVZX EAX,byte ptr [EAX]
004bcbac	5e	POP ESI
004bcbad	c3	RET
004bcbae	57	PUSH EDI
004bcbaf	8b3e	MOV EDI,dword ptr [ESI]
004bcbb1	8bce	MOV ECX,ESI
004bcbb3	ff5714	CALL dword ptr [EDI + 0x14]
004bcbb6	50	PUSH EAX
004bcbb7	8bce	MOV ECX,ESI
004bcbb9	ff5708	CALL dword ptr [EDI + 0x8]
004bcbbc	5f	POP EDI
004bcbbd	5e	POP ESI
004bcbbe	c3	RET
