/*
 * FUN_0040b384 at 0040b384
 * undefined FUN_0040b384(void)
 * Address ranges: 0040b384-0040b392
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b384(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (byte)((uint)param_2 >> 8);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  return CONCAT22((ushort)bVar1 | (ushort)(((uint)bVar2 << 0x18) >> 0x10),CONCAT11(bVar1,bVar2));
}

