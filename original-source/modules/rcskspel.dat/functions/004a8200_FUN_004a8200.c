/*
 * FUN_004a8200 at 004a8200
 * undefined FUN_004a8200(void)
 * Address ranges: 004a8200-004a8291
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004a8200(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d17db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004aa0a0();
  local_4 = 0;
  FUN_004ad0f0();
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2e] = 0xffffffff;
  ExceptionList = local_c;
  return param_1;
}

