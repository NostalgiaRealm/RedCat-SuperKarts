/*
 * FUN_0044dea8 at 0044dea8
 * undefined FUN_0044dea8(void)
 * Address ranges: 0044dea8-0044deda
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044dea8(int *param_1,int param_2)

{
  int *piVar1;
  
  if ((char)param_1[2] == '\0') {
    piVar1 = (int *)(**(code **)*param_1)(param_1,param_2);
    FUN_00402eac(piVar1);
    (**(code **)(*param_1 + 4))(param_1,param_2,0);
  }
  FUN_0040f550((int *)param_1[1],param_2);
  return;
}

