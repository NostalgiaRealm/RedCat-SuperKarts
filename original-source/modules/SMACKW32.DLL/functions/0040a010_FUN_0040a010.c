/*
 * FUN_0040a010 at 0040a010
 * undefined __stdcall FUN_0040a010(void)
 * Address ranges: 0040a010-0040a03f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a010(void)

{
  undefined2 uVar1;
  uint in_EAX;
  uint uVar2;
  int unaff_ESI;
  byte *pbVar3;
  
  uVar1 = (undefined2)DAT_0040e9d0;
  pbVar3 = (byte *)(unaff_ESI + 0x7468);
  uVar2 = in_EAX >> 2;
  do {
    while ((*pbVar3 & 1) == 0) {
      *(undefined2 *)pbVar3 = uVar1;
      pbVar3 = pbVar3 + 4;
      uVar2 = uVar2 - 1;
      if (uVar2 == 0) {
        return;
      }
    }
    *(undefined2 *)pbVar3 = *(undefined2 *)(pbVar3 + 2);
    pbVar3 = pbVar3 + 4;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}

