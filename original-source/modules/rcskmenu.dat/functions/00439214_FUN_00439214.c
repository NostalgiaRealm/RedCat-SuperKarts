/*
 * FUN_00439214 at 00439214
 * int * __register FUN_00439214(int * param_1, char param_2, int * param_3)
 * Address ranges: 00439214-004392a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00439214(int *param_1,char param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffdc,in_stack_ffffffe0);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  piVar1 = FUN_00436158((int *)&PTR_FUN_00434d74,'\x01',param_1);
  param_1[10] = (int)piVar1;
  piVar1[0x1f] = (int)param_1;
  piVar1[0x1e] = *(int *)(*param_1 + 0x38);
  piVar1[0x19] = (int)param_1;
  iVar2 = FUN_00402e7c((int *)&DAT_004335c4,'\x01',extraout_ECX_00);
  param_1[0xe] = iVar2;
  *(int **)(iVar2 + 0xc) = param_1;
  *(undefined1 **)(iVar2 + 8) = &LAB_00439a74;
  *(undefined1 *)((int)param_1 + 0x35) = 1;
  FUN_00414778(param_1,'\0',param_3);
  iVar2 = param_1[10];
  *(undefined1 *)(iVar2 + 0x2f) = 0;
  *(undefined1 *)(iVar2 + 0x30) = 0;
  FUN_00439e88(param_1);
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffdc;
  }
  return param_1;
}

