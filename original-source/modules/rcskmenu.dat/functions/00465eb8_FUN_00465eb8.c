/*
 * FUN_00465eb8 at 00465eb8
 * int * __register FUN_00465eb8(int * param_1, char param_2, int * param_3)
 * Address ranges: 00465eb8-00465f70
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00465eb8(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  char extraout_DL;
  char cVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  FUN_00441790(param_1,'\0',param_3);
  FUN_0043eeb0(param_1,0x121);
  FUN_0043eed0(param_1,0xc1);
  FUN_00445950((int)param_1,'\x01');
  param_1[0x10] = 0x81;
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_00465898,'\x01',extraout_ECX_00);
  param_1[0x84] = iVar1;
  *(int **)(iVar1 + 0xc) = param_1;
  piVar2 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',extraout_ECX_01);
  param_1[0x7c] = (int)piVar2;
  FUN_0043e3e0(piVar2,(int)param_1);
  iVar1 = FUN_00402e7c((int *)&DAT_004335c4,'\x01',extraout_ECX_02);
  param_1[0x7e] = iVar1;
  *(int **)(iVar1 + 0xc) = param_1;
  *(code **)(iVar1 + 8) = FUN_0046631c;
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

