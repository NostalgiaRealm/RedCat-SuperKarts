/*
 * FUN_00414fd0 at 00414fd0
 * undefined FUN_00414fd0(void)
 * Address ranges: 00414fd0-00414fe4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414fd0(int param_1)

{
  if (*(short *)(param_1 + 10) != 0) {
    (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  }
  return;
}

