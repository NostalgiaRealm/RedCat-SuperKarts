/*
 * FUN_00403d24 at 00403d24
 * byte * __stdcall FUN_00403d24(void)
 * Address ranges: 00403d24-00403d7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * FUN_00403d24(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (DAT_0040a12c == 0) {
    FUN_00405209();
  }
  bVar1 = *DAT_0040a124;
  pbVar4 = DAT_0040a124;
  if (bVar1 == 0x22) {
    while( true ) {
      pbVar3 = pbVar4;
      bVar1 = pbVar3[1];
      pbVar4 = pbVar3 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar2 = FUN_00405405(bVar1);
      if (iVar2 != 0) {
        pbVar4 = pbVar3 + 2;
      }
    }
    if (*pbVar4 == 0x22) goto LAB_00403d61;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
    }
  }
  for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
LAB_00403d61:
  }
  return pbVar4;
}

