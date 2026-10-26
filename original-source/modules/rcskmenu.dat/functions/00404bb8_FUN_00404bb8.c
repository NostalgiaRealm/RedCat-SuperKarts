/*
 * FUN_00404bb8 at 00404bb8
 * undefined __register FUN_00404bb8(int * param_1, VARIANTARG * param_2)
 * Address ranges: 00404bb8-00404bf0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404bb8(int *param_1,VARIANTARG *param_2)

{
  _union_2683 local_14;
  
  if ((param_2->n1).n2.vt == 0x100) {
    FUN_00403ba4(param_1,*(undefined4 **)((int)&param_2->n1 + 8));
    return;
  }
  local_14.n2.vt = 0;
  FUN_00404ac4((VARIANT *)&local_14.n2,param_2,0x100);
  FUN_00403b50(param_1);
  *param_1 = local_14._8_4_;
  return;
}

