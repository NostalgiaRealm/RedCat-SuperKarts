/*
 * FUN_00448270 at 00448270
 * undefined FUN_00448270(void)
 * Address ranges: 00448270-004482e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00448270(int param_1)

{
  undefined1 auStack_20 [12];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  
  *(undefined4 *)((&DAT_0053f99c)[param_1 * 0xd0] * 0xd0 + 0x44 + DAT_0067ee20) = 1;
  uStack_10 = (&DAT_0053f99c)[param_1 * 0xd0];
  iStack_8 = param_1;
  uStack_4 = 0;
  uStack_3 = 0;
  auStack_20[0] = 1;
  uStack_14 = 0x3f000000;
  uStack_c = 0xffffffff;
  FUN_00445740(auStack_20);
  return 1;
}

