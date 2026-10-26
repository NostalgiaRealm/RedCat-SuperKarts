/*
 * FUN_004c47c2 at 004c47c2
 * undefined FUN_004c47c2(void)
 * Address ranges: 004c47c2-004c47e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_004c47c2(char *param_1,int param_2)

{
  *param_1 = (char)(param_2 / 10) + '0';
  param_1[1] = (char)(param_2 % 10) + '0';
  return param_1 + 2;
}

