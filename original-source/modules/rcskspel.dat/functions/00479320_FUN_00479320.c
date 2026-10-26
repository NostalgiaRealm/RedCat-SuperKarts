/*
 * FUN_00479320 at 00479320
 * undefined FUN_00479320(void)
 * Address ranges: 00479320-004794ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00479320(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  char *pcVar11;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  undefined1 uStack_9;
  byte *pbStack_8;
  int iStack_4;
  
  if ((DAT_006b6a1c & 1) == 0) {
    DAT_006b6a1c = DAT_006b6a1c | 1;
    DAT_00544e38 = uStack_9;
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar11 = (char *)&DAT_004f7e84;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      puVar7 = &DAT_004f7e84;
      puVar10 = DAT_00544e3c;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      DAT_00544e40 = uVar3;
      *(undefined1 *)((int)DAT_00544e3c + uVar3) = 0;
    }
    DAT_00544e48 = uStack_9;
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar11 = (char *)&DAT_004f7e7c;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      puVar7 = &DAT_004f7e7c;
      puVar10 = DAT_00544e4c;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      FUN_0040b5e0(uVar3);
    }
    DAT_00544e58 = uStack_9;
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar11 = (char *)&DAT_004f7e74;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(&DAT_004f7e74,~uVar3 - 1);
    FUN_004be654(FUN_00479880);
  }
  cVar1 = FUN_00481840();
  if (cVar1 == '\0') {
    iVar6 = FUN_00481730();
    puVar8 = &DAT_00544e38;
    if (iVar6 != 0) {
      puVar8 = &DAT_00544e48;
    }
  }
  else {
    puVar8 = &DAT_00544e58;
  }
  iVar2 = FUN_0047f750();
  iVar6 = *(int *)(iVar2 + 0x74);
  iStack_4 = *(int *)(iVar2 + 0x78);
  if (iVar6 != iStack_4) {
    uVar3 = *(uint *)(puVar8 + 8);
    pbStack_8 = *(byte **)(puVar8 + 4);
    do {
      pbVar12 = &DAT_004d2404;
      if (pbStack_8 != (byte *)0x0) {
        pbVar12 = pbStack_8;
      }
      uVar4 = *(uint *)(iVar6 + 8);
      uVar5 = uVar4;
      if (uVar3 <= uVar4) {
        uVar5 = uVar3;
      }
      bVar13 = false;
      iVar2 = 0;
      bVar14 = true;
      pbVar9 = *(byte **)(iVar6 + 4);
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar13 = *pbVar9 < *pbVar12;
        bVar14 = *pbVar9 == *pbVar12;
        pbVar9 = pbVar9 + 1;
        pbVar12 = pbVar12 + 1;
      } while (bVar14);
      if (!bVar14) {
        iVar2 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      }
      if (((iVar2 == 0) && (uVar3 <= uVar4)) && (uVar4 == uVar3)) {
        (**(code **)(**(int **)(iVar6 + 0x10) + 0x14))(2);
        return;
      }
      iVar6 = iVar6 + 0x14;
    } while (iVar6 != iStack_4);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&uStack_9,&DAT_004d9d80);
}

