/*
 * FUN_0045323c at 0045323c
 * undefined FUN_0045323c(void)
 * Address ranges: 0045323c-004532f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0045323c(int *param_1,char param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  char extraout_DL;
  char cVar3;
  byte bVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffdc,in_stack_ffffffe0);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  FUN_00414778(param_1,'\0',param_3);
  bVar4 = 0;
  do {
    piVar1 = FUN_00452980((int *)&PTR_FUN_004528d8,'\x01',(int)param_1);
    param_1[bVar4 + 9] = (int)piVar1;
    if (bVar4 == 5) {
      iVar2 = piVar1[4];
      *(int **)(iVar2 + 0xc) = param_1;
      *(code **)(iVar2 + 8) = FUN_0045348c;
    }
    else {
      iVar2 = piVar1[4];
      *(int **)(iVar2 + 0xc) = param_1;
      *(undefined1 **)(iVar2 + 8) = &LAB_00453480;
    }
    bVar4 = bVar4 + 1;
  } while (bVar4 != 7);
  iVar2 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  param_1[0x13] = iVar2;
  param_1[0x11] = 0x68;
  param_1[0x12] = 0x18;
  param_1[0x10] = 0;
  piVar1 = FUN_004174fc((int *)&PTR_FUN_00415fdc,'\x01',extraout_ECX_01);
  param_1[0x14] = (int)piVar1;
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffdc;
  }
  return param_1;
}

