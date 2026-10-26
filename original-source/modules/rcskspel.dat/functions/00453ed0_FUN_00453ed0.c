/*
 * FUN_00453ed0 at 00453ed0
 * undefined FUN_00453ed0(void)
 * Address ranges: 00453ed0-00453f2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453ed0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004cdd60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0044feb0(param_1);
  FUN_004503a0(1);
  local_8 = 0;
  FUN_00454260();
  ExceptionList = local_10;
  return;
}

