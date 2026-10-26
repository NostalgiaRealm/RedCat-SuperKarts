/*
 * FUN_00449784 at 00449784
 * int * __register FUN_00449784(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 00449784-00449811
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00449784(int *param_1,char param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined4 extraout_ECX;
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
  FUN_00402e7c(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 1) = 1;
  param_1[2] = 5;
  if (((*(int *)PTR_DAT_0047c9d4 == 2) && (3 < *(int *)PTR_DAT_0047c71c)) ||
     ((*(int *)PTR_DAT_0047c9d4 == 1 &&
      ((4 < *(int *)PTR_DAT_0047c71c ||
       ((*(int *)PTR_DAT_0047c71c == 4 && (9 < *(int *)PTR_DAT_0047c8b8)))))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  FUN_004498e8((int)param_1,0);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

