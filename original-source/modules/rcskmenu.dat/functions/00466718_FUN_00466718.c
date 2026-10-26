/*
 * FUN_00466718 at 00466718
 * undefined __register FUN_00466718(int * param_1)
 * Address ranges: 00466718-0046673e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466718(int *param_1)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  int lParam;
  
  lParam = param_1[0x85];
  wParam = 0;
  Msg = 0x1329;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,wParam,lParam);
  FUN_004666d8(param_1);
  return;
}

