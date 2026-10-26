/*
 * FUN_00419f44 at 00419f44
 * undefined __register FUN_00419f44(int param_1)
 * Address ranges: 00419f44-00419f5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419f44(int param_1)

{
  *(undefined1 *)(param_1 + 0x18) = 1;
  if (*(short *)(param_1 + 10) != 0) {
    (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),param_1);
  }
  return;
}

