/*
 * FUN_0046063c at 0046063c
 * bool __register FUN_0046063c(int param_1)
 * Address ranges: 0046063c-00460643
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0046063c(int param_1)

{
  return (*(byte *)(param_1 + 0x20) & 0x10) != 0;
}

