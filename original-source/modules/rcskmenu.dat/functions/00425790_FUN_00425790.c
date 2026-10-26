/*
 * FUN_00425790 at 00425790
 * int * __register FUN_00425790(int * param_1, char param_2, int * param_3)
 * Address ranges: 00425790-004257ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00425790(int *param_1,char param_2,int *param_3)

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
  FUN_0042564c(param_1,'\0',param_3);
  param_1[0x10] = 0xe0;
  FUN_0043eeb0(param_1,0x4b);
  FUN_0043eed0(param_1,0x19);
  FUN_00445950((int)param_1,'\x01');
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

