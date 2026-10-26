/*
 * FUN_0040a9d3 at 0040a9d3
 * undefined4 __stdcall FUN_0040a9d3(void)
 * Address ranges: 0040a9d3-0040aa1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040a9d3(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,1);
  if (BVar1 == 0) {
    FUN_00405614();
  }
  else {
    if (local_20.message == 0x12) {
      FUN_0041f6c8(0);
    }
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  }
  return 0;
}

