/*
 * FUN_0040b150 at 0040b150
 * undefined FUN_0040b150(void)
 * Address ranges: 0040b150-0040b159
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b150(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(uVar1,uVar1));
}

