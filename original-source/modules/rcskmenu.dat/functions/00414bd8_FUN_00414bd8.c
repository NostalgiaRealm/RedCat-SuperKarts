/*
 * FUN_00414bd8 at 00414bd8
 * undefined __register FUN_00414bd8(int param_1)
 * Address ranges: 00414bd8-00414be1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414bd8(int param_1)

{
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) & 0xfffe;
  return;
}

