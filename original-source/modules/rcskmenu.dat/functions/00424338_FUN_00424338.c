/*
 * FUN_00424338 at 00424338
 * undefined FUN_00424338(void)
 * Address ranges: 00424338-00424359
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424338(int param_1,WPARAM param_2,LPARAM param_3)

{
  HWND hWnd;
  UINT Msg;
  
  Msg = 0x151;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  SendMessageA(hWnd,Msg,param_2,param_3);
  return;
}

