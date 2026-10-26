/*
 * FUN_00404c34 at 00404c34
 * undefined __register FUN_00404c34(VARIANTARG * param_1, OLECHAR * param_2)
 * Address ranges: 00404c34-00404c67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404c34(VARIANTARG *param_1,OLECHAR *param_2)

{
  BSTR pOVar1;
  
  if (7 < (param_1->n1).n2.vt) {
    FUN_0040486c(param_1);
  }
  pOVar1 = (BSTR)0x0;
  if ((param_2 != (OLECHAR *)0x0) && (pOVar1 = (BSTR)0x0, *(uint *)(param_2 + -2) >> 1 != 0)) {
    pOVar1 = SysAllocStringLen(param_2,*(uint *)(param_2 + -2) >> 1);
    if (pOVar1 == (BSTR)0x0) {
      FUN_004027a0(1);
      return;
    }
  }
  (param_1->n1).n2.vt = 8;
  *(BSTR *)((int)&param_1->n1 + 8) = pOVar1;
  return;
}

