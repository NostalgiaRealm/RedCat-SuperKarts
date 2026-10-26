; 004cfaaf Unwind@004cfaaf
004cfaaf	8b45d0	MOV EAX,dword ptr [EBP + -0x30]
004cfab2	83e002	AND EAX,0x2
004cfab5	85c0	TEST EAX,EAX
004cfab7	0f8408000000	JZ 0x004cfac5
004cfabd	8d4dd4	LEA ECX,[EBP + -0x2c]
004cfac0	e9ebb9f3ff	JMP 0x0040b4b0
004cfac5	c3	RET
