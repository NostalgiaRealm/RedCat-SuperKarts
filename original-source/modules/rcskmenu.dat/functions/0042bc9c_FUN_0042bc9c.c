/*
 * FUN_0042bc9c at 0042bc9c
 * undefined FUN_0042bc9c(void)
 * Address ranges: 0042bc9c-0042bcd9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bc9c(int param_1,int param_2,char *param_3,char *param_4)

{
  FUN_00414bf4(param_1,param_2,param_3,param_4);
  if (*(int *)(param_1 + 0x238) != 0) {
    (**(code **)(**(int **)(param_1 + 0x238) + 0x2c))
              (*(int **)(param_1 + 0x238),param_2,param_3,param_4);
  }
  return;
}

