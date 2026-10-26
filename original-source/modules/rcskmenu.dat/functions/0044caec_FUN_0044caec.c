/*
 * FUN_0044caec at 0044caec
 * int * __register FUN_0044caec(int * param_1, char param_2, int param_3, undefined * param_4)
 * Address ranges: 0044caec-0044cb3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0044caec(int *param_1,char param_2,int param_3,undefined *param_4)

{
  int extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 1) = 0;
  FUN_0044cac8((int)param_1,param_3,param_4);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

