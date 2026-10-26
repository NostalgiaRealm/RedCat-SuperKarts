/*
 * FUN_0040a97d at 0040a97d
 * undefined4 __stdcall FUN_0040a97d(void)
 * Address ranges: 0040a97d-0040a9d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040a97d(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  do {
    BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
    if (local_20.message == 0x12) {
      if (DAT_0043d53c == 0) {
        return 1;
      }
      (*DAT_0043d528)();
    }
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  } while( true );
}

