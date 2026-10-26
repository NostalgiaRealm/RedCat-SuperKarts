/*
 * FUN_0040bae4 at 0040bae4
 * undefined FUN_0040bae4(void)
 * Address ranges: 0040bae4-0040baef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040bae4(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}

