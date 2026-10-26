; 004a19e0 FUN_004a19e0
004a19e0	8b44240c	MOV EAX,dword ptr [ESP + 0xc]
004a19e4	8b4c2408	MOV ECX,dword ptr [ESP + 0x8]
004a19e8	8b542404	MOV EDX,dword ptr [ESP + 0x4]
004a19ec	d94020	FLD float ptr [EAX + 0x20]
004a19ef	d84908	FMUL float ptr [ECX + 0x8]
004a19f2	d94010	FLD float ptr [EAX + 0x10]
004a19f5	d84904	FMUL float ptr [ECX + 0x4]
004a19f8	dec1	FADDP
004a19fa	d901	FLD float ptr [ECX]
004a19fc	d808	FMUL float ptr [EAX]
004a19fe	dec1	FADDP
004a1a00	d84030	FADD float ptr [EAX + 0x30]
004a1a03	d91a	FSTP float ptr [EDX]
004a1a05	d94024	FLD float ptr [EAX + 0x24]
004a1a08	d84908	FMUL float ptr [ECX + 0x8]
004a1a0b	d94014	FLD float ptr [EAX + 0x14]
004a1a0e	d84904	FMUL float ptr [ECX + 0x4]
004a1a11	dec1	FADDP
004a1a13	d94004	FLD float ptr [EAX + 0x4]
004a1a16	d809	FMUL float ptr [ECX]
004a1a18	dec1	FADDP
004a1a1a	d84034	FADD float ptr [EAX + 0x34]
004a1a1d	d95a04	FSTP float ptr [EDX + 0x4]
004a1a20	d94028	FLD float ptr [EAX + 0x28]
004a1a23	d84908	FMUL float ptr [ECX + 0x8]
004a1a26	d94018	FLD float ptr [EAX + 0x18]
004a1a29	d84904	FMUL float ptr [ECX + 0x4]
004a1a2c	dec1	FADDP
004a1a2e	d94008	FLD float ptr [EAX + 0x8]
004a1a31	d809	FMUL float ptr [ECX]
004a1a33	dec1	FADDP
004a1a35	d84038	FADD float ptr [EAX + 0x38]
004a1a38	d95a08	FSTP float ptr [EDX + 0x8]
004a1a3b	c3	RET
