/*
 * FUN_004457cc at 004457cc
 * undefined FUN_004457cc(void)
 * Address ranges: 004457cc-004457eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004457cc(int *param_1,LPPOINT param_2)

{
  HWND hWnd;
  
  param_2->x = 0;
  param_2->y = 0;
  hWnd = (HWND)FUN_00445724(param_1);
  ClientToScreen(hWnd,param_2);
  return;
}

