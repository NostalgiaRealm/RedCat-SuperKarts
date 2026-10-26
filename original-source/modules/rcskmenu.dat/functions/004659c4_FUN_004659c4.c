/*
 * FUN_004659c4 at 004659c4
 * undefined __register FUN_004659c4(int param_1, WPARAM param_2)
 * Address ranges: 004659c4-00465a4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004659c4(int param_1,WPARAM param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  undefined4 *in_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  undefined4 **ppuVar2;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  WPARAM local_14;
  undefined1 local_10;
  byte *local_c;
  undefined4 *local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (byte *)0x0;
  puStack_24 = &LAB_00465a50;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  lParam = 0;
  Msg = 0x1308;
  wParam = param_2;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  LVar1 = SendMessageA(hWnd,Msg,wParam,lParam);
  if (LVar1 == 0) {
    ppuVar2 = &local_8;
    FUN_00405438((undefined4 *)PTR_PTR_0047c844,(int *)&local_c);
    local_10 = 0;
    local_14 = param_2;
    FUN_00408a5c(local_c,&local_14,0,(int *)ppuVar2);
    FUN_0046593c(local_8);
  }
  FUN_004666d8(*(int **)(param_1 + 0xc));
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00465a57;
  puStack_24 = (undefined1 *)0x465a4f;
  FUN_00403b74((int *)&local_c,2);
  return;
}

