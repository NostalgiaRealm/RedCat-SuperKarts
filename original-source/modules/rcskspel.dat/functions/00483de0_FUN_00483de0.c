/*
 * FUN_00483de0 at 00483de0
 * undefined FUN_00483de0(void)
 * Address ranges: 00483de0-00483ee7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_00483de0(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1401;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00483830();
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  local_4 = 0;
  param_1[0xe] = 0;
  *param_1 = &PTR_FUN_004d2ef4;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  param_1[0xf] = 0;
  param_1[1] = 1;
  param_1[0xb] = 5;
  param_1[0xc] = 2;
  param_1[0x10] = 0;
  param_1[6] = 0;
  param_1[4] = 0x3f400000;
  param_1[0x26] = 0;
  param_1[5] = 0x3f800000;
  param_1[10] = 0xffffaf00;
  param_1[0x2b] = 0;
  param_1[0x27] = 0;
  param_1[0x2d] = 0;
  param_1[0x2c] = 0;
  param_1[0x2e] = 0;
  param_1[0x28] = 0;
  param_1[0x24] = 0x3f800000;
  param_1[0x25] = 0;
  uVar1 = FUN_004a6060(s_S_SFX_PCX_004f9af8);
  param_1[0x29] = uVar1;
  param_1[0x2a] = 0;
  param_1[2] = 1;
  ExceptionList = local_c;
  return param_1;
}

