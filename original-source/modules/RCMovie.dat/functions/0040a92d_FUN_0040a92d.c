/*
 * FUN_0040a92d at 0040a92d
 * undefined4 __stdcall FUN_0040a92d(void)
 * Address ranges: 0040a92d-0040a97c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040a92d(void)

{
  tagMSG local_20;
  
  PeekMessageA(&local_20,(HWND)0x0,0,0,1);
  if (local_20.message == 0x12) {
    if (DAT_0043d53c == 0) {
      return 1;
    }
    (*DAT_0043d528)();
  }
  TranslateMessage(&local_20);
  DispatchMessageA(&local_20);
  return 0;
}

