/*
 * FUN_00465954 at 00465954
 * undefined __register FUN_00465954(int param_1)
 * Address ranges: 00465954-004659b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465954(int param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined4 *local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_14 = &LAB_004659b8;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  lParam = 0;
  wParam = 0;
  Msg = 0x1309;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar1 = SendMessageA(hWnd,Msg,wParam,lParam);
  if (LVar1 == 0) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c870,(int *)&local_8);
    FUN_0046593c(local_8);
  }
  FUN_004666d8(*(int **)(param_1 + 0xc));
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_004659bf;
  puStack_14 = (undefined1 *)0x4659b7;
  FUN_00403b50((int *)&local_8);
  return;
}

