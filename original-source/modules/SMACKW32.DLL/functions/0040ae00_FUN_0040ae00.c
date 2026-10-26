/*
 * FUN_0040ae00 at 0040ae00
 * undefined FUN_0040ae00(void)
 * Address ranges: 0040ae00-0040ae0e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040ae00(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)(CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2)) >>
                 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 0x18)) << 0x18;
}

