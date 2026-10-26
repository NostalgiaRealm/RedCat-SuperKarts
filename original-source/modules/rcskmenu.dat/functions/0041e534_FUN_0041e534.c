/*
 * FUN_0041e534 at 0041e534
 * undefined __register FUN_0041e534(void)
 * Address ranges: 0041e534-0041e595
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e534(void)

{
  BYTE BVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  byte bVar5;
  
  bVar5 = 0;
  iVar2 = MulDiv(8,DAT_0047d684,0x48);
  DAT_0047b378 = -iVar2;
  if (PTR_DAT_0047c9d8[8] != '\0') {
    BVar1 = FUN_0041e4f0();
    if (BVar1 == 0x80) {
      puVar3 = &DAT_0041e598;
      pcVar4 = s_MS_Sans_Serif_0047b37f;
      for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined4 *)pcVar4 = *puVar3;
        puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
        pcVar4 = pcVar4 + ((uint)bVar5 * -2 + 1) * 4;
      }
      iVar2 = MulDiv(9,DAT_0047d684,0x48);
      DAT_0047b378 = -iVar2;
      DAT_0047b37e = 0x80;
    }
  }
  return;
}

