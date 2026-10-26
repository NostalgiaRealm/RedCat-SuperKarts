/*
 * FUN_0043d63c at 0043d63c
 * HWND __register FUN_0043d63c(POINT * param_1)
 * Address ranges: 0043d63c-0043d667
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HWND FUN_0043d63c(POINT *param_1)

{
  HWND hWnd;
  undefined4 uVar1;
  
  hWnd = WindowFromPoint(*param_1);
  while ((hWnd != (HWND)0x0 && (uVar1 = FUN_0043d618(hWnd), (char)uVar1 == '\0'))) {
    hWnd = GetParent(hWnd);
  }
  return hWnd;
}

