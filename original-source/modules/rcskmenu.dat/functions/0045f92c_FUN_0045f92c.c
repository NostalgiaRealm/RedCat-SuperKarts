/*
 * FUN_0045f92c at 0045f92c
 * int * __register FUN_0045f92c(int * param_1, char param_2, int * param_3)
 * Address ranges: 0045f92c-0045f9fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0045f92c(int *param_1,char param_2,int *param_3)

{
  int *piVar1;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00447088(param_1,'\0',param_3);
  piVar1 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX_00);
  param_1[0x82] = (int)piVar1;
  piVar1 = FUN_0045f6c0((int *)&PTR_FUN_0045ee6c,'\x01',param_1);
  param_1[0x84] = (int)piVar1;
  (**(code **)(*piVar1 + 0x60))(piVar1,param_1);
  FUN_0045dfec(param_1[0x84],param_1[0x83]);
  param_1[0x87] = 0xfa;
  param_1[0x88] = 0x32;
  param_1[0x7e] = 5;
  param_1[0x86] = 5;
  param_1[0x85] = 5;
  FUN_0043eeb0(param_1,200);
  FUN_0043eed0(param_1,*(int *)(param_1[0x84] + 0x3c) + 10);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

