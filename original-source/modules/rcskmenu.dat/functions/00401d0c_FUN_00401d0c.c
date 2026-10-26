/*
 * FUN_00401d0c at 00401d0c
 * undefined __register FUN_00401d0c(uint * param_1, uint param_2)
 * Address ranges: 00401d0c-00401d33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401d0c(uint *param_1,uint param_2)

{
  if (0xb < (int)param_2) {
    *param_1 = param_2 | 2;
    FUN_00401ce8((int)(param_1 + 1));
    return;
  }
  if (3 < (int)param_2) {
    *param_1 = param_2 | 0x80000002;
  }
  *(uint *)((int)param_1 + param_2) = *(uint *)((int)param_1 + param_2) & 0xfffffffe;
  return;
}

