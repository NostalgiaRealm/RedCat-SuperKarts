/*
 * FUN_0041a7d4 at 0041a7d4
 * int * __register FUN_0041a7d4(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0041a7d4-0041a812
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041a7d4(int *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar2;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  iVar1 = FUN_0041a794();
  FUN_0041a7b4(iVar1,extraout_EDX,extraout_ECX_00);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

