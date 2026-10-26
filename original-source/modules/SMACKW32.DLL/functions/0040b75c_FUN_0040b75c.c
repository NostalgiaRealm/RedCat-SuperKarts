/*
 * FUN_0040b75c at 0040b75c
 * undefined FUN_0040b75c(void)
 * Address ranges: 0040b75c-0040b767
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b75c(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}

