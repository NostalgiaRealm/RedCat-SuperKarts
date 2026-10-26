/*
 * FUN_00478b90 at 00478b90
 * undefined FUN_00478b90(void)
 * Address ranges: 00478b90-00478d98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00478b90(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  DWORD DVar5;
  DWORD DVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  byte *pbVar12;
  char *pcVar13;
  undefined4 *puVar14;
  bool bVar15;
  bool bVar16;
  undefined4 uVar17;
  undefined1 *puVar18;
  
  iVar2 = FUN_0047d670();
  if ((DAT_006b6a1c & 1) == 0) {
    DAT_006b6a1c = DAT_006b6a1c | 1;
    DAT_00544e38 = param_1._0_1_;
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar13 = (char *)&DAT_004f7e84;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7 - 1;
    cVar1 = FUN_0040b600(uVar7,1);
    if (cVar1 != '\0') {
      puVar10 = &DAT_004f7e84;
      puVar14 = DAT_00544e3c;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar14 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      FUN_0040b5e0(uVar7);
    }
    DAT_00544e48 = param_1._0_1_;
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar13 = (char *)&DAT_004f7e7c;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7 - 1;
    cVar1 = FUN_0040b600(uVar7,1);
    if (cVar1 != '\0') {
      puVar10 = &DAT_004f7e7c;
      puVar14 = DAT_00544e4c;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar14 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      FUN_0040b5e0(uVar7);
    }
    DAT_00544e58 = param_1._0_1_;
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar13 = (char *)&DAT_004f7e74;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7 - 1;
    cVar1 = FUN_0040b600(uVar7,1);
    if (cVar1 != '\0') {
      puVar10 = &DAT_004f7e74;
      puVar14 = DAT_00544e5c;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar14 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      FUN_0040b5e0(uVar7);
    }
    FUN_004be654(FUN_00479880);
  }
  cVar1 = FUN_00481840();
  if (cVar1 == '\0') {
    iVar3 = FUN_00481730();
    puVar11 = &DAT_00544e38;
    if (iVar3 != 0) {
      puVar11 = &DAT_00544e48;
    }
  }
  else {
    puVar11 = &DAT_00544e58;
  }
  pbVar4 = *(byte **)(iVar2 + 4);
  uVar7 = *(uint *)(iVar2 + 8);
  if (pbVar4 == (byte *)0x0) {
    pbVar4 = &DAT_004d2404;
  }
  uVar8 = *(uint *)(puVar11 + 8);
  uVar9 = uVar8;
  if (uVar7 <= uVar8) {
    uVar9 = uVar7;
  }
  bVar15 = false;
  iVar2 = 0;
  bVar16 = true;
  pbVar12 = *(byte **)(puVar11 + 4);
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    bVar15 = *pbVar12 < *pbVar4;
    bVar16 = *pbVar12 == *pbVar4;
    pbVar12 = pbVar12 + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar16);
  if (!bVar16) {
    iVar2 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  if (((iVar2 != 0) || (uVar8 < uVar7)) || (uVar8 != uVar7)) {
    (**(code **)(*param_1 + 0x14))(2);
    FUN_0047f750();
    FUN_0047f6f0();
    DVar5 = GetTickCount();
    DVar6 = GetTickCount();
    uVar7 = DVar6 - DVar5;
    while (uVar7 < 500) {
      FUN_004baf80();
      DVar6 = GetTickCount();
      uVar7 = DVar6 - DVar5;
    }
  }
  uVar17 = 0;
  FUN_00477f10(0);
  FUN_00477fd0(uVar17);
  puVar18 = &DAT_00545040;
  FUN_0047f750(&DAT_00545040);
  FUN_0047fa30(puVar18);
  return;
}

