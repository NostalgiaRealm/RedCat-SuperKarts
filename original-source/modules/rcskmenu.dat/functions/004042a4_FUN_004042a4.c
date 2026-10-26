/*
 * FUN_004042a4 at 004042a4
 * undefined __register FUN_004042a4(UINT param_1)
 * Address ranges: 004042a4-004042b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004042a4(UINT param_1)

{
  BSTR pOVar1;
  
  if (param_1 != 0) {
    pOVar1 = SysAllocStringLen((OLECHAR *)0x0,param_1);
    if (pOVar1 == (BSTR)0x0) {
      FUN_004027a0(1);
      return;
    }
  }
  return;
}

