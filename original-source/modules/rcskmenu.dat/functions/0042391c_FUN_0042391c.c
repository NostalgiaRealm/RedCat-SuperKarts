/*
 * FUN_0042391c at 0042391c
 * undefined FUN_0042391c(void)
 * Address ranges: 0042391c-004239b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042391c(int *param_1,char param_2,int *param_3)

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
  if (*PTR_DAT_0047c7a0 == '\0') {
    param_1[0x10] = 0x2b8;
  }
  else {
    param_1[0x10] = 0x2a8;
  }
  FUN_0043eeb0(param_1,0x79);
  FUN_0043eed0(param_1,0x19);
  FUN_00445950((int)param_1,'\x01');
  FUN_0043f7fc((int)param_1,'\0');
  *(undefined1 *)(param_1 + 0x7d) = 1;
  *(undefined1 *)((int)param_1 + 0x1f7) = 1;
  *(undefined1 *)(param_1 + 0x7e) = 1;
  *(undefined1 *)((int)param_1 + 0x1f9) = 1;
  FUN_0042402c(param_1);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

