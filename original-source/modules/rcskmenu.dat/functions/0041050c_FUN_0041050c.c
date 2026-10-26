/*
 * FUN_0041050c at 0041050c
 * undefined __register FUN_0041050c(int * param_1, int * param_2)
 * Address ranges: 0041050c-00410565
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041050c(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00403024(param_2,param_1[1]);
  if ((char)uVar1 == '\0') {
    FUN_0040f5ec(&PTR_FUN_0040de6c,(undefined4 *)PTR_PTR_0047c848,0);
  }
  FUN_0040f504((int *)param_1[2],(int)param_2);
  param_2[1] = (int)param_1;
  param_2[2] = param_1[4];
  param_1[4] = param_1[4] + 1;
  (**(code **)(*param_1 + 0xc))(param_1,param_2);
  FUN_0041015c(param_1);
  FUN_004104a8(param_1,param_2,0);
  return;
}

