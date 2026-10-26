/*
 * FUN_0040b264 at 0040b264
 * undefined FUN_0040b264(void)
 * Address ranges: 0040b264-0040b271
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b264(undefined4 param_1,uint param_2)

{
  return param_2 & 0xff | (uint)CONCAT12((char)(param_2 >> 0x18),(short)param_2) << 8;
}

