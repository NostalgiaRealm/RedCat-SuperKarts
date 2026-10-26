/*
 * FUN_0040ba40 at 0040ba40
 * undefined FUN_0040ba40(void)
 * Address ranges: 0040ba40-0040ba4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040ba40(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,(short)((uint)param_2 >> 8)) << 8;
}

