/*
 * FUN_00405efe at 00405efe
 * undefined __cdecl FUN_00405efe(byte * param_1, uint param_2)
 * Address ranges: 00405efe-00405f5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00405efe(byte *param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  bool bVar6;
  
  pbVar3 = (byte *)0x0;
  if (DAT_00408dcc == 0) {
    _strrchr((char *)param_1,param_2);
    return;
  }
  do {
    bVar5 = *param_1;
    if ((*(byte *)((int)&DAT_00408ee0 + bVar5 + 1) & 4) == 0) {
      bVar6 = param_2 == bVar5;
LAB_00405f51:
      pbVar4 = param_1;
      if (bVar6) {
        pbVar3 = param_1;
      }
    }
    else {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if (bVar1 == 0) {
        bVar6 = pbVar3 == (byte *)0x0;
        param_1 = pbVar4;
        bVar5 = bVar1;
        goto LAB_00405f51;
      }
      uVar2 = CONCAT11(bVar5,bVar1);
      bVar5 = bVar1;
      if (param_2 == uVar2) {
        pbVar3 = param_1;
      }
    }
    param_1 = pbVar4 + 1;
    if (bVar5 == 0) {
      return;
    }
  } while( true );
}

