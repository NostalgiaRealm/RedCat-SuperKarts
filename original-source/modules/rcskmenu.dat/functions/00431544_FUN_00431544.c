/*
 * FUN_00431544 at 00431544
 * undefined4 __register FUN_00431544(int param_1)
 * Address ranges: 00431544-0043155b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00431544(int param_1)

{
  if ((PTR_DAT_0047c9d8[9] != '\0') && (*(char *)(param_1 + 0x28) == '\x01')) {
    return CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  return 0;
}

