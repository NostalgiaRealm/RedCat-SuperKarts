/*
 * FUN_004a82a0 at 004a82a0
 * undefined FUN_004a82a0(void)
 * Address ranges: 004a82a0-004a8300
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a82a0(void)

{
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_004d1809;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_004a8490();
  FUN_004a8510();
  local_4 = local_4 & 0xffffff00;
  FUN_004ad100();
  local_4 = 0xffffffff;
  FUN_004aa0b0();
  ExceptionList = local_c;
  return;
}

