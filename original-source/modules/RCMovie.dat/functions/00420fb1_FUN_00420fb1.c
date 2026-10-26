/*
 * FUN_00420fb1 at 00420fb1
 * byte * __stdcall FUN_00420fb1(void)
 * Address ranges: 00420fb1-00421008
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * FUN_00420fb1(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (DAT_0043f928 == 0) {
    FUN_00424bb9();
  }
  bVar1 = *DAT_0043f934;
  pbVar4 = DAT_0043f934;
  if (bVar1 == 0x22) {
    while( true ) {
      pbVar3 = pbVar4;
      bVar1 = pbVar3[1];
      pbVar4 = pbVar3 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar2 = FUN_004247b3(bVar1);
      if (iVar2 != 0) {
        pbVar4 = pbVar3 + 2;
      }
    }
    if (*pbVar4 == 0x22) goto LAB_00420fee;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
    }
  }
  for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
LAB_00420fee:
  }
  return pbVar4;
}

