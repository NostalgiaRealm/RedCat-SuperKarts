/*
 * FUN_004239c4 at 004239c4
 * undefined FUN_004239c4(void)
 * Address ranges: 004239c4-004239e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004239c4(int *param_1,WPARAM param_2)

{
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  lParam = 0;
  Msg = 0xc5;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,param_2,lParam);
  return;
}

