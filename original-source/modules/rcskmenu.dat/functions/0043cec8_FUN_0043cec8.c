/*
 * FUN_0043cec8 at 0043cec8
 * undefined __register FUN_0043cec8(int * param_1, char param_2, int param_3)
 * Address ranges: 0043cec8-0043ceea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cec8(int *param_1,char param_2,int param_3)

{
  int extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_00000000;
  undefined4 in_stack_fffffff0;
  undefined4 in_stack_fffffff4;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_fffffff0,in_stack_fffffff4);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  param_1[0xe] = param_3;
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_00000000;
  }
  return;
}

