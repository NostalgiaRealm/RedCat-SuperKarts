/*
 * FUN_00439a08 at 00439a08
 * undefined FUN_00439a08(void)
 * Address ranges: 00439a08-00439a1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439a08(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(short *)(param_1 + 0x42) != 0) {
    (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),param_1,param_2,param_3);
  }
  return;
}

