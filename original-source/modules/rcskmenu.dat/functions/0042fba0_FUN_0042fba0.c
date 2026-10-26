/*
 * FUN_0042fba0 at 0042fba0
 * undefined FUN_0042fba0(void)
 * Address ranges: 0042fba0-0042fbd7;0042fbef-0042fbf4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042fba0(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  if (*(short *)(param_1 + 0x42) != 0) {
    puStack_1c = &LAB_0042fbd8;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),param_1);
    *in_FS_OFFSET = uStack_20;
  }
  return;
}

