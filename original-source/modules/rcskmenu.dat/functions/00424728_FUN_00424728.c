/*
 * FUN_00424728 at 00424728
 * undefined __register FUN_00424728(int * param_1)
 * Address ranges: 00424728-00424742
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424728(int *param_1)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  lParam = 0;
  wParam = 0;
  Msg = 0x147;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,wParam,lParam);
  return;
}

