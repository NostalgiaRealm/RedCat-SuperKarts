/*
 * FUN_00417a28 at 00417a28
 * int * __register FUN_00417a28(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 00417a28-00417a69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00417a28(int *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    cVar2 = extraout_DL;
  }
  iVar1 = FUN_00416b28(DAT_0047d6cc,&DAT_0047b584);
  param_1[4] = iVar1;
  *(undefined1 *)(param_1 + 6) = 4;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

