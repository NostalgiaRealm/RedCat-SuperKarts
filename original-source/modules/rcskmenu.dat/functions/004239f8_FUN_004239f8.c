/*
 * FUN_004239f8 at 004239f8
 * undefined __register FUN_004239f8(int * param_1, char param_2)
 * Address ranges: 004239f8-00423a18
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004239f8(int *param_1,char param_2)

{
  if (param_2 != (char)param_1[0x7d]) {
    *(char *)(param_1 + 0x7d) = param_2;
    FUN_00423ff0(param_1);
    FUN_00442cd4((int)param_1);
  }
  return;
}

