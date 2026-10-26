/*
 * FUN_00439ae8 at 00439ae8
 * undefined4 __register FUN_00439ae8(int param_1)
 * Address ranges: 00439ae8-00439aff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00439ae8(int param_1)

{
  if ((PTR_DAT_0047c9d8[9] != '\0') && (*(char *)(param_1 + 0x24) != '\0')) {
    return CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  return 0;
}

