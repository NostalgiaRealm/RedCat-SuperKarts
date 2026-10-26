/*
 * FUN_0040b0a8 at 0040b0a8
 * undefined FUN_0040b0a8(void)
 * Address ranges: 0040b0a8-0040b0b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b0a8(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = (ushort)((uint)param_2 >> 0x10);
  uVar1 = CONCAT22(uVar2,CONCAT11((char)param_2,(char)((uint)param_2 >> 8)));
  return (uVar1 & 0xffffff) >> 8 | ((uint)(uVar2 >> 8) | uVar1 << 8) << 0x10;
}

