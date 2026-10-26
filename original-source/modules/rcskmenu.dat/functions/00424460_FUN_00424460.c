/*
 * FUN_00424460 at 00424460
 * undefined FUN_00424460(void)
 * Address ranges: 00424460-0042447e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424460(int param_1,WPARAM param_2)

{
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  lParam = 0;
  Msg = 0x144;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  SendMessageA(hWnd,Msg,param_2,lParam);
  return;
}

