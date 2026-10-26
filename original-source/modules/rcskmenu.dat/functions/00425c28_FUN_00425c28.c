/*
 * FUN_00425c28 at 00425c28
 * undefined FUN_00425c28(void)
 * Address ranges: 00425c28-00425c50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00425c28(int *param_1)

{
  uint wParam;
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  FUN_00442914(param_1);
  lParam = 0;
  wParam = (uint)*(byte *)((int)param_1 + 0x1fa);
  Msg = 0xf1;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,wParam,lParam);
  return;
}

