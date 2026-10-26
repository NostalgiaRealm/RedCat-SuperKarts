/*
 * FUN_0040ad84 at 0040ad84
 * undefined FUN_0040ad84(void)
 * Address ranges: 0040ad84-0040ad8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040ad84(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 0x18);
  return CONCAT31((uint3)bVar1 | (uint3)(((uint)CONCAT11((char)param_2,(char)param_2) << 0x10) >> 8)
                  ,bVar1);
}

