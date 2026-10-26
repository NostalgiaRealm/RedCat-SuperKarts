/*
 * FUN_0043152c at 0043152c
 * undefined4 __register FUN_0043152c(int param_1)
 * Address ranges: 0043152c-00431543
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043152c(int param_1)

{
  if ((PTR_DAT_0047c9d8[9] != '\0') && (*(char *)(param_1 + 0x28) != '\0')) {
    return CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  return 0;
}

