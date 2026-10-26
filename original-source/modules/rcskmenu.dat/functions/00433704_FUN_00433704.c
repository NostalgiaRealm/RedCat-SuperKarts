/*
 * FUN_00433704 at 00433704
 * undefined FUN_00433704(void)
 * Address ranges: 00433704-0043374d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00433704(int *param_1,char param_2,int *param_3)

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
  param_1[10] = 0x10;
  param_1[9] = 0x10;
  (**(code **)(*param_1 + 0x34))();
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

