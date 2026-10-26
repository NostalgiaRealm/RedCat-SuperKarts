/*
 * FUN_00483c70 at 00483c70
 * undefined FUN_00483c70(void)
 * Address ranges: 00483c70-00483dde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_00483c70(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d13ef;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00483830();
  *(undefined1 *)(param_1 + 3) = 1;
  *(undefined1 *)((int)param_1 + 0xd) = 1;
  param_1[7] = 0xc1000000;
  param_1[8] = 0xc0800000;
  param_1[9] = 0x3f800000;
  param_1[0xe] = 0;
  param_1[0xf] = 0x41c80000;
  param_1[0x10] = 0x420c0000;
  param_1[0x26] = 0x41700000;
  param_1[0x27] = 0xc20c0000;
  local_4 = 0;
  *param_1 = &PTR_FUN_004d2ef0;
  param_1[1] = 400;
  param_1[0x28] = 0;
  param_1[0xb] = 5;
  param_1[0xc] = 2;
  param_1[6] = 0x3f000000;
  param_1[4] = 0x40000000;
  param_1[5] = 0x41a00000;
  param_1[10] = 0x806060c0;
  param_1[0x2b] = 0x3f0f5c29;
  param_1[0x2d] = 0x3d4ccccd;
  param_1[0x2c] = 0x3f2147ae;
  param_1[0x2e] = 0x3ecccccd;
  param_1[0x24] = 0x41c80000;
  param_1[0x25] = 0;
  uVar1 = FUN_004a6060(s_S_SFX_PCX_004f9aec);
  param_1[0x29] = uVar1;
  param_1[0x2a] = 0;
  param_1[2] = 2;
  ExceptionList = local_c;
  return param_1;
}

