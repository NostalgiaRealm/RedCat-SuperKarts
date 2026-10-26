/*
 * FUN_00423bbc at 00423bbc
 * undefined FUN_00423bbc(void)
 * Address ranges: 00423bbc-00423bde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00423bbc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  UINT Msg;
  undefined4 *wParam;
  LPARAM lParam;
  undefined4 uStack_8;
  
  wParam = &uStack_8;
  lParam = 0;
  Msg = 0xb0;
  uStack_8 = param_3;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,(WPARAM)wParam,lParam);
  return uStack_8;
}

