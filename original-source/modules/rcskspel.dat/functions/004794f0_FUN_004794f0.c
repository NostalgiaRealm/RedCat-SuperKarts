/*
 * FUN_004794f0 at 004794f0
 * undefined FUN_004794f0(void)
 * Address ranges: 004794f0-00479690
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004794f0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  char *pcVar12;
  bool bVar13;
  bool bVar14;
  
  iVar2 = FUN_0047d670();
  if ((DAT_006b6a1c & 1) == 0) {
    DAT_006b6a1c = DAT_006b6a1c | 1;
    DAT_00544e38 = param_1._0_1_;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar12 = (char *)&DAT_004f7e84;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5 - 1;
    cVar1 = FUN_0040b600(uVar5,1);
    if (cVar1 != '\0') {
      puVar8 = &DAT_004f7e84;
      puVar11 = DAT_00544e3c;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      DAT_00544e40 = uVar5;
      *(undefined1 *)((int)DAT_00544e3c + uVar5) = 0;
    }
    DAT_00544e48 = param_1._0_1_;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar12 = (char *)&DAT_004f7e7c;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5 - 1;
    cVar1 = FUN_0040b600(uVar5,1);
    if (cVar1 != '\0') {
      puVar8 = &DAT_004f7e7c;
      puVar11 = DAT_00544e4c;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      FUN_0040b5e0(uVar5);
    }
    DAT_00544e58 = param_1._0_1_;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar12 = (char *)&DAT_004f7e74;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(&DAT_004f7e74,~uVar5 - 1);
    FUN_004be654(FUN_00479880);
  }
  cVar1 = FUN_00481840();
  if (cVar1 == '\0') {
    iVar3 = FUN_00481730();
    puVar9 = &DAT_00544e38;
    if (iVar3 != 0) {
      puVar9 = &DAT_00544e48;
    }
  }
  else {
    puVar9 = &DAT_00544e58;
  }
  pbVar4 = *(byte **)(iVar2 + 4);
  uVar5 = *(uint *)(iVar2 + 8);
  if (pbVar4 == (byte *)0x0) {
    pbVar4 = &DAT_004d2404;
  }
  uVar6 = *(uint *)(puVar9 + 8);
  uVar7 = uVar6;
  if (uVar5 <= uVar6) {
    uVar7 = uVar5;
  }
  bVar13 = false;
  iVar2 = 0;
  bVar14 = true;
  pbVar10 = *(byte **)(puVar9 + 4);
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    bVar13 = *pbVar10 < *pbVar4;
    bVar14 = *pbVar10 == *pbVar4;
    pbVar10 = pbVar10 + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar14);
  if (!bVar14) {
    iVar2 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
  }
  if (((iVar2 != 0) || (uVar6 < uVar5)) || (uVar6 != uVar5)) {
    (**(code **)(*param_1 + 0x14))(2);
    FUN_0047f750();
    FUN_0047f6f0();
  }
  return;
}

