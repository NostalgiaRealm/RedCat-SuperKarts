/*
 * FUN_0040b1fc at 0040b1fc
 * undefined FUN_0040b1fc(void)
 * Address ranges: 0040b1fc-0040b209
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b1fc(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10)
                   ,(short)param_2);
  return uVar1 >> 8 | uVar1 << 0x18;
}

