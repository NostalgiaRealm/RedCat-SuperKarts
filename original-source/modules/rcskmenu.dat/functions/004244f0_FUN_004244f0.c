/*
 * FUN_004244f0 at 004244f0
 * undefined FUN_004244f0(void)
 * Address ranges: 004244f0-00424521
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004244f0(int param_1,byte param_2)

{
  uint wParam;
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  lParam = 0;
  wParam = (param_2 ^ 1) & 0x7f;
  Msg = 0xb;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0xc));
  SendMessageA(hWnd,Msg,wParam,lParam);
  if (param_2 != 1) {
    FUN_0043fb28(*(int **)(param_1 + 0xc));
  }
  return;
}

