/*
 * FUN_00457484 at 00457484
 * undefined FUN_00457484(void)
 * Address ranges: 00457484-004574e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00457484(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined4 extraout_ECX_01;
  char extraout_DL;
  char cVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  FUN_0044dbdc(param_1,'\0',param_3);
  iVar4 = 0;
  uVar2 = extraout_ECX_00;
  do {
    piVar1 = FUN_0044dbdc((int *)&UNK_004571a0,'\x01',uVar2);
    param_1[iVar4 + 1] = (int)piVar1;
    iVar4 = iVar4 + 1;
    uVar2 = extraout_ECX_01;
  } while (iVar4 != 4);
  piVar1 = FUN_0044dbdc((int *)&UNK_00457220,'\x01',extraout_ECX_01);
  param_1[5] = (int)piVar1;
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

