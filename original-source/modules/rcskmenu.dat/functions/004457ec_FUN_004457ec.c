/*
 * FUN_004457ec at 004457ec
 * undefined __register FUN_004457ec(int * param_1, LPRECT param_2)
 * Address ranges: 004457ec-00445802
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004457ec(int *param_1,LPRECT param_2)

{
  HWND hWnd;
  
  hWnd = (HWND)FUN_00445724(param_1);
  GetClientRect(hWnd,param_2);
  return;
}

