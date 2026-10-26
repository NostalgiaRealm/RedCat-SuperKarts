/*
 * FUN_004c76e0 at 004c76e0
 * undefined FUN_004c76e0(void)
 * Address ranges: 004c76e0-004c7737
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * FUN_004c76e0(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (DAT_006b7dcc == 0) {
    FUN_004c72c4();
  }
  bVar1 = *DAT_006b7dc4;
  pbVar4 = DAT_006b7dc4;
  if (bVar1 == 0x22) {
    while( true ) {
      pbVar3 = pbVar4;
      bVar1 = pbVar3[1];
      pbVar4 = pbVar3 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar2 = FUN_004ca2b9(bVar1);
      if (iVar2 != 0) {
        pbVar4 = pbVar3 + 2;
      }
    }
    if (*pbVar4 == 0x22) goto LAB_004c771d;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
    }
  }
  for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
LAB_004c771d:
  }
  return pbVar4;
}

