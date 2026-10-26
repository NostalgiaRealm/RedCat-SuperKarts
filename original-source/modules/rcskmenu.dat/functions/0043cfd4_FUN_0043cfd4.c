/*
 * FUN_0043cfd4 at 0043cfd4
 * int * __register FUN_0043cfd4(int * param_1, char param_2, int param_3)
 * Address ranges: 0043cfd4-0043d037
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0043cfd4(int *param_1,char param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  FUN_0043cec8(param_1,'\0',param_3);
  piVar1 = FUN_00417cf4((int *)&PTR_FUN_00416258,'\x01',extraout_ECX_00);
  param_1[0x10] = (int)piVar1;
  uVar2 = FUN_0041e8ac(0,0xffffff);
  FUN_00417e74(piVar1,uVar2);
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

