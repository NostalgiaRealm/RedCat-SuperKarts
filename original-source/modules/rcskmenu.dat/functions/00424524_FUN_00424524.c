/*
 * FUN_00424524 at 00424524
 * undefined FUN_00424524(void)
 * Address ranges: 00424524-00424549
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424524(int param_1,undefined *param_2)

{
  undefined *lParam;
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  
  lParam = FUN_00403f94(param_2);
  wParam = 0xffffffff;
  Msg = 0x158;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  SendMessageA(hWnd,Msg,wParam,(LPARAM)lParam);
  return;
}

