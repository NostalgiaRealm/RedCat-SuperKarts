/*
 * FUN_00467ea0 at 00467ea0
 * undefined FUN_00467ea0(void)
 * Address ranges: 00467ea0-00467ef3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467ea0(int *param_1,char param_2)

{
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  byte bStack_9;
  int *piStack_8;
  
  puStack_10 = (undefined1 *)0x467eab;
  piStack_8 = FUN_0040320c(param_1,param_2);
  puStack_14 = &LAB_00467ef4;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  bStack_9 = extraout_DL;
  FUN_00402eac((int *)piStack_8[0x96]);
  piStack_8[0x96] = 0;
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00467efb;
  puStack_14 = (undefined1 *)0x467ef3;
  FUN_00467010(piStack_8,bStack_9 & 0xfc);
  return;
}

