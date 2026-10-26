/*
 * FUN_004505fc at 004505fc
 * int * __register FUN_004505fc(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 004505fc-00450645
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004505fc(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
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
  FUN_00402e7c(param_1,'\0',param_3);
  piVar1 = FUN_00410030((int *)&PTR_FUN_0040e0cc,'\x01',(int)&PTR_FUN_0045050c);
  param_1[1] = (int)piVar1;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

