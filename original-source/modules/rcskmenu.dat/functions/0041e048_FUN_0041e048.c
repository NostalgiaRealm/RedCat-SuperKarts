/*
 * FUN_0041e048 at 0041e048
 * int * __register FUN_0041e048(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0041e048-0041e09a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041e048(int *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
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
  FUN_00419f0c(param_1,'\0',param_3);
  *(undefined1 *)((int)param_1 + 0x19) = 1;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_00416944,'\x01',extraout_ECX_00);
  param_1[8] = iVar1;
  FUN_0041bd50(iVar1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

