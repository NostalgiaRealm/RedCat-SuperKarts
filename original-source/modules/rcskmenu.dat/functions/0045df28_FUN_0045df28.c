/*
 * FUN_0045df28 at 0045df28
 * int * __register FUN_0045df28(int * param_1, char param_2, int * param_3)
 * Address ranges: 0045df28-0045dfa3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0045df28(int *param_1,char param_2,int *param_3)

{
  int *piVar1;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00425790(param_1,'\0',param_3);
  param_1[0x10] = param_1[0x10] & 0xffffffbf;
  piVar1 = FUN_00417ff0((int *)&PTR_FUN_0041631c,'\x01',extraout_ECX_00);
  param_1[0x80] = (int)piVar1;
  param_1[0x82] = 0;
  param_1[0x83] = 0xc0c0c0;
  *(undefined1 *)(param_1 + 0x84) = 0;
  param_1[0x85] = 0;
  *(undefined1 *)(param_1 + 0x86) = 0;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

