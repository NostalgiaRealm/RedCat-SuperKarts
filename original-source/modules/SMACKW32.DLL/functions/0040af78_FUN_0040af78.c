/*
 * FUN_0040af78 at 0040af78
 * undefined FUN_0040af78(void)
 * Address ranges: 0040af78-0040af86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040af78(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return CONCAT22(uVar1 >> 8 |
                  (ushort)((uint)(CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x18) >>
                          0x10),(short)param_2);
}

