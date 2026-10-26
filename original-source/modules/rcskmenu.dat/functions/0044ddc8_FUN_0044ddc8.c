/*
 * FUN_0044ddc8 at 0044ddc8
 * int * __register FUN_0044ddc8(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0044ddc8-0044de19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0044ddc8(int *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_0044dbdc(param_1,'\0',param_3);
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  param_1[1] = iVar1;
  *(char *)(param_1 + 2) = (char)param_3;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

