/*
 * FUN_00411390 at 00411390
 * undefined FUN_00411390(void)
 * Address ranges: 00411390-004113a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411390(int param_1)

{
  if ((*(int *)(param_1 + 4) == 0) && (*(short *)(param_1 + 0x22) != 0)) {
    (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x24),param_1);
  }
  return;
}

