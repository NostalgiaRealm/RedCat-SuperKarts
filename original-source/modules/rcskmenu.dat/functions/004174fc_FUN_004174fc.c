/*
 * FUN_004174fc at 004174fc
 * int * __register FUN_004174fc(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 004174fc-0041754f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004174fc(int *param_1,char param_2,undefined4 param_3)

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
  DAT_0047b374 = 0;
  iVar1 = FUN_00416b28(DAT_0047d6c8,(byte *)&DAT_0047b374);
  param_1[4] = iVar1;
  param_1[6] = -0x7ffffff8;
  param_1[7] = DAT_0047d684;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

