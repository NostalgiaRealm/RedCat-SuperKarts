/*
 * FUN_0040ae94 at 0040ae94
 * undefined FUN_0040ae94(void)
 * Address ranges: 0040ae94-0040aea2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040ae94(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return CONCAT22(uVar1 >> 8 |
                  (ushort)((uint)(CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x18) >>
                          0x10),(short)param_2);
}

