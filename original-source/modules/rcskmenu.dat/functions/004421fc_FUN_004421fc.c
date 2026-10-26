/*
 * FUN_004421fc at 004421fc
 * undefined __register FUN_004421fc(int param_1)
 * Address ranges: 004421fc-00442218
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004421fc(int param_1)

{
  *(short *)(param_1 + 0x120) = *(short *)(param_1 + 0x120) + -1;
  if ((*(short *)(param_1 + 0x120) == 0) && ((*(byte *)(param_1 + 0x44) & 0x10) != 0)) {
    FUN_0044221c((int *)param_1);
  }
  return;
}

