/*
 * FUN_0043c864 at 0043c864
 * HANDLE __register FUN_0043c864(HWND param_1)
 * Address ranges: 0043c864-0043c87c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HANDLE FUN_0043c864(HWND param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = (HANDLE)0x0;
  if (param_1 != (HWND)0x0) {
    pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_0047d7b6);
  }
  return pvVar1;
}

