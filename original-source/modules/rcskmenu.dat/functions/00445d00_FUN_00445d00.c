/*
 * FUN_00445d00 at 00445d00
 * undefined __register FUN_00445d00(undefined4 param_1, int * param_2, int param_3)
 * Address ranges: 00445d00-00445d3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445d00(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0043be00);
  if ((char)uVar1 != '\0') {
    FUN_0044540c((int)param_2,param_3);
    return;
  }
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0043b888);
  if ((char)uVar1 != '\0') {
    FUN_0043f8a0(param_2,param_3);
  }
  return;
}

