/*
 * FUN_0041bed8 at 0041bed8
 * undefined __register FUN_0041bed8(int param_1)
 * Address ranges: 0041bed8-0041bf20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bed8(int param_1)

{
  if (((*(byte *)(param_1 + 0x28) & 3) != 0) && (*(int *)(param_1 + 0x40) == 0)) {
    if (*(short *)(param_1 + 0x26) == 0x10) {
      *(undefined4 *)(param_1 + 0x40) = 0xf800;
      *(undefined4 *)(param_1 + 0x44) = 0x7e0;
      *(undefined4 *)(param_1 + 0x48) = 0x1f;
    }
    else if (*(short *)(param_1 + 0x26) == 0x20) {
      *(undefined4 *)(param_1 + 0x40) = 0xff0000;
      *(undefined4 *)(param_1 + 0x44) = 0xff00;
      *(undefined4 *)(param_1 + 0x48) = 0xff;
    }
  }
  return;
}

