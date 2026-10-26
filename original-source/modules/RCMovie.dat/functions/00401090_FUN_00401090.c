/*
 * FUN_00401090 at 00401090
 * undefined4 __stdcall FUN_00401090(void)
 * Address ranges: 00401090-004010e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401090(void)

{
  BOOL BVar1;
  tagMSG local_1c;
  
  BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  if (BVar1 == 0) {
    return 0;
  }
  do {
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
    BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  } while (BVar1 != 0);
  return 0;
}

