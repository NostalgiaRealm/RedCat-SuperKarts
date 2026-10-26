/*
 * FUN_00467e44 at 00467e44
 * undefined FUN_00467e44(void)
 * Address ranges: 00467e44-00467e9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00467e44(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  int *extraout_ECX;
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
  FUN_00466fbc(param_1,'\0',param_3);
  iVar1 = FUN_00462500((int *)&PTR_FUN_004623a8,'\x01',(int)param_1);
  param_1[0x96] = iVar1;
  param_1[0x94] = -0x7ffffff1;
  *(undefined1 *)((int)param_1 + 0x255) = 1;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

