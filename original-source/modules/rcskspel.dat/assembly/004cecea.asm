; 004cecea Unwind@004cecea
004cecea	8b45cc	MOV EAX,dword ptr [EBP + -0x34]
004ceced	83e001	AND EAX,0x1
004cecf0	85c0	TEST EAX,EAX
004cecf2	0f8408000000	JZ 0x004ced00
004cecf8	8d4de4	LEA ECX,[EBP + -0x1c]
004cecfb	e9b0c7f3ff	JMP 0x0040b4b0
004ced00	c3	RET
