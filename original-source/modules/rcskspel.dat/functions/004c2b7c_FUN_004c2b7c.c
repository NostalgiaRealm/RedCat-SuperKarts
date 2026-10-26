/*
 * FUN_004c2b7c at 004c2b7c
 * undefined FUN_004c2b7c(void)
 * Address ranges: 004c2b7c-004c2bb8;004c2bc0-004c2bd1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c2b7c(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d3b98;
  pcStack_10 = FUN_004c2aa4;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (DAT_006b6778 != (code *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*DAT_006b6778)();
  }
  local_8 = 0xffffffff;
  FUN_004c9715();
  return;
}

