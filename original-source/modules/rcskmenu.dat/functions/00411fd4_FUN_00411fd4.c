/*
 * FUN_00411fd4 at 00411fd4
 * int * __register FUN_00411fd4(int * param_1, char param_2, int param_3, undefined4 * param_4, undefined4 * param_5, int param_6, int param_7)
 * Address ranges: 00411fd4-0041202a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00411fd4(int *param_1,char param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
                  int param_6,int param_7)

{
  int extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  param_1[1] = param_3;
  param_1[2] = param_7;
  param_1[3] = param_6;
  FUN_00403ba4(param_1 + 4,param_5);
  FUN_00403ba4(param_1 + 5,param_4);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

