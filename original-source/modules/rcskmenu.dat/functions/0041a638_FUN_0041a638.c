/*
 * FUN_0041a638 at 0041a638
 * int * __register FUN_0041a638(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0041a638-0041a6b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041a638(int *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
  param_1[1] = iVar1;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  param_1[2] = iVar1;
  FUN_0041a6e4((int)param_1,CONCAT22(extraout_var,3),(int)&PTR_FUN_004166f0);
  FUN_0041a6e4((int)param_1,CONCAT22(extraout_var_00,0xe),(int)&PTR_FUN_004166f0);
  FUN_0041a6e4((int)param_1,CONCAT22(extraout_var_01,2),(int)&PTR_FUN_00416860);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

