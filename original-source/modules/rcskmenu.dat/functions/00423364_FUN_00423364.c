/*
 * FUN_00423364 at 00423364
 * int * __register FUN_00423364(int * param_1, char param_2, int * param_3)
 * Address ranges: 00423364-004233c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00423364(int *param_1,char param_2,int *param_3)

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
  FUN_004467c0(param_1,'\0',param_3);
  param_1[0x10] = param_1[0x10] | 0x840;
  FUN_0043eeb0(param_1,0x41);
  FUN_0043eed0(param_1,0x11);
  *(undefined1 *)((int)param_1 + 0x12d) = 1;
  *(undefined1 *)(param_1 + 0x4c) = 1;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

