/*
 * FUN_00404aa4 at 00404aa4
 * undefined __register FUN_00404aa4(VARIANTARG * param_1, int param_2)
 * Address ranges: 00404aa4-00404ac3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404aa4(VARIANTARG *param_1,int param_2)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_004047d0(*(LPCSTR *)(param_2 + 8));
  FUN_0040486c(param_1);
  (param_1->n1).n2.vt = 8;
  *(BSTR *)((int)&param_1->n1 + 8) = pOVar1;
  return;
}

