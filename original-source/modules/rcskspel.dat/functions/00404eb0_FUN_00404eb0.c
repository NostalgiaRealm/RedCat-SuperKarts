/*
 * FUN_00404eb0 at 00404eb0
 * undefined FUN_00404eb0(void)
 * Address ranges: 00404eb0-00404efa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00404eb0(int param_1,int param_2)

{
  if ((param_2 < param_1) && (param_1 - param_2 < DAT_00680220 / 2)) {
    return 1;
  }
  if ((param_1 < param_2) && (DAT_00680220 / 2 < param_2 - param_1)) {
    return 1;
  }
  return 0;
}

