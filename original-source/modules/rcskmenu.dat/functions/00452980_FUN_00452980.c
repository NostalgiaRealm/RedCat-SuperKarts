/*
 * FUN_00452980 at 00452980
 * int * __register FUN_00452980(int * param_1, char param_2, int param_3)
 * Address ranges: 00452980-004529ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00452980(int *param_1,char param_2,int param_3)

{
  int *piVar1;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 2) = 1;
  param_1[1] = param_3;
  piVar1 = FUN_004516e4((int *)&PTR_FUN_00450238,'\x01',extraout_ECX_00);
  param_1[4] = (int)piVar1;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

