/*
 * FUN_0043e460 at 0043e460
 * undefined FUN_0043e460(void)
 * Address ranges: 0043e460-0043e4a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e460(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  
  uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_0043b108);
  if ((char)uVar2 != '\0') {
    param_2[2] = param_1[2];
    param_2[3] = param_1[3];
    param_2[4] = param_1[4];
    iVar1 = param_1[2];
    param_2[2] = iVar1;
    FUN_00403088(param_2,iVar1,extraout_ECX);
    return;
  }
  FUN_0040fd8c(param_1,param_2);
  return;
}

