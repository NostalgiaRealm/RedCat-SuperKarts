/*
 * FUN_00423750 at 00423750
 * undefined FUN_00423750(void)
 * Address ranges: 00423750-00423769
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423750(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((char)param_2 != *(char *)((int)param_1 + 0x12d)) {
    *(char *)((int)param_1 + 0x12d) = (char)param_2;
    FUN_00403088(param_1,param_2,param_3);
  }
  return;
}

