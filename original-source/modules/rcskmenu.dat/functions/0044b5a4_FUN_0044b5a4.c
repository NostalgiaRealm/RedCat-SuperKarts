/*
 * FUN_0044b5a4 at 0044b5a4
 * undefined FUN_0044b5a4(void)
 * Address ranges: 0044b5a4-0044b5f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0044b5a4(int *param_1,char param_2,int *param_3)

{
  HWND pHVar1;
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
  FUN_00414778(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 0xe) = 1;
  param_1[9] = 1000;
  pHVar1 = FUN_00429694();
  param_1[10] = (int)pHVar1;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

