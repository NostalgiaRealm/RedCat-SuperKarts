/*
 * FUN_0049d320 at 0049d320
 * undefined FUN_0049d320(void)
 * Address ranges: 0049d320-0049d37a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall
FUN_0049d320(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d15d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0049f040();
  local_4 = 0;
  FUN_0049d300();
  FUN_0049d3e0(param_2,param_3,param_4);
  ExceptionList = local_c;
  return param_1;
}

