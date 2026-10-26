; 004c1dc0 __trandisp1
004c1dc0	807a0e05	CMP byte ptr [EDX + 0xe],0x5
004c1dc4	7511	JNZ 0x004c1dd7
004c1dc6	668b9d5cffffff	MOV BX,word ptr [EBP + 0xffffff5c]
004c1dcd	80cf02	OR BH,0x2
004c1dd0	80e7fe	AND BH,0xfe
004c1dd3	b33f	MOV BL,0x3f
004c1dd5	eb04	JMP 0x004c1ddb
004c1dd7	66bb3f13	MOV BX,0x133f
004c1ddb	66899d5effffff	MOV word ptr [EBP + 0xffffff5e],BX
004c1de2	d9ad5effffff	FLDCW word ptr [EBP + 0xffffff5e]
004c1de8	bbcd2f5000	MOV EBX,0x502fcd
004c1ded	d9e5	FXAM
004c1def	89956cffffff	MOV dword ptr [EBP + 0xffffff6c],EDX
004c1df5	9bddbd60ffffff	FSTSW word ptr [EBP + 0xffffff60]
004c1dfc	c68570ffffff00	MOV byte ptr [EBP + 0xffffff70],0x0
004c1e03	9b	WAIT
004c1e04	8a8d61ffffff	MOV CL,byte ptr [EBP + 0xffffff61]
004c1e0a	d0e1	SHL CL,0x1
004c1e0c	d0f9	SAR CL,0x1
004c1e0e	d0c1	ROL CL,0x1
004c1e10	8ac1	MOV AL,CL
004c1e12	240f	AND AL,0xf
004c1e14	d7	XLAT EBX
004c1e15	0fbec0	MOVSX EAX,AL
004c1e18	81e104040000	AND ECX,0x404
004c1e1e	8bda	MOV EBX,EDX
004c1e20	03d8	ADD EBX,EAX
004c1e22	83c310	ADD EBX,0x10
004c1e25	ff23	JMP dword ptr [EBX]
