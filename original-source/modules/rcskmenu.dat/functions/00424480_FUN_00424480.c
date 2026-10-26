/*
 * FUN_00424480 at 00424480
 * undefined __register FUN_00424480(int param_1)
 * Address ranges: 00424480-004244e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424480(int param_1)

{
  HWND hWnd;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  uint *local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  puStack_14 = &LAB_004244e4;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  FUN_0043f64c(*(int *)(param_1 + 0xc),(int *)&local_8);
  lParam = 0;
  wParam = 0;
  Msg = 0x14b;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  SendMessageA(hWnd,Msg,wParam,lParam);
  FUN_0043f67c(*(int *)(param_1 + 0xc),local_8);
  (**(code **)(**(int **)(param_1 + 0xc) + 0x80))();
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_004244eb;
  puStack_14 = (undefined1 *)0x4244e3;
  FUN_00403b50((int *)&local_8);
  return;
}

