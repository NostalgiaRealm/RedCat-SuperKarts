/*
 * FUN_00466230 at 00466230
 * undefined __register FUN_00466230(int * param_1)
 * Address ranges: 00466230-0046624a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466230(int *param_1)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  lParam = 0;
  wParam = 0;
  Msg = 0x130b;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,wParam,lParam);
  return;
}

