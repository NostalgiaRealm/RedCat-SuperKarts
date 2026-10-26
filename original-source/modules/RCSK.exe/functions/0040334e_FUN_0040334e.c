/*
 * FUN_0040334e at 0040334e
 * byte * __cdecl FUN_0040334e(byte * param_1, byte * param_2)
 * Address ranges: 0040334e-00403395
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * __cdecl FUN_0040334e(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_2 <= param_1) {
    return (byte *)0x0;
  }
  if (DAT_00408dcc != 0) {
    pbVar1 = param_2 + -1;
    if ((*(byte *)((int)&DAT_00408ee0 + param_2[-1] + 1) & 4) != 0) {
      return param_2 + -2;
    }
    do {
      pbVar1 = pbVar1 + -1;
      if (pbVar1 < param_1) break;
    } while ((*(byte *)((int)&DAT_00408ee0 + *pbVar1 + 1) & 4) != 0);
    param_2 = param_2 + -((int)param_2 - (int)pbVar1 & 1U);
  }
  return param_2 + -1;
}

