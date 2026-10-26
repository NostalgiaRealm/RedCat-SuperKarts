; 004bce63 std::basic_streambuf<char,std::char_traits<char>_>::_Gninc
004bce63	8b412c	MOV EAX,dword ptr [ECX + 0x2c]
004bce66	ff08	DEC dword ptr [EAX]
004bce68	8b491c	MOV ECX,dword ptr [ECX + 0x1c]
004bce6b	8b01	MOV EAX,dword ptr [ECX]
004bce6d	8d5001	LEA EDX,[EAX + 0x1]
004bce70	8911	MOV dword ptr [ECX],EDX
004bce72	c3	RET
