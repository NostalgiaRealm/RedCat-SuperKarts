/*
 * FUN_0040ae4c at 0040ae4c
 * undefined FUN_0040ae4c(void)
 * Address ranges: 0040ae4c-0040ae55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040ae4c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}

