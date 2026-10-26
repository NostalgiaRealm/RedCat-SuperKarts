/*
 * FUN_004bb000 at 004bb000
 * undefined FUN_004bb000(void)
 * Address ranges: 004bb000-004bb04e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bb000(void)

{
  BOOL BVar1;
  tagMSG local_1c;
  
  BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    if (local_1c.message == 0x12) {
      FUN_004c025c(0);
    }
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
    return 0;
  }
  FUN_004ba540();
  return 0;
}

