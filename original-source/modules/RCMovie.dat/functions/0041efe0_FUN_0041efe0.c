/*
 * FUN_0041efe0 at 0041efe0
 * undefined4 * __fastcall FUN_0041efe0(undefined4 * param_1)
 * Address ranges: 0041efe0-0041f02a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_0041efe0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00427f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0041e930(param_1);
  local_4 = 0;
  *(undefined1 *)((int)param_1 + 0x35) = 0;
  FUN_0041f250((undefined4 *)((int)param_1 + 0x36));
  *param_1 = &PTR_FUN_00429f48;
  ExceptionList = local_c;
  return param_1;
}

