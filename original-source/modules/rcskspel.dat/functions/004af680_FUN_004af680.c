/*
 * FUN_004af680 at 004af680
 * undefined FUN_004af680(void)
 * Address ranges: 004af680-004af79a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004af680(int *param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d1988;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (param_1[3] == 1) {
    ExceptionList = &local_c;
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x2d,param_1 + 5,
                 param_1[1]);
    iVar1 = *param_1;
    if (iVar1 != 0) {
      FUN_004be99e(iVar1,0x1d8,*(undefined4 *)(iVar1 + -4),FUN_004af070);
      FUN_004bc150(iVar1 + -4);
    }
  }
  if (param_1[3] != 0) {
    FUN_004bc150(param_1[4]);
    param_1[3] = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  local_4 = 0xffffffff;
  if (param_1[3] == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x2d,param_1 + 5,
                 param_1[1]);
    iVar1 = *param_1;
    if (iVar1 != 0) {
      FUN_004be99e(iVar1,0x1d8,*(undefined4 *)(iVar1 + -4),FUN_004af070);
      FUN_004bc150(iVar1 + -4);
    }
  }
  if (param_1[3] != 0) {
    FUN_004bc150(param_1[4]);
    param_1[3] = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  ExceptionList = local_c;
  return;
}

