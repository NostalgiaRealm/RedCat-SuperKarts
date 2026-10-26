/*
 * FUN_00409fe0 at 00409fe0
 * undefined __stdcall FUN_00409fe0(void)
 * Address ranges: 00409fe0-0040a00f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409fe0(void)

{
  byte *pbVar1;
  uint in_EAX;
  uint uVar2;
  int unaff_ESI;
  byte *pbVar3;
  int unaff_EDI;
  
  pbVar3 = (byte *)(unaff_ESI + 0x7468);
  uVar2 = in_EAX >> 2;
  do {
    while ((*pbVar3 & 1) == 0) {
      pbVar3 = pbVar3 + 4;
      uVar2 = uVar2 - 1;
      if (uVar2 == 0) {
        return;
      }
    }
    pbVar1 = (byte *)(unaff_EDI + (uint)(*(ushort *)(pbVar3 + 2) >> 3));
    *pbVar1 = *pbVar1 | '\x01' << ((byte)*(ushort *)(pbVar3 + 2) & 7);
    pbVar3 = pbVar3 + 4;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}

