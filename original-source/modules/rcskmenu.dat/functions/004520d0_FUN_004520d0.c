/*
 * FUN_004520d0 at 004520d0
 * int * __register FUN_004520d0(int * param_1, char param_2, HGLOBAL param_3)
 * Address ranges: 004520d0-00452122
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004520d0(int *param_1,char param_2,HGLOBAL param_3)

{
  SIZE_T SVar1;
  LPVOID pvVar2;
  HGLOBAL extraout_ECX;
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
  FUN_00402e7c(param_1,'\0',param_3);
  param_1[5] = (int)param_3;
  SVar1 = GlobalSize(param_3);
  pvVar2 = GlobalLock(param_3);
  FUN_00411b98((int)param_1,pvVar2,SVar1);
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

