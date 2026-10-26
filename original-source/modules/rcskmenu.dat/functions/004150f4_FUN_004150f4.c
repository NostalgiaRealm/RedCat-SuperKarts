/*
 * FUN_004150f4 at 004150f4
 * undefined4 __register FUN_004150f4(int param_1)
 * Address ranges: 004150f4-0041510d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004150f4(int param_1)

{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x3a) != 0) {
    uVar1 = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c),param_1);
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return 0;
}

