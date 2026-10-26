/*
 * FUN_00465cf4 at 00465cf4
 * undefined FUN_00465cf4(void)
 * Address ranges: 00465cf4-00465d83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465cf4(int param_1,WPARAM param_2,undefined4 param_3)

{
  HWND hWnd;
  LRESULT LVar1;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  undefined4 *lParam;
  undefined4 **ppuVar2;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  WPARAM WStack_30;
  undefined1 uStack_2c;
  byte *pbStack_28;
  undefined4 *puStack_24;
  undefined4 auStack_20 [6];
  undefined4 uStack_8;
  
  puStack_3c = &stack0xfffffffc;
  puStack_24 = (undefined4 *)0x0;
  pbStack_28 = (byte *)0x0;
  puStack_40 = &LAB_00465d84;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  auStack_20[0] = 8;
  lParam = auStack_20;
  Msg = 0x1306;
  wParam = param_2;
  uStack_8 = param_3;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar1 = SendMessageA(hWnd,Msg,wParam,(LPARAM)lParam);
  if (LVar1 == 0) {
    ppuVar2 = &puStack_24;
    FUN_00405438((undefined4 *)PTR_PTR_0047c624,(int *)&pbStack_28);
    uStack_2c = 0;
    WStack_30 = param_2;
    FUN_00408a5c(pbStack_28,&WStack_30,0,(int *)ppuVar2);
    FUN_0046593c(puStack_24);
  }
  *in_FS_OFFSET = uStack_44;
  puStack_3c = &LAB_00465d8b;
  puStack_40 = (undefined1 *)0x465d83;
  FUN_00403b74((int *)&pbStack_28,2);
  return;
}

