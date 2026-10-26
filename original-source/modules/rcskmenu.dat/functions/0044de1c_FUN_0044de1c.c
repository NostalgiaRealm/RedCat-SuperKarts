/*
 * FUN_0044de1c at 0044de1c
 * undefined FUN_0044de1c(void)
 * Address ranges: 0044de1c-0044de69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044de1c(int *param_1,char param_2)

{
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  byte bStack_9;
  int *piStack_8;
  
  puStack_10 = (undefined1 *)0x44de27;
  piStack_8 = FUN_0040320c(param_1,param_2);
  puStack_14 = &LAB_0044de6a;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  bStack_9 = extraout_DL;
  FUN_0044de90(piStack_8);
  FUN_00402eac((int *)piStack_8[1]);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0044de71;
  puStack_14 = (undefined1 *)0x44de69;
  FUN_0044dc14(piStack_8,bStack_9 & 0xfc);
  return;
}

