/*
 * FUN_004669c0 at 004669c0
 * undefined FUN_004669c0(void)
 * Address ranges: 004669c0-004669e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004669c0(int *param_1,UINT *param_2)

{
  HWND hWnd;
  UINT UVar1;
  UINT Msg;
  UINT wParam;
  
  UVar1 = param_2[2];
  wParam = param_2[1];
  Msg = *param_2;
  hWnd = (HWND)FUN_00445724(param_1);
  UVar1 = DefWindowProcA(hWnd,Msg,wParam,UVar1);
  param_2[3] = UVar1;
  return;
}

