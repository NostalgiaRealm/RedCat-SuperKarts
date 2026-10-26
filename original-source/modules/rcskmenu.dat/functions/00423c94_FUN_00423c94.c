/*
 * FUN_00423c94 at 00423c94
 * undefined __register FUN_00423c94(int * param_1)
 * Address ranges: 00423c94-00423caa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423c94(int *param_1)

{
  HWND hWnd;
  LPCSTR lpString;
  
  lpString = "";
  hWnd = (HWND)FUN_00445724(param_1);
  SetWindowTextA(hWnd,lpString);
  return;
}

