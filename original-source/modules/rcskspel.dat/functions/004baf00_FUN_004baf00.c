/*
 * FUN_004baf00 at 004baf00
 * undefined FUN_004baf00(void)
 * Address ranges: 004baf00-004baf76
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004baf00(void)

{
  int iVar1;
  tagMSG local_1c;
  
  iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if (local_1c.message == 0x12) {
      if (DAT_006abae8 == 0) {
        return 1;
      }
      (*DAT_006abad4)();
    }
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
    iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  } while( true );
}

