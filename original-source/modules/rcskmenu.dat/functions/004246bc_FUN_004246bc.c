/*
 * FUN_004246bc at 004246bc
 * bool __register FUN_004246bc(int * param_1)
 * Address ranges: 004246bc-004246dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004246bc(int *param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  lParam = 0;
  wParam = 0;
  Msg = 0x157;
  hWnd = (HWND)FUN_00445724(param_1);
  LVar1 = SendMessageA(hWnd,Msg,wParam,lParam);
  return LVar1 != 0;
}

