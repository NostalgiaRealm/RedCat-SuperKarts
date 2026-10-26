/*
 * FUN_00402b74 at 00402b74
 * undefined4 __register FUN_00402b74(uint param_1)
 * Address ranges: 00402b74-00402b89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402b74(uint param_1)

{
  DAT_0047d044 = DAT_0047d044 * 0x8088405 + 1;
  return (int)((ulonglong)param_1 * (ulonglong)DAT_0047d044 >> 0x20);
}

