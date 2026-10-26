/*
 * FUN_004739f4 at 004739f4
 * int * __register FUN_004739f4(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 004739f4-00473a36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004739f4(int *param_1,char param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
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
  FUN_0045d414(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 0xce) = 0;
  *(undefined1 *)((int)param_1 + 0x339) = 1;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

