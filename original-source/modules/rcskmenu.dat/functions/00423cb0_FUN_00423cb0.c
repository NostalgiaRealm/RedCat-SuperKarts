/*
 * FUN_00423cb0 at 00423cb0
 * undefined __register FUN_00423cb0(int * param_1)
 * Address ranges: 00423cb0-00423cca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423cb0(int *param_1)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  lParam = -1;
  wParam = 0;
  Msg = 0xb1;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,wParam,lParam);
  return;
}

