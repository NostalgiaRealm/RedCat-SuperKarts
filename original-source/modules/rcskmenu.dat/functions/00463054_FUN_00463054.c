/*
 * FUN_00463054 at 00463054
 * undefined FUN_00463054(void)
 * Address ranges: 00463054-00463083
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463054(int *param_1,int *param_2)

{
  FUN_004258a4(param_1,param_2);
  param_2[1] = param_2[1] | 0xb;
  if (((*(byte *)(param_1 + 8) & 0x10) == 0) && (*(char *)((int)param_1 + 0x213) != '\0')) {
    param_2[2] = param_2[2] | 0x20;
    param_2[1] = param_2[1] & 0xfdffffff;
  }
  return;
}

