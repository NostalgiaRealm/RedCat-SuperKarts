/*
 * FUN_0041bb5c at 0041bb5c
 * int * __register FUN_0041bb5c(int * param_1, char param_2, int param_3)
 * Address ranges: 0041bb5c-0041bb97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041bb5c(int *param_1,char param_2,int param_3)

{
  int extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00417ff0(param_1,'\0',param_3);
  param_1[0x16] = param_3;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

