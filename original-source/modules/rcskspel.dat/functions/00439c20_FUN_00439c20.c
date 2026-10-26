/*
 * FUN_00439c20 at 00439c20
 * undefined FUN_00439c20(void)
 * Address ranges: 00439c20-00439c6d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00439c20(int *param_1,int param_2)

{
  if (param_1[3] == *(int *)(param_2 + 0xc)) {
    return param_1[2] - *(int *)(param_2 + 8) >> 2;
  }
  return (*(int *)(param_2 + 4) - *(int *)(param_2 + 8) >> 2) +
         ((param_1[3] - *(int *)(param_2 + 0xc) >> 2) + 0x3fffff) * 0x400 +
         (param_1[2] - *param_1 >> 2);
}

