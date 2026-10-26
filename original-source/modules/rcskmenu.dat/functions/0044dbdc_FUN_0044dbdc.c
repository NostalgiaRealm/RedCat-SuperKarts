/*
 * FUN_0044dbdc at 0044dbdc
 * int * __register FUN_0044dbdc(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0044dbdc-0044dc10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0044dbdc(int *param_1,char param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

