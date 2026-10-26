/*
 * FUN_0043e07c at 0043e07c
 * HANDLE __register FUN_0043e07c(POINT * param_1)
 * Address ranges: 0043e07c-0043e0ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HANDLE FUN_0043e07c(POINT *param_1)

{
  HWND hWnd;
  HANDLE pvVar1;
  
  hWnd = WindowFromPoint(*param_1);
  pvVar1 = (HANDLE)0x0;
  while ((hWnd != (HWND)0x0 && (pvVar1 = FUN_0043c864(hWnd), pvVar1 == (HANDLE)0x0))) {
    hWnd = GetParent(hWnd);
  }
  return pvVar1;
}

