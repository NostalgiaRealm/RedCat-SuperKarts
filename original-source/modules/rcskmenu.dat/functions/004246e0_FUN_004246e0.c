/*
 * FUN_004246e0 at 004246e0
 * undefined __register FUN_004246e0(int * param_1, byte param_2)
 * Address ranges: 004246e0-00424724
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004246e0(int *param_1,byte param_2)

{
  uint wParam;
  HWND pHVar1;
  UINT Msg;
  RECT *lpRect;
  LPARAM lParam;
  BOOL bErase;
  RECT RStack_18;
  
  lParam = 0;
  wParam = (uint)param_2;
  Msg = 0x14f;
  pHVar1 = (HWND)FUN_00445724(param_1);
  SendMessageA(pHVar1,Msg,wParam,lParam);
  lpRect = &RStack_18;
  (**(code **)(*param_1 + 0x40))(param_1,&RStack_18);
  bErase = -1;
  pHVar1 = (HWND)FUN_00445724(param_1);
  InvalidateRect(pHVar1,lpRect,bErase);
  return;
}

