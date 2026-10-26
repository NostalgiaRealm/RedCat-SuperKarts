/*
 * FUN_00465c14 at 00465c14
 * undefined __register FUN_00465c14(int param_1, WPARAM param_2, undefined * param_3)
 * Address ranges: 00465c14-00465ce5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465c14(int param_1,WPARAM param_2,undefined *param_3)

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
  undefined *local_38;
  undefined1 local_34;
  WPARAM local_30;
  undefined1 local_2c;
  byte *local_28;
  undefined4 *local_24;
  uint local_20 [3];
  undefined *local_14;
  undefined4 local_c;
  
  puStack_48 = &stack0xfffffffc;
  local_24 = (undefined4 *)0x0;
  local_28 = (byte *)0x0;
  puStack_4c = &LAB_00465ce6;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  uVar1 = FUN_0043fc2c(*(int *)(param_1 + 0xc));
  local_20[0] = *(uint *)(&DAT_0047c3a4 + (uVar1 & 0x7f) * 4) | 3;
  local_14 = FUN_00403f94(param_3);
  local_c = (**(code **)(**(int **)(param_1 + 0xc) + 0xbc))(*(int **)(param_1 + 0xc),param_2);
  lParam = local_20;
  Msg = 0x1306;
  wParam = param_2;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar2 = SendMessageA(hWnd,Msg,wParam,(LPARAM)lParam);
  if (LVar2 == 0) {
    ppuVar3 = &local_24;
    FUN_00405438((undefined4 *)PTR_PTR_0047c904,(int *)&local_28);
    local_34 = 0xb;
    local_2c = 0;
    local_38 = param_3;
    local_30 = param_2;
    FUN_00408a5c(local_28,&local_38,1,(int *)ppuVar3);
    FUN_0046593c(local_24);
  }
  FUN_004666d8(*(int **)(param_1 + 0xc));
  *in_FS_OFFSET = uStack_50;
  puStack_48 = &LAB_00465ced;
  puStack_4c = (undefined1 *)0x465ce5;
  FUN_00403b74((int *)&local_28,2);
  return;
}

