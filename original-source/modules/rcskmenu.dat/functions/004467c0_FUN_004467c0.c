/*
 * FUN_004467c0 at 004467c0
 * int * __register FUN_004467c0(int * param_1, char param_2, int * param_3)
 * Address ranges: 004467c0-0044681a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004467c0(int *param_1,char param_2,int *param_3)

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
  FUN_0043e850(param_1,'\0',param_3);
  piVar1 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',extraout_ECX_00);
  param_1[0x48] = (int)piVar1;
  FUN_0043e3e0(piVar1,(int)param_1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

