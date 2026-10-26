/*
 * FUN_004108f0 at 004108f0
 * undefined __register FUN_004108f0(undefined4 param_1, undefined4 * param_2, undefined4 param_3)
 * Address ranges: 004108f0-00410937
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004108f0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  byte *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (byte *)0x0;
  puStack_1c = &LAB_00410938;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_00405438(param_2,(int *)&local_8);
  FUN_004108b8(param_1,local_8,param_3);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0041093f;
  puStack_1c = (undefined1 *)0x410937;
  FUN_00403b50((int *)&local_8);
  return;
}

