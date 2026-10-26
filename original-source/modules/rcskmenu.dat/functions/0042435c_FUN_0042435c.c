/*
 * FUN_0042435c at 0042435c
 * undefined FUN_0042435c(void)
 * Address ranges: 0042435c-004243ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042435c(int param_1,undefined *param_2)

{
  undefined *lParam;
  HWND hWnd;
  LRESULT LVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *puStack_8;
  
  puStack_14 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_18 = &LAB_004243cf;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  lParam = FUN_00403f94(param_2);
  wParam = 0;
  Msg = 0x143;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar1 = SendMessageA(hWnd,Msg,wParam,(LPARAM)lParam);
  if (LVar1 < 0) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c6cc,(int *)&puStack_8);
    piVar2 = FUN_0040ac64((int *)&DAT_0040ddb0,'\x01',puStack_8);
    FUN_00403604(piVar2);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_004243d6;
  puStack_18 = (undefined1 *)0x4243ce;
  FUN_00403b50((int *)&puStack_8);
  return;
}

