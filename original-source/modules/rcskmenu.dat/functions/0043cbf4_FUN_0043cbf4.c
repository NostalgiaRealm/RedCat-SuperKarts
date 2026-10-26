/*
 * FUN_0043cbf4 at 0043cbf4
 * HWND __register FUN_0043cbf4(void)
 * Address ranges: 0043cbf4-0043cc19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HWND FUN_0043cbf4(void)

{
  HWND hWnd;
  HWND pHVar1;
  HWND pHVar2;
  int in_stack_00000004;
  
  pHVar2 = (HWND)FUN_00445724(*(int **)(in_stack_00000004 + -4));
  pHVar1 = pHVar2;
  while (hWnd = pHVar2, hWnd != (HWND)0x0) {
    pHVar2 = GetParent(hWnd);
    pHVar1 = hWnd;
  }
  return pHVar1;
}

