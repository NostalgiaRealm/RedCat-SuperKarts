/*
 * FUN_00423c00 at 00423c00
 * undefined FUN_00423c00(void)
 * Address ranges: 00423c00-00423c2c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00423c00(int *param_1)

{
  HWND hWnd;
  UINT Msg;
  int *wParam;
  int *lParam;
  int iStack_c;
  int iStack_8;
  
  wParam = &iStack_c;
  lParam = &iStack_8;
  Msg = 0xb0;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,(WPARAM)wParam,(LPARAM)lParam);
  return iStack_8 - iStack_c;
}

