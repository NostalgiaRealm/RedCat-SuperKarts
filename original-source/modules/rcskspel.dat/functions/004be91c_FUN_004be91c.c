/*
 * FUN_004be91c at 004be91c
 * undefined FUN_004be91c(void)
 * Address ranges: 004be91c-004be985
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004be91c(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  int local_20;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d36e0;
  pcStack_10 = FUN_004c2aa4;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    (*param_4)();
  }
  local_8 = 0xffffffff;
  FUN_004be986();
  ExceptionList = local_14;
  return;
}

