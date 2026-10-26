/*
 * FUN_00465d94 at 00465d94
 * undefined FUN_00465d94(void)
 * Address ranges: 00465d94-00465e65
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465d94(int param_1,WPARAM param_2,undefined *param_3)

{
  uint uVar1;
  HWND hWnd;
  LRESULT LVar2;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  uint *lParam;
  undefined4 **ppuVar3;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  undefined *puStack_38;
  undefined1 uStack_34;
  WPARAM WStack_30;
  undefined1 uStack_2c;
  byte *pbStack_28;
  undefined4 *puStack_24;
  uint auStack_20 [3];
  undefined *puStack_14;
  undefined4 uStack_c;
  
  puStack_48 = &stack0xfffffffc;
  puStack_24 = (undefined4 *)0x0;
  pbStack_28 = (byte *)0x0;
  puStack_4c = &LAB_00465e66;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  uVar1 = FUN_0043fc2c(*(int *)(param_1 + 0xc));
  auStack_20[0] = *(uint *)(&DAT_0047c3ac + (uVar1 & 0x7f) * 4) | 3;
  puStack_14 = FUN_00403f94(param_3);
  uStack_c = (**(code **)(**(int **)(param_1 + 0xc) + 0xbc))(*(int **)(param_1 + 0xc),param_2);
  lParam = auStack_20;
  Msg = 0x1307;
  wParam = param_2;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar2 = SendMessageA(hWnd,Msg,wParam,(LPARAM)lParam);
  if (LVar2 < 0) {
    ppuVar3 = &puStack_24;
    FUN_00405438((undefined4 *)PTR_PTR_0047c904,(int *)&pbStack_28);
    uStack_34 = 0xb;
    uStack_2c = 0;
    puStack_38 = param_3;
    WStack_30 = param_2;
    FUN_00408a5c(pbStack_28,&puStack_38,1,(int *)ppuVar3);
    FUN_0046593c(puStack_24);
  }
  FUN_004666d8(*(int **)(param_1 + 0xc));
  *in_FS_OFFSET = uStack_50;
  puStack_48 = &LAB_00465e6d;
  puStack_4c = (undefined1 *)0x465e65;
  FUN_00403b74((int *)&pbStack_28,2);
  return;
}

