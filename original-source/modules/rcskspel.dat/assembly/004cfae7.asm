; 004cfae7 Unwind@004cfae7
004cfae7	8b45cc	MOV EAX,dword ptr [EBP + -0x34]
004cfaea	83e002	AND EAX,0x2
004cfaed	85c0	TEST EAX,EAX
004cfaef	0f8408000000	JZ 0x004cfafd
004cfaf5	8d4dd4	LEA ECX,[EBP + -0x2c]
004cfaf8	e9b3b9f3ff	JMP 0x0040b4b0
004cfafd	c3	RET
