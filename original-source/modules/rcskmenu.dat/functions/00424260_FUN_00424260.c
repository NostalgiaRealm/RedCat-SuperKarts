/*
 * FUN_00424260 at 00424260
 * undefined __register FUN_00424260(int param_1)
 * Address ranges: 00424260-0042427b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424260(int param_1)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  lParam = 0;
  wParam = 0;
  Msg = 0x146;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  SendMessageA(hWnd,Msg,wParam,lParam);
  return;
}

