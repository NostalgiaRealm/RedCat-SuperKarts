/*
 * FUN_0042acf8 at 0042acf8
 * undefined FUN_0042acf8(void)
 * Address ranges: 0042acf8-0042ad53
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042acf8(int *param_1,char param_2,int *param_3)

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
  FUN_0042a4e8(param_1,'\0',param_3);
  param_1[0x10] = 0xab;
  FUN_0043eeb0(param_1,0xb9);
  FUN_0043eed0(param_1,0x29);
  *(undefined1 *)(param_1 + 0x82) = 1;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

