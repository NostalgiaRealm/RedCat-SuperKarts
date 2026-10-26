/*
 * FUN_004593d0 at 004593d0
 * undefined FUN_004593d0(void)
 * Address ranges: 004593d0-00459439
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_004593d0(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdfc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00458230(param_2,0);
  local_4 = 0;
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0x3f800000;
  param_1[0x13] = 0x3f800000;
  param_1[0x14] = 0xffffffff;
  *param_1 = &PTR_FUN_004d2890;
  FUN_00459910(param_1 + 0x11);
  ExceptionList = local_c;
  return param_1;
}

