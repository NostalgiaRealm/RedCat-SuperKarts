/*
 * FUN_00414f54 at 00414f54
 * int * __register FUN_00414f54(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 00414f54-00414f94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00414f54(int *param_1,char param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  (**(code **)*param_1)(param_1,param_3);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

