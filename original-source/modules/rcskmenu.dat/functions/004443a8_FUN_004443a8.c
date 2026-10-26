/*
 * FUN_004443a8 at 004443a8
 * undefined __register FUN_004443a8(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 004443a8-004443cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004443a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(short *)(param_1 + 0x1b2) != 0) {
    (**(code **)(param_1 + 0x1b0))(*(undefined4 *)(param_1 + 0x1b4),param_1,param_2,param_3);
  }
  return;
}

