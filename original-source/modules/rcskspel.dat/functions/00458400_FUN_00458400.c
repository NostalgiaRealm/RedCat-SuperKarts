/*
 * FUN_00458400 at 00458400
 * undefined FUN_00458400(void)
 * Address ranges: 00458400-00458419
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00458400(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  return;
}

