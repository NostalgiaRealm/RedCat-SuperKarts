/*
 * FUN_00469938 at 00469938
 * undefined FUN_00469938(void)
 * Address ranges: 00469938-00469973
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00469938(uint param_1,undefined4 *param_2)

{
  if (9 < param_1) {
    FUN_00403b34("Assertion failure");
  }
  *param_2 = *(undefined4 *)(param_1 * 6 + 0x47c414);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)(param_1 * 6 + 0x47c418);
  return;
}

