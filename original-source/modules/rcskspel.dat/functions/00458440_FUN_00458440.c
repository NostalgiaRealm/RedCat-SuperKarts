/*
 * FUN_00458440 at 00458440
 * undefined FUN_00458440(void)
 * Address ranges: 00458440-00458459
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00458440(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = *param_2;
  *(undefined4 *)(param_1 + 0x20) = param_2[1];
  *(undefined4 *)(param_1 + 0x24) = param_2[2];
  return;
}

