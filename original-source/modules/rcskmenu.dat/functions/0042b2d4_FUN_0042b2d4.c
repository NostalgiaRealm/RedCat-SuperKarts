/*
 * FUN_0042b2d4 at 0042b2d4
 * undefined __register FUN_0042b2d4(int param_1)
 * Address ranges: 0042b2d4-0042b314;0042b32c-0042b331
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b2d4(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  if (*(short *)(param_1 + 0x2c2) != 0) {
    puStack_1c = &DAT_0042b315;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    (**(code **)(param_1 + 0x2c0))(*(undefined4 *)(param_1 + 0x2c4),param_1);
    *in_FS_OFFSET = uStack_20;
  }
  return;
}

