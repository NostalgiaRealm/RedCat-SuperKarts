; 00479bbc TfrmIntro_playerNotify
00479bbc	8b90dc020000	MOV EDX,dword ptr [EAX + 0x2dc]
00479bc2	80baf002000000	CMP byte ptr [EDX + 0x2f0],0x0
00479bc9	7505	JNZ 0x00479bd0
00479bcb	e8484ffbff	CALL 0x0042eb18
00479bd0	c3	RET
