/*
 * FUN_004a3c00 at 004a3c00
 * undefined FUN_004a3c00(void)
 * Address ranges: 004a3c00-004a3c49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a3c00(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d174b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004a4680();
  local_4 = 0xffffffff;
  FUN_004ad100();
  ExceptionList = local_c;
  return;
}

