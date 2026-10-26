/*
 * FUN_00471eb0 at 00471eb0
 * undefined FUN_00471eb0(void)
 * Address ranges: 00471eb0-00471f09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00471eb0(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 unaff_EDI;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 uStack00000018;
  
  uVar2 = 0xffffffff;
  *_uStack00000018 = uStack00000018;
  *(undefined4 *)(_uStack00000018 + 4) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 8) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 0xc) = unaff_EDI;
  pcVar5 = &DAT_004f6c30;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)&DAT_004f6c30;
    puVar6 = *(undefined4 **)(_uStack00000018 + 4);
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    FUN_0040b5e0(uVar2);
  }
  return _uStack00000018;
}

