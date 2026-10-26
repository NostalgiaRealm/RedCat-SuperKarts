/*
 * FUN_00429964 at 00429964
 * int * __register FUN_00429964(int * param_1, char param_2, int param_3, undefined1 param_4)
 * Address ranges: 00429964-004299eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00429964(int *param_1,char param_2,int param_3,undefined1 param_4)

{
  int extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  param_1[1] = param_3;
  *(undefined1 *)(param_1 + 6) = param_4;
  *(undefined2 *)((int)param_1 + 10) = 0x50;
  *(undefined2 *)(param_1 + 2) = 8;
  *(undefined1 *)(param_1 + 7) = 1;
  param_1[8] = 10;
  param_1[0x10] = 4;
  param_1[0xf] = 0xc;
  param_1[10] = -0x7fffffec;
  *(undefined1 *)(param_1 + 0xb) = 1;
  *(undefined1 *)(param_1 + 0x11) = 1;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

