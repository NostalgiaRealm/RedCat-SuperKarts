/*
 * FUN_00422d50 at 00422d50
 * undefined FUN_00422d50(void)
 * Address ranges: 00422d50-00422ece
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00422d50(int param_1,undefined4 param_2)

{
  int iVar1;
  
  DAT_0050914c = FUN_0049fc60(0,0,0,0,0,0,param_1,param_2,FUN_004a0610);
  *(undefined4 *)(DAT_006a5c38 + DAT_0050914c * 0xa9 + 0xa1) = 2;
  *(undefined1 *)(DAT_006a5c38 + DAT_0050914c * 0xa9 + 0x90) = 1;
  DAT_00509140 = 0x41200000;
  DAT_00509144 = 0x40800000;
  DAT_00509148 = 0x41200000;
  iVar1 = DAT_006a5c38 + DAT_0050914c + 0x80 + DAT_0050914c * 0xa8;
  *(undefined4 *)(DAT_006a5c38 + DAT_0050914c + 0x80 + DAT_0050914c * 0xa8) = 0x41200000;
  *(undefined4 *)(iVar1 + 4) = 0x40800000;
  *(undefined4 *)(iVar1 + 8) = 0x41200000;
  FUN_004a09e0();
  iVar1 = DAT_006a5ee0 + 0x58 + param_1 * 0xbc;
  _DAT_00509130 = *(undefined4 *)(DAT_006a5ee0 + 0x58 + param_1 * 0xbc);
  _DAT_00509134 = *(undefined4 *)(iVar1 + 4);
  _DAT_00509138 = *(undefined4 *)(iVar1 + 8);
  return;
}

