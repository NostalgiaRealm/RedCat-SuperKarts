/*
 * FUN_0040b5cc at 0040b5cc
 * undefined FUN_0040b5cc(void)
 * Address ranges: 0040b5cc-0040b5d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b5cc(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)((uint)param_2 >> 8))
                  );
  return uVar1 >> 8 | uVar1 << 0x18;
}

