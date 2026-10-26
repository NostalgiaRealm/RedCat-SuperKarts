/*
 * FUN_004be99e at 004be99e
 * undefined FUN_004be99e(void)
 * Address ranges: 004be99e-004bea05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004be99e(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d36f0;
  pcStack_10 = FUN_004c2aa4;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)();
  }
  local_8 = 0xffffffff;
  FUN_004bea06();
  ExceptionList = local_14;
  return;
}

