/*
 * FUN_0040486c at 0040486c
 * undefined __register FUN_0040486c(VARIANTARG * param_1)
 * Address ranges: 0040486c-004048ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040486c(VARIANTARG *param_1)

{
  ushort uVar1;
  
  uVar1 = (param_1->n1).n2.vt;
  if (((uVar1 & 0x4000) != 0) || (uVar1 < 8)) {
    (param_1->n1).n2.vt = 0;
    return;
  }
  if (uVar1 == 0x100) {
    (param_1->n1).n2.vt = 0;
    FUN_00403b50((int *)((int)&param_1->n1 + 8));
    return;
  }
  if (uVar1 == 0x101) {
                    /* WARNING: Could not recover jumptable at 0x0040488e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0047d3e8)();
    return;
  }
  VariantClear(param_1);
  return;
}

