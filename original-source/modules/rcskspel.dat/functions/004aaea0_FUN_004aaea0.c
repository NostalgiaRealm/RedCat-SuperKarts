/*
 * FUN_004aaea0 at 004aaea0
 * undefined FUN_004aaea0(void)
 * Address ranges: 004aaea0-004aaee8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004aaea0(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d1868;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004ab6d0();
  local_4 = 0xffffffff;
  FUN_004aa0b0();
  ExceptionList = local_c;
  return;
}

