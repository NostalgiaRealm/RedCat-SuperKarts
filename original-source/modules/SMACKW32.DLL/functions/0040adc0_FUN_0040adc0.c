/*
 * FUN_0040adc0 at 0040adc0
 * undefined FUN_0040adc0(void)
 * Address ranges: 0040adc0-0040adce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040adc0(undefined4 param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 0x18);
  return CONCAT22((ushort)bVar1 | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(bVar1,(char)((uint)param_2 >> 8)));
}

