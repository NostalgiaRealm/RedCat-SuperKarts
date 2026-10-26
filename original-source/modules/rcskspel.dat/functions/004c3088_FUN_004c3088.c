/*
 * FUN_004c3088 at 004c3088
 * undefined FUN_004c3088(void)
 * Address ranges: 004c3088-004c3123
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004c3088(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d3bd8;
  pcStack_10 = FUN_004c2aa4;
  local_14 = ExceptionList;
  DAT_006b677c = param_1;
  DAT_006b6780 = param_3;
  local_8 = 1;
  ExceptionList = &local_14;
  uVar1 = FUN_004bebab(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_004c314e();
  ExceptionList = local_14;
  return uVar1;
}

