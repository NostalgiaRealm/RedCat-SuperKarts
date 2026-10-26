/*
 * FUN_004418e0 at 004418e0
 * undefined FUN_004418e0(void)
 * Address ranges: 004418e0-00441917
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004418e0(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x14) = *param_2;
  *(undefined4 *)(param_1 + 0x18) = param_2[1];
  *(undefined4 *)(param_1 + 0x1c) = param_2[2];
  *(undefined4 *)(param_1 + 0x58) = 1;
  if (*(int *)(param_1 + 0x5c) == 1) {
    *(undefined4 *)(param_1 + 0x58) = 0;
    (**(code **)(**(int **)(param_1 + 0x54) + 0xc))(*(int **)(param_1 + 0x54),param_1);
  }
  return;
}

