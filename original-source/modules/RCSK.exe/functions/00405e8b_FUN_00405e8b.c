/*
 * FUN_00405e8b at 00405e8b
 * byte * __cdecl FUN_00405e8b(byte * param_1, uint param_2)
 * Address ranges: 00405e8b-00405efd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * __cdecl FUN_00405e8b(byte *param_1,uint param_2)

{
  ushort uVar1;
  byte *pbVar2;
  
  if (DAT_00408dcc == 0) {
    pbVar2 = (byte *)_strchr((char *)param_1,param_2);
    return pbVar2;
  }
  while( true ) {
    uVar1 = (ushort)*param_1;
    if (uVar1 == 0) break;
    if ((*(byte *)((int)&DAT_00408ee0 + uVar1 + 1) & 4) == 0) {
      pbVar2 = param_1;
      if (param_2 == uVar1) break;
    }
    else {
      pbVar2 = param_1 + 1;
      if (param_1[1] == 0) {
        return (byte *)0x0;
      }
      if (param_2 == CONCAT11(*param_1,param_1[1])) {
        return param_1;
      }
    }
    param_1 = pbVar2 + 1;
  }
  return (byte *)(~-(uint)(param_2 != uVar1) & (uint)param_1);
}

