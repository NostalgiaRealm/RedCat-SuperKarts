/*
 * FUN_004848e0 at 004848e0
 * undefined FUN_004848e0(void)
 * Address ranges: 004848e0-004849fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004848e0(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1457;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00483830();
  param_1[6] = 0x3f800000;
  param_1[5] = 0x3f800000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xe] = 0;
  local_4 = 0;
  param_1[0xf] = 0;
  *param_1 = &PTR_FUN_004d2f00;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[0x10] = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 1;
  param_1[0x26] = 0;
  param_1[1] = 0x96;
  param_1[0xb] = 2;
  param_1[0xc] = 2;
  param_1[0x27] = 0x41a00000;
  param_1[4] = 0x3fa00000;
  param_1[10] = 0xff707070;
  param_1[0x2b] = 0;
  param_1[0x28] = 0;
  param_1[0x2d] = 0;
  param_1[0x2c] = 0;
  param_1[0x2e] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0x3f000000;
  uVar1 = FUN_004a6060(s_S_SFX_PCX_004f9c40);
  param_1[0x29] = uVar1;
  param_1[0x2a] = 0;
  param_1[2] = 2;
  ExceptionList = local_c;
  return param_1;
}

