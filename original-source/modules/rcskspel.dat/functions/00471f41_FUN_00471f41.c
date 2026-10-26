/*
 * FUN_00471f41 at 00471f41
 * undefined FUN_00471f41(void)
 * Address ranges: 00471f41-00471f9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00471f41(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 unaff_EDI;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 uStack00000018;
  
  *_uStack00000018 = uStack00000018;
  *(undefined4 *)(_uStack00000018 + 4) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 8) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 0xc) = unaff_EDI;
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f6c28;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = &DAT_004f6c28;
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

