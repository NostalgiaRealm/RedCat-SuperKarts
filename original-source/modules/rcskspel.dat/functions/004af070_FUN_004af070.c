/*
 * FUN_004af070 at 004af070
 * undefined FUN_004af070(void)
 * Address ranges: 004af070-004af0ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004af070(void)

{
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_004d1956;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_004ad100();
  local_4 = local_4 & 0xffffff00;
  FUN_004ad100();
  local_4 = 0xffffffff;
  FUN_004aa0b0();
  ExceptionList = local_c;
  return;
}

