/*
 * FUN_004243e0 at 004243e0
 * undefined FUN_004243e0(void)
 * Address ranges: 004243e0-00424452
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004243e0(int param_1,WPARAM param_2,undefined *param_3)

{
  undefined *lParam;
  HWND hWnd;
  LRESULT LVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined4 *puStack_8;
  
  puStack_18 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_1c = &LAB_00424453;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  lParam = FUN_00403f94(param_3);
  Msg = 0x14a;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar1 = SendMessageA(hWnd,Msg,param_2,(LPARAM)lParam);
  if (LVar1 < 0) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c6cc,(int *)&puStack_8);
    piVar2 = FUN_0040ac64((int *)&DAT_0040ddb0,'\x01',puStack_8);
    FUN_00403604(piVar2);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0042445a;
  puStack_1c = (undefined1 *)0x424452;
  FUN_00403b50((int *)&puStack_8);
  return;
}

