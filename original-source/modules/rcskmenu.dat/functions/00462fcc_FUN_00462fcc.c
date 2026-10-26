/*
 * FUN_00462fcc at 00462fcc
 * undefined __register FUN_00462fcc(int * param_1, char param_2)
 * Address ranges: 00462fcc-00463038
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00462fcc(int *param_1,char param_2)

{
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  byte local_9;
  int *local_8;
  
  puStack_10 = (undefined1 *)0x462fd7;
  local_8 = FUN_0040320c(param_1,param_2);
  puStack_14 = &LAB_00463039;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  local_9 = extraout_DL;
  FUN_00402eac((int *)local_8[0x83]);
  local_8[0x83] = 0;
  FUN_00402eac((int *)local_8[0x80]);
  local_8[0x80] = 0;
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00463040;
  puStack_14 = (undefined1 *)0x463038;
  FUN_004418ac(local_8,local_9 & 0xfc);
  return;
}

