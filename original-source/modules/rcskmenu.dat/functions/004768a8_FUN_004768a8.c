/*
 * FUN_004768a8 at 004768a8
 * int * __register FUN_004768a8(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 004768a8-00476905
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004768a8(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
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
  FUN_0045d414(param_1,'\0',param_3);
  FUN_00403ba4(param_1 + 0xb4,(undefined4 *)"PHASE_HIGHSCORE");
  piVar1 = FUN_00458584((int *)&DAT_00458564,'\x01',extraout_ECX_00);
  param_1[0xe0] = (int)piVar1;
  FUN_004769ac((int)param_1);
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

