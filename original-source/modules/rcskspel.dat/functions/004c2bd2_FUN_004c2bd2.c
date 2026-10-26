/*
 * FUN_004c2bd2 at 004c2bd2
 * undefined FUN_004c2bd2(void)
 * Address ranges: 004c2bd2-004c2c0e;004c2c16-004c2c27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c2bd2(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d3bb0;
  pcStack_10 = FUN_004c2aa4;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_00502fec != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_00502fec)();
  }
  local_8 = 0xffffffff;
  FUN_004c2b7c();
  return;
}

