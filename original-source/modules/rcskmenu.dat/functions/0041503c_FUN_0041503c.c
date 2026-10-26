/*
 * FUN_0041503c at 0041503c
 * int * __register FUN_0041503c(int * param_1, char param_2, int * param_3)
 * Address ranges: 0041503c-0041507f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041503c(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00414778(param_1,'\0',param_3);
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  param_1[0x10] = iVar1;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

