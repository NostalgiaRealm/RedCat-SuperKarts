/*
 * FUN_004418a0 at 004418a0
 * undefined FUN_004418a0(void)
 * Address ranges: 004418a0-004418d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004418a0(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  *(undefined4 *)(param_1 + 0x58) = 1;
  if (*(int *)(param_1 + 0x5c) == 1) {
    *(undefined4 *)(param_1 + 0x58) = 0;
    (**(code **)(**(int **)(param_1 + 0x54) + 0xc))(*(int **)(param_1 + 0x54),param_1);
  }
  return;
}

