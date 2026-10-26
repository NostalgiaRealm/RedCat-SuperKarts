/*
 * FUN_0045d414 at 0045d414
 * int * __register FUN_0045d414(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0045d414-0045d45f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0045d414(int *param_1,char param_2,undefined4 param_3)

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
  FUN_0042adf0(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 0x7a) = 1;
  FUN_0042c93c((int)param_1,'\0');
  *(undefined1 *)((int)param_1 + 0x2d5) = 1;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

