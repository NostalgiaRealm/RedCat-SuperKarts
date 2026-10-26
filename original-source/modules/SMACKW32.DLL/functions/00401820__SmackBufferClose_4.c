/*
 * _SmackBufferClose@4 at 00401820
 * undefined __stdcall _SmackBufferClose@4(int param_1)
 * Address ranges: 00401820-00401907
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackBufferClose_4(int param_1)

{
                    /* 0x1820  6  _SmackBufferClose@4 */
  if (param_1 == 0) {
    return;
  }
  switch(*(undefined4 *)(param_1 + 8)) {
  case 1:
    goto LAB_0040186a;
  case 2:
LAB_0040186a:
    FUN_0040650f();
    if (*(HWND *)(param_1 + 0x470) != (HWND)0x0) {
      ShowWindow(*(HWND *)(param_1 + 0x470),0);
      SendMessageA(*(HWND *)(param_1 + 0x470),0x402,0,0);
    }
    break;
  case 3:
    FUN_0040650f();
    break;
  case 4:
    if (*(int *)(param_1 + 0x450) != 0) {
      SelectObject(*(HDC *)(param_1 + 0x45c),*(HGDIOBJ *)(param_1 + 0x454));
      DeleteObject(*(HGDIOBJ *)(param_1 + 0x450));
      if (*(HDC *)(param_1 + 0x45c) != (HDC)0x0) {
        DeleteDC(*(HDC *)(param_1 + 0x45c));
      }
    }
  }
  if (*(HGDIOBJ *)(param_1 + 0x458) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x458));
  }
  FUN_0040650f();
  return;
}

