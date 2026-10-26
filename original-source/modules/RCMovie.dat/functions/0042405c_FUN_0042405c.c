/*
 * FUN_0042405c at 0042405c
 * undefined __stdcall FUN_0042405c(void)
 * Address ranges: 0042405c-00424098;004240a0-004240b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042405c(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0042a3f0;
  pcStack_10 = FUN_00421630;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (DAT_0043e464 != (code *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*DAT_0043e464)();
  }
  local_8 = 0xffffffff;
  FUN_004260b4();
  return;
}

