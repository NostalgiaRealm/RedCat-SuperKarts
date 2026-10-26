/*
 * FUN_00406bb0 at 00406bb0
 * uint __register FUN_00406bb0(uint param_1, int param_2)
 * Address ranges: 00406bb0-00406bbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00406bb0(uint param_1,int param_2)

{
  return param_1 & 0xffff | param_2 << 0x10;
}

