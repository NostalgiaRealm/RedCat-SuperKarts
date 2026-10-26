/*
 * FUN_0047d140 at 0047d140
 * undefined FUN_0047d140(void)
 * Address ranges: 0047d140-0047d182
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047d140(int param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d1041;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != 0) {
    ExceptionList = &local_c;
    FUN_00477a70(param_2);
  }
  ExceptionList = local_c;
  return;
}

