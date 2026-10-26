/*
 * FUN_004150d8 at 004150d8
 * undefined4 __register FUN_004150d8(int param_1)
 * Address ranges: 004150d8-004150f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004150d8(int param_1)

{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x32) != 0) {
    uVar1 = (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x34),param_1);
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return 0;
}

