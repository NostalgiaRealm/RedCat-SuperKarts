/*
 * FUN_0042a4e8 at 0042a4e8
 * int * __register FUN_0042a4e8(int * param_1, char param_2, int * param_3)
 * Address ranges: 0042a4e8-0042a54f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042a4e8(int *param_1,char param_2,int *param_3)

{
  int *piVar1;
  int *extraout_ECX;
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
  FUN_00441790(param_1,'\0',param_3);
  piVar1 = FUN_00429964((int *)&PTR_FUN_00426e14,'\x01',(int)param_1,0);
  param_1[0x7c] = (int)piVar1;
  piVar1 = FUN_00429964((int *)&PTR_FUN_00426e14,'\x01',(int)param_1,1);
  param_1[0x7d] = (int)piVar1;
  *(undefined1 *)(param_1 + 0x7e) = 1;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

