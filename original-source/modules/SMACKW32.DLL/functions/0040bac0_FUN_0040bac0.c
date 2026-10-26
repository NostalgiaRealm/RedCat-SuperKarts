/*
 * FUN_0040bac0 at 0040bac0
 * undefined FUN_0040bac0(void)
 * Address ranges: 0040bac0-0040bacb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040bac0(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return CONCAT31(uVar1 >> 8 |
                  (uint3)((uint)(CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18) >> 8),
                  (char)((uint)param_2 >> 0x10));
}

