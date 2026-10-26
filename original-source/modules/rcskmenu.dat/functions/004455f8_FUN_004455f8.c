/*
 * FUN_004455f8 at 004455f8
 * undefined FUN_004455f8(void)
 * Address ranges: 004455f8-00445613
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004455f8(int param_1)

{
  bool bVar1;
  
  bVar1 = FUN_00445a20(param_1);
  if (bVar1) {
    UpdateWindow(*(HWND *)(param_1 + 0x14c));
  }
  return;
}

