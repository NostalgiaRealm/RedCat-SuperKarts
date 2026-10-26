/*
 * FUN_0044e168 at 0044e168
 * int * __register FUN_0044e168(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0044e168-0044e1b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0044e168(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
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
  FUN_0044dbdc(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 1) = 0;
  piVar1 = FUN_0044ddc8((int *)&PTR_FUN_0044dd90,'\x01',0);
  param_1[2] = (int)piVar1;
  FUN_00403b50(param_1 + 3);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

