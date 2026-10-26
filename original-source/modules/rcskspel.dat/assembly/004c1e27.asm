; 004c1e27 __trandisp2
004c1e27	807a0e05	CMP byte ptr [EDX + 0xe],0x5
004c1e2b	7511	JNZ 0x004c1e3e
004c1e2d	668b9d5cffffff	MOV BX,word ptr [EBP + 0xffffff5c]
004c1e34	80cf02	OR BH,0x2
004c1e37	80e7fe	AND BH,0xfe
004c1e3a	b33f	MOV BL,0x3f
004c1e3c	eb04	JMP 0x004c1e42
004c1e3e	66bb3f13	MOV BX,0x133f
004c1e42	66899d5effffff	MOV word ptr [EBP + 0xffffff5e],BX
004c1e49	d9ad5effffff	FLDCW word ptr [EBP + 0xffffff5e]
004c1e4f	bbcd2f5000	MOV EBX,0x502fcd
004c1e54	d9e5	FXAM
004c1e56	89956cffffff	MOV dword ptr [EBP + 0xffffff6c],EDX
004c1e5c	9bddbd60ffffff	FSTSW word ptr [EBP + 0xffffff60]
004c1e63	c68570ffffff00	MOV byte ptr [EBP + 0xffffff70],0x0
004c1e6a	d9c9	FXCH
004c1e6c	8a8d61ffffff	MOV CL,byte ptr [EBP + 0xffffff61]
004c1e72	d9e5	FXAM
004c1e74	9bddbd60ffffff	FSTSW word ptr [EBP + 0xffffff60]
004c1e7b	d9c9	FXCH
004c1e7d	8aad61ffffff	MOV CH,byte ptr [EBP + 0xffffff61]
004c1e83	d0e5	SHL CH,0x1
004c1e85	d0fd	SAR CH,0x1
004c1e87	d0c5	ROL CH,0x1
004c1e89	8ac5	MOV AL,CH
004c1e8b	240f	AND AL,0xf
004c1e8d	d7	XLAT EBX
004c1e8e	8ae0	MOV AH,AL
004c1e90	d0e1	SHL CL,0x1
004c1e92	d0f9	SAR CL,0x1
004c1e94	d0c1	ROL CL,0x1
004c1e96	8ac1	MOV AL,CL
004c1e98	240f	AND AL,0xf
004c1e9a	d7	XLAT EBX
004c1e9b	d0e4	SHL AH,0x1
004c1e9d	d0e4	SHL AH,0x1
004c1e9f	0ac4	OR AL,AH
004c1ea1	0fbec0	MOVSX EAX,AL
004c1ea4	81e104040000	AND ECX,0x404
004c1eaa	8bda	MOV EBX,EDX
004c1eac	03d8	ADD EBX,EAX
004c1eae	83c310	ADD EBX,0x10
004c1eb1	ff23	JMP dword ptr [EBX]
