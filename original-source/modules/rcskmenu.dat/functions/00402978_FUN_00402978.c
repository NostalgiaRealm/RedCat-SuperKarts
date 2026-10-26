/*
 * FUN_00402978 at 00402978
 * undefined __register FUN_00402978(void)
 * Address ranges: 00402978-00402984
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402978(void)

{
  ushort in_FPUStatusWord;
  unkbyte10 in_ST0;
  
  fcos(in_ST0);
  if ((in_FPUStatusWord & 0x400) == 0) {
    return;
  }
  return;
}

