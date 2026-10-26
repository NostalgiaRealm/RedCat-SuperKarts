/*
 * FUN_0043eb40 at 0043eb40
 * bool __register FUN_0043eb40(int param_1)
 * Address ranges: 0043eb40-0043eb55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0043eb40(int param_1)

{
  return (&DAT_0047b900)[*(byte *)(param_1 + 0x4b)] != *(char *)(param_1 + 0x51);
}

