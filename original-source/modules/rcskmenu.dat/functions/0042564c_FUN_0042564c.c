/*
 * FUN_0042564c at 0042564c
 * int * __register FUN_0042564c(int * param_1, char param_2, int * param_3)
 * Address ranges: 0042564c-0042569c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042564c(int *param_1,char param_2,int *param_3)

{
  int *extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00441790(param_1,'\0',param_3);
  if ((PTR_DAT_0047c9d8[8] != '\0') && (*(int *)PTR_DAT_0047c9d4 == 2)) {
    *(undefined1 *)(param_1 + 0x55) = 0;
  }
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

