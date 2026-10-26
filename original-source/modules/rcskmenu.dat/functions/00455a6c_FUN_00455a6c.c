/*
 * FUN_00455a6c at 00455a6c
 * undefined FUN_00455a6c(void)
 * Address ranges: 00455a6c-00455ab2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00455a6c(int *param_1,char param_2,int *param_3)

{
  int *extraout_ECX;
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
  FUN_00414778(param_1,'\0',param_3);
  param_1[0xb] = 0;
  param_1[10] = 0;
  FUN_00403b50(param_1 + 9);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

