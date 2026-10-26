/*
 * FUN_0042fb48 at 0042fb48
 * undefined __register FUN_0042fb48(int param_1)
 * Address ranges: 0042fb48-0042fb7f;0042fb97-0042fb9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042fb48(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  if (*(short *)(param_1 + 0x3a) != 0) {
    puStack_1c = &LAB_0042fb80;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c),param_1);
    *in_FS_OFFSET = uStack_20;
  }
  return;
}

