/*
 * FUN_0040ba04 at 0040ba04
 * undefined FUN_0040ba04(void)
 * Address ranges: 0040ba04-0040ba0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040ba04(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  undefined1 uVar2;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  uVar2 = (undefined1)((uint)param_2 >> 8);
  return CONCAT31(uVar1 >> 0x10 | (uint3)((uint)(CONCAT31(uVar1,uVar2) << 0x10) >> 8),uVar2);
}

