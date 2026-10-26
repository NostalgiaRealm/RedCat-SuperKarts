/*
 * FUN_0040b798 at 0040b798
 * undefined FUN_0040b798(void)
 * Address ranges: 0040b798-0040b7a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b798(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return ((uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18) >> 0x10 |
         (uint)uVar1 << 0x10;
}

