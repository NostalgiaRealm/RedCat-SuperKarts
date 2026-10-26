/*
 * FUN_004240b2 at 004240b2
 * undefined __stdcall FUN_004240b2(void)
 * Address ranges: 004240b2-004240ee;004240f6-00424107
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004240b2(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a408;
  pcStack_10 = FUN_00421630;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_004374a4 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_004374a4)();
  }
  local_8 = 0xffffffff;
  FUN_0042405c();
  return;
}

