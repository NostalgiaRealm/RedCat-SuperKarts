/*
 * FUN_0043e0f8 at 0043e0f8
 * undefined __register FUN_0043e0f8(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 0043e0f8-0043e11c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e0f8(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
    *param_1 = iVar1;
  }
  FUN_0040f504((int *)*param_1,param_2);
  return;
}

