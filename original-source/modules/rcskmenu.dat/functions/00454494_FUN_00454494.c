/*
 * FUN_00454494 at 00454494
 * int * __register FUN_00454494(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 00454494-004544db
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00454494(int *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
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
  if (param_1[1] == 0) {
    iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',param_3);
    param_1[1] = iVar1;
  }
  FUN_00454504((int)param_1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

