/*
 * FUN_0041a844 at 0041a844
 * undefined FUN_0041a844(void)
 * Address ranges: 0041a844-0041a877
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a844(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00402df4(param_2);
  uVar2 = FUN_00403024((int *)param_1[1],iVar1);
  if ((char)uVar2 != '\0') {
    (**(code **)(*param_2 + 8))(param_2,param_1[1]);
    return;
  }
  FUN_0040fd8c(param_1,param_2);
  return;
}

