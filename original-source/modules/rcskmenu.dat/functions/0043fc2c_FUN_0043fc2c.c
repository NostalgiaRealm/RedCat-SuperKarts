/*
 * FUN_0043fc2c at 0043fc2c
 * undefined4 __register FUN_0043fc2c(int param_1)
 * Address ranges: 0043fc2c-0043fc43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043fc2c(int param_1)

{
  if ((PTR_DAT_0047c9d8[9] != '\0') && (*(char *)(param_1 + 0x4f) != '\0')) {
    return CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  return 0;
}

