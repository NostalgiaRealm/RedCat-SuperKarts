/*
 * FUN_00453bd0 at 00453bd0
 * undefined FUN_00453bd0(void)
 * Address ranges: 00453bd0-00453c4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00453bd0(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *extraout_ECX;
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
  FUN_004467c0(param_1,'\0',param_3);
  piVar2 = FUN_00452980((int *)&PTR_FUN_004528d8,'\x01',(int)param_1);
  param_1[0x4b] = (int)piVar2;
  iVar1 = piVar2[4];
  *(int **)(iVar1 + 0xc) = param_1;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(*param_1 + 0xa0);
  FUN_0043eeb0(param_1,0x40);
  FUN_0043eed0(param_1,0x40);
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

