/*
 * FUN_00411eec at 00411eec
 * int * __register FUN_00411eec(int * param_1, char param_2, int param_3, int param_4)
 * Address ranges: 00411eec-00411f32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00411eec(int *param_1,char param_2,int param_3,int param_4)

{
  int iVar1;
  int extraout_ECX;
  char extraout_DL;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  param_1[1] = param_3;
  iVar1 = FUN_00402714(param_4);
  param_1[2] = iVar1;
  param_1[3] = param_4;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

