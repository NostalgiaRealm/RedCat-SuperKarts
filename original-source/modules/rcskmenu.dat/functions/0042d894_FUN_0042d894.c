/*
 * FUN_0042d894 at 0042d894
 * undefined __register FUN_0042d894(int * param_1)
 * Address ranges: 0042d894-0042d8c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d894(int *param_1)

{
  FUN_0042d818(0xb001,(int *)param_1[0x82],param_1);
  if (*(short *)((int)param_1 + 0x28a) != 0) {
    (*(code *)param_1[0xa2])(param_1[0xa3],param_1);
  }
  return;
}

