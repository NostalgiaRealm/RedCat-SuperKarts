/*
 * FUN_00459f94 at 00459f94
 * int * __register FUN_00459f94(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 00459f94-00459fff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00459f94(int *param_1,char param_2,undefined4 param_3)

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
  FUN_00402e7c(param_1,'\0',param_3);
  FUN_00403b50(param_1 + 3);
  *(undefined1 *)(param_1 + 4) = 1;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x22) = 0;
  *(undefined1 *)((int)param_1 + 0x23) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  param_1[1] = -1;
  *(undefined1 *)((int)param_1 + 0x26) = 0;
  piVar1 = FUN_0044dbdc((int *)&DAT_004547e0,'\x01',extraout_ECX_00);
  param_1[6] = (int)piVar1;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

