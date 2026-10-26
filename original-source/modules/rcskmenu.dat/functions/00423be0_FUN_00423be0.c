/*
 * FUN_00423be0 at 00423be0
 * undefined FUN_00423be0(void)
 * Address ranges: 00423be0-00423bfc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423be0(int *param_1,WPARAM param_2)

{
  HWND hWnd;
  UINT Msg;
  WPARAM lParam;
  
  Msg = 0xb1;
  lParam = param_2;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,param_2,lParam);
  return;
}

