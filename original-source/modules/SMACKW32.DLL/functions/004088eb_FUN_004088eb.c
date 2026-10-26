/*
 * FUN_004088eb at 004088eb
 * undefined8 __fastcall FUN_004088eb(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004088eb-00408936
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_004088eb(undefined4 param_1,undefined4 param_2)

{
  DAT_0040ef40 = TlsAlloc();
  if ((DAT_0040f049 >> 8 & 0x80) != 0) {
    while ((DAT_0040ef40 != 0xffffffff && (DAT_0040ef40 < 3))) {
      DAT_0040ef40 = TlsAlloc();
    }
  }
  return CONCAT44(param_2,(uint)(DAT_0040ef40 != 0xffffffff));
}

