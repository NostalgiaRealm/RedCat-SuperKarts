/*
 * FUN_0040191e at 0040191e
 * undefined __cdecl FUN_0040191e(byte * param_1, byte * param_2, byte * param_3, byte * param_4, byte * param_5)
 * Address ranges: 0040191e-004019ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040191e(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if ((param_2 != (byte *)0x0) && (*param_2 != 0)) {
    *param_1 = *param_2;
    param_1[1] = 0x3a;
    param_1 = param_1 + 2;
  }
  if ((param_3 != (byte *)0x0) && (bVar1 = *param_3, pbVar2 = param_3, bVar1 != 0)) {
    do {
      pbVar3 = param_1;
      *pbVar3 = bVar1;
      bVar1 = pbVar2[1];
      param_1 = pbVar3 + 1;
      pbVar2 = pbVar2 + 1;
    } while (bVar1 != 0);
    pbVar2 = FUN_0040334e(param_3,pbVar2);
    if ((*pbVar2 != 0x2f) && (*pbVar2 != 0x5c)) {
      *param_1 = 0x5c;
      param_1 = pbVar3 + 2;
    }
  }
  if (param_4 != (byte *)0x0) {
    bVar1 = *param_4;
    while (bVar1 != 0) {
      *param_1 = bVar1;
      pbVar2 = param_4 + 1;
      param_1 = param_1 + 1;
      param_4 = param_4 + 1;
      bVar1 = *pbVar2;
    }
  }
  if (param_5 == (byte *)0x0) {
    *param_1 = 0;
  }
  else {
    if ((*param_5 != 0) && (*param_5 != 0x2e)) {
      *param_1 = 0x2e;
      param_1 = param_1 + 1;
    }
    do {
      bVar1 = *param_5;
      *param_1 = bVar1;
      param_1 = param_1 + 1;
      param_5 = param_5 + 1;
    } while (bVar1 != 0);
  }
  return;
}

