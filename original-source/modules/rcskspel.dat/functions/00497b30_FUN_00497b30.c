/*
 * FUN_00497b30 at 00497b30
 * undefined FUN_00497b30(void)
 * Address ranges: 00497b30-00497bbd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_00497b30(int param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5,int *param_6)

{
  *param_3 = param_1 - param_2;
  *param_4 = param_1 + param_2;
  if (*param_3 < 0) {
    *param_5 = 0;
    *param_6 = *param_4 % DAT_00680220;
    *param_3 = *param_3 + DAT_00680220 + -1;
    *param_4 = DAT_00680220 + -1;
    return 1;
  }
  if (DAT_00680220 + -1 < param_1 + param_2) {
    *param_5 = 0;
    *param_6 = *param_4 % DAT_00680220;
    *param_4 = DAT_00680220 + -1;
    return 1;
  }
  return 0;
}

