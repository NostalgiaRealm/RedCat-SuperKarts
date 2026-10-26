/*
 * FUN_0042bc64 at 0042bc64
 * undefined FUN_0042bc64(void)
 * Address ranges: 0042bc64-0042bc98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bc64(int *param_1,int *param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  
  if ((param_2 != (int *)param_1[9]) && (param_1 != param_2)) {
    if ((int *)param_1[9] == (int *)0x0) {
      FUN_00442c8c(param_1);
      param_3 = extraout_ECX;
    }
    FUN_0043f518(param_1,param_2,param_3);
    if (param_1[9] == 0) {
      FUN_00442e24(param_1);
    }
  }
  return;
}

