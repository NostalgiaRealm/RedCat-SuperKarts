/*
 * FUN_00462f28 at 00462f28
 * undefined FUN_00462f28(void)
 * Address ranges: 00462f28-00462fcb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00462f28(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  FUN_00425790(param_1,'\0',param_3);
  iVar1 = FUN_00462500((int *)&PTR_FUN_004623a8,'\x01',(int)param_1);
  param_1[0x80] = iVar1;
  piVar2 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',extraout_ECX_00);
  param_1[0x83] = (int)piVar2;
  FUN_0043eeb0(param_1,0x79);
  FUN_0043eed0(param_1,0x15);
  *(undefined1 *)((int)param_1 + 0x212) = 1;
  param_1[0x81] = -0x7ffffffb;
  param_1[0x82] = -0x7ffffff8;
  FUN_00445950((int)param_1,'\0');
  FUN_0043e3e0((int *)param_1[0x83],(int)param_1);
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

