/*
 * FUN_00417ff0 at 00417ff0
 * int * __register FUN_00417ff0(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 00417ff0-004180ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00417ff0(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
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
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
  piVar1 = FUN_004174fc((int *)&PTR_FUN_00415fdc,'\x01',extraout_ECX_00);
  param_1[3] = (int)piVar1;
  piVar1[3] = (int)param_1;
  piVar1[2] = (int)&LAB_00418bdc;
  piVar1[5] = (int)(param_1 + 0xe);
  piVar1 = FUN_00417a28((int *)&PTR_FUN_00416158,'\x01',extraout_ECX_01);
  param_1[4] = (int)piVar1;
  piVar1[3] = (int)param_1;
  piVar1[2] = (int)&LAB_00418bfc;
  piVar1[5] = (int)(param_1 + 0xe);
  piVar1 = FUN_00417cf4((int *)&PTR_FUN_00416258,'\x01',extraout_ECX_02);
  param_1[5] = (int)piVar1;
  piVar1[3] = (int)param_1;
  piVar1[2] = (int)&LAB_00418c1c;
  piVar1[5] = (int)(param_1 + 0xe);
  param_1[8] = 0xcc0020;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_0040f9e8(DAT_0047d6d4,(int)param_1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

