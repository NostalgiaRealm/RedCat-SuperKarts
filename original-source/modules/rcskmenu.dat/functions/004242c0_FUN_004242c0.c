/*
 * FUN_004242c0 at 004242c0
 * undefined FUN_004242c0(void)
 * Address ranges: 004242c0-00424325
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004242c0(int param_1,WPARAM param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  byte *pbStack_8;
  
  puStack_18 = &stack0xfffffffc;
  pbStack_8 = (byte *)0x0;
  puStack_1c = &LAB_00424326;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  lParam = 0;
  Msg = 0x150;
  wParam = param_2;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar1 = SendMessageA(hWnd,Msg,wParam,lParam);
  if (LVar1 == -1) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c8f0,(int *)&pbStack_8);
    FUN_004108b8(param_1,pbStack_8,param_2);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0042432d;
  puStack_1c = (undefined1 *)0x424325;
  FUN_00403b50((int *)&pbStack_8);
  return;
}

