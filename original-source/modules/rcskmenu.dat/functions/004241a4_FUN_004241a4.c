/*
 * FUN_004241a4 at 004241a4
 * undefined __register FUN_004241a4(int * param_1)
 * Address ranges: 004241a4-004241c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004241a4(int *param_1)

{
  FUN_00444d24(param_1);
  if (((*(byte *)((int)param_1 + 0x41) & 2) != 0) &&
     (((*(byte *)(param_1 + 8) & 0x10) == 0 || ((*(byte *)(param_1 + 8) & 1) == 0)))) {
    FUN_0042402c(param_1);
  }
  return;
}

