/*
 * FUN_0042f4b4 at 0042f4b4
 * undefined FUN_0042f4b4(void)
 * Address ranges: 0042f4b4-0042f51a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042f4b4(int *param_1,char param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar1;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    cVar1 = extraout_DL;
  }
  (**(code **)(*param_1 + 0xcc))(param_1,0);
  FUN_0042a744((int)param_1,'\0');
  FUN_0042c378((int)param_1,'\x05');
  FUN_00444158(param_1,'\x01',extraout_ECX);
  FUN_0042c5c0(param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),3),extraout_ECX_00);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = 0;
  }
  return param_1;
}

