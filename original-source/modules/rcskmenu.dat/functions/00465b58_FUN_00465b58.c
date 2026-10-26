/*
 * FUN_00465b58 at 00465b58
 * undefined FUN_00465b58(void)
 * Address ranges: 00465b58-00465b73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465b58(int param_1)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  lParam = 0;
  wParam = 0;
  Msg = 0x1304;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  SendMessageA(hWnd,Msg,wParam,lParam);
  return;
}

