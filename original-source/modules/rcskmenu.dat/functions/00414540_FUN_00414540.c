/*
 * FUN_00414540 at 00414540
 * undefined FUN_00414540(void)
 * Address ranges: 00414540-00414555
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414540(int param_1,undefined4 param_2)

{
  if (*(short *)(param_1 + 0x4a) != 0) {
    (**(code **)(param_1 + 0x48))(*(undefined4 *)(param_1 + 0x4c),param_1,param_2);
  }
  return;
}

