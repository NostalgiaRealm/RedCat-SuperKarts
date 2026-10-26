/*
 * FUN_00465a60 at 00465a60
 * undefined FUN_00465a60(void)
 * Address ranges: 00465a60-00465b47
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465a60(int param_1,WPARAM param_2,int *param_3)

{
  uint uVar1;
  HWND hWnd;
  LRESULT LVar2;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  uint *lParam;
  undefined4 **ppuVar3;
  undefined4 uStack_1048;
  undefined1 *puStack_1044;
  undefined1 *puStack_1040;
  WPARAM WStack_1030;
  undefined1 uStack_102c;
  byte *pbStack_1028;
  undefined4 *puStack_1024;
  char acStack_1020 [28];
  int iStack_1004;
  uint auStack_20 [3];
  char *pcStack_14;
  undefined4 uStack_10;
  
  puStack_1040 = &stack0xfffffffc;
  puStack_1024 = (undefined4 *)0x0;
  pbStack_1028 = (byte *)0x0;
  puStack_1044 = &LAB_00465b48;
  uStack_1048 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1048;
  iStack_1004 = param_1;
  uVar1 = FUN_0043fc2c(*(int *)(param_1 + 0xc));
  auStack_20[0] = *(uint *)(&DAT_0047c39c + (uVar1 & 0x7f) * 4) | 1;
  pcStack_14 = acStack_1020;
  uStack_10 = 0x1000;
  lParam = auStack_20;
  Msg = 0x1305;
  wParam = param_2;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar2 = SendMessageA(hWnd,Msg,wParam,(LPARAM)lParam);
  if (LVar2 == 0) {
    ppuVar3 = &puStack_1024;
    FUN_00405438((undefined4 *)PTR_PTR_0047c7f0,(int *)&pbStack_1028);
    uStack_102c = 0;
    WStack_1030 = param_2;
    FUN_00408a5c(pbStack_1028,&WStack_1030,0,(int *)ppuVar3);
    FUN_0046593c(puStack_1024);
  }
  FUN_00403d80(param_3,acStack_1020,0x1000);
  *in_FS_OFFSET = uStack_1048;
  puStack_1040 = &LAB_00465b4f;
  puStack_1044 = (undefined1 *)0x465b47;
  FUN_00403b74((int *)&pbStack_1028,2);
  return;
}

