/*
 * FUN_00423c30 at 00423c30
 * undefined FUN_00423c30(void)
 * Address ranges: 00423c30-00423c92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423c30(int *param_1,int param_2)

{
  HWND pHVar1;
  UINT UVar2;
  WPARAM *wParam;
  WPARAM wParam_00;
  int *lParam;
  LPARAM lParam_00;
  WPARAM WStack_10;
  int iStack_c;
  
  wParam = &WStack_10;
  lParam = &iStack_c;
  UVar2 = 0xb0;
  pHVar1 = (HWND)FUN_00445724(param_1);
  SendMessageA(pHVar1,UVar2,(WPARAM)wParam,(LPARAM)lParam);
  param_2 = param_2 + WStack_10;
  UVar2 = 0xb1;
  iStack_c = param_2;
  pHVar1 = (HWND)FUN_00445724(param_1);
  SendMessageA(pHVar1,UVar2,WStack_10,param_2);
  lParam_00 = 0;
  wParam_00 = 0;
  UVar2 = 0xb7;
  pHVar1 = (HWND)FUN_00445724(param_1);
  SendMessageA(pHVar1,UVar2,wParam_00,lParam_00);
  return;
}

