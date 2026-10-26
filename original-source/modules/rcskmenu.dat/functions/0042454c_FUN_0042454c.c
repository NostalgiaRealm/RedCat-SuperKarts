/*
 * FUN_0042454c at 0042454c
 * undefined FUN_0042454c(void)
 * Address ranges: 0042454c-0042463f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042454c(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  char extraout_DL;
  char cVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar4 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar4 = extraout_DL;
  }
  FUN_00441790(param_1,'\0',param_3);
  if (*PTR_DAT_0047c7a0 == '\0') {
    param_1[0x10] = 0x42b2;
  }
  else {
    param_1[0x10] = 0x42a2;
  }
  FUN_0043eeb0(param_1,0x91);
  FUN_0043eed0(param_1,0x19);
  FUN_00445950((int)param_1,'\x01');
  FUN_0043f7fc((int)param_1,'\0');
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_00422f18,'\x01',extraout_ECX_00);
  param_1[0x7c] = iVar1;
  *(int **)(iVar1 + 0xc) = param_1;
  piVar2 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',extraout_ECX_01);
  param_1[0x7d] = (int)piVar2;
  param_1[0x7f] = 0x10;
  *(undefined1 *)((int)param_1 + 0x1fa) = 0;
  puVar3 = FUN_004295d8();
  param_1[0x84] = (int)puVar3;
  puVar3 = FUN_004295d8();
  param_1[0x85] = (int)puVar3;
  param_1[0x81] = 8;
  param_1[0x8a] = -1;
  if (cVar4 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

