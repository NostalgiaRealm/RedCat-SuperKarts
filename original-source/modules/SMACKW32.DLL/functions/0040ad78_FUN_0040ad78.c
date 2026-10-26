/*
 * FUN_0040ad78 at 0040ad78
 * undefined FUN_0040ad78(void)
 * Address ranges: 0040ad78-0040ad83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040ad78(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}

