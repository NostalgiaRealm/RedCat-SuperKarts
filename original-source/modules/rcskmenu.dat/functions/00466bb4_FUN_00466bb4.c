/*
 * FUN_00466bb4 at 00466bb4
 * undefined FUN_00466bb4(void)
 * Address ranges: 00466bb4-00466c13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00466bb4(int *param_1,char param_2,int *param_3)

{
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  char extraout_DL;
  char cVar1;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00441790(param_1,'\0',param_3);
  FUN_0043ec64(param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),5),extraout_ECX_00);
  param_1[0x10] = param_1[0x10] | 0x401;
  FUN_0043f564(param_1,0,extraout_ECX_01);
  *(undefined1 *)(param_1 + 0x7e) = 1;
  *(undefined1 *)((int)param_1 + 0x1fa) = 0;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

