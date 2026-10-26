/*
 * FUN_004516e4 at 004516e4
 * int * __register FUN_004516e4(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 004516e4-00451726
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004516e4(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  piVar1 = FUN_00419f0c(param_1,'\0',param_3);
  piVar1 = FUN_004516b8(piVar1,extraout_EDX,extraout_ECX_00);
  FUN_004524e4((int)param_1,(int)piVar1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

