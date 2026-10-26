/*
 * FUN_0041c7f0 at 0041c7f0
 * int * __register FUN_0041c7f0(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0041c7f0-0041c857
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041c7f0(int *param_1,char param_2,undefined4 param_3)

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
  param_1[0xb] = 0x20000000;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_004167cc,'\x01',extraout_ECX_00);
  param_1[8] = iVar1;
  FUN_0041bd50(iVar1);
  if (DAT_0047b3a0 != '\0') {
    (**(code **)(*param_1 + 0x68))(param_1,1);
  }
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

