; 004bee72 __abnormal_termination
004bee72	33c0	XOR EAX,EAX
004bee74	648b0d00000000	MOV ECX,dword ptr FS:[0x0]
004bee7b	817904e8ed4b00	CMP dword ptr [ECX + 0x4],0x4bede8
004bee82	7510	JNZ 0x004bee94
004bee84	8b510c	MOV EDX,dword ptr [ECX + 0xc]
004bee87	8b520c	MOV EDX,dword ptr [EDX + 0xc]
004bee8a	395108	CMP dword ptr [ECX + 0x8],EDX
004bee8d	7505	JNZ 0x004bee94
004bee8f	b801000000	MOV EAX,0x1
004bee94	c3	RET
