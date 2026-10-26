/*
 * FUN_00442e64 at 00442e64
 * undefined FUN_00442e64(void)
 * Address ranges: 00442e64-00442eaa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442e64(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  puStack_1c = &DAT_00442ebc;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_28 = &LAB_00442eab;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c));
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_00442eb2;
  puStack_28 = (undefined1 *)0x442ea5;
  FUN_0043e22c();
  puStack_28 = (undefined1 *)0x442eaa;
  FUN_0041ba34();
  return;
}

