/*
 * FUN_0045f6c0 at 0045f6c0
 * int * __register FUN_0045f6c0(int * param_1, char param_2, int * param_3)
 * Address ranges: 0045f6c0-0045f732
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0045f6c0(int *param_1,char param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *extraout_ECX;
  char extraout_DL;
  char cVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  uVar1 = FUN_00403024(param_3,(int)&PTR_FUN_0045efe4);
  if ((char)uVar1 == '\0') {
    FUN_00403b34("Assertion failure");
  }
  FUN_0045df28(param_1,'\0',param_3);
  iVar2 = FUN_0040303c(param_3,(int)&PTR_FUN_0045efe4);
  param_1[0x90] = iVar2;
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

