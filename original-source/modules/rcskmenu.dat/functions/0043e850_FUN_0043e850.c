/*
 * FUN_0043e850 at 0043e850
 * int * __register FUN_0043e850(int * param_1, char param_2, int * param_3)
 * Address ranges: 0043e850-0043e917
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0043e850(int *param_1,char param_2,int *param_3)

{
  int *piVar1;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
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
  FUN_00414778(param_1,'\0',param_3);
  param_1[0xb] = (int)param_1;
  param_1[10] = *(int *)(*param_1 + 0x6c);
  param_1[0x10] = 0xaa;
  piVar1 = FUN_004174fc((int *)&PTR_FUN_00415fdc,'\x01',extraout_ECX_00);
  param_1[0x16] = (int)piVar1;
  piVar1[3] = (int)param_1;
  piVar1[2] = (int)FUN_0043f6fc;
  *(undefined1 *)((int)param_1 + 0x51) = 3;
  piVar1 = FUN_0043e424((int *)&PTR_FUN_0043b108,'\x01',(int)param_1);
  param_1[0x19] = (int)piVar1;
  piVar1[7] = (int)param_1;
  piVar1[6] = (int)FUN_00440410;
  param_1[0x18] = -0x7ffffffb;
  *(undefined1 *)((int)param_1 + 0x47) = 1;
  *(undefined1 *)(param_1 + 0x12) = 1;
  *(undefined1 *)((int)param_1 + 0x49) = 1;
  *(undefined1 *)((int)param_1 + 0x4a) = 1;
  *(undefined1 *)((int)param_1 + 0x8a) = 1;
  *(undefined1 *)(param_1 + 0x14) = 1;
  *(undefined1 *)((int)param_1 + 0x4e) = 0;
  *(undefined2 *)((int)param_1 + 0x6a) = 0xfff4;
  param_1[0x29] = (int)&PTR_FUN_00428da8;
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

