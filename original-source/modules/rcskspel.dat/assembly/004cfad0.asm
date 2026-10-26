; 004cfad0 Unwind@004cfad0
004cfad0	8b45cc	MOV EAX,dword ptr [EBP + -0x34]
004cfad3	83e001	AND EAX,0x1
004cfad6	85c0	TEST EAX,EAX
004cfad8	0f8408000000	JZ 0x004cfae6
004cfade	8d4de4	LEA ECX,[EBP + -0x1c]
004cfae1	e9cab9f3ff	JMP 0x0040b4b0
004cfae6	c3	RET
