/*
 * FUN_0043a5d4 at 0043a5d4
 * undefined FUN_0043a5d4(void)
 * Address ranges: 0043a5d4-0043a647
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0043a5d4(int *param_1,char param_2,int *param_3)

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
  FUN_00439214(param_1,'\0',param_3);
  param_1[0x12] = -1;
  param_1[0x13] = -1;
  iVar1 = param_1[10];
  *(int **)(iVar1 + 0x84) = param_1;
  *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(*param_1 + 0x3c);
  param_1[0xb] = *(int *)(*(int *)PTR_DAT_0047c86c + 0x24);
  *(undefined1 *)((int)param_1 + 0x51) = 1;
  FUN_0043a590(DAT_0047d798,(int)param_1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

