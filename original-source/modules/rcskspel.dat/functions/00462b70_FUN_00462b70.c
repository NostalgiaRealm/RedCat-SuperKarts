/*
 * FUN_00462b70 at 00462b70
 * undefined FUN_00462b70(void)
 * Address ranges: 00462b70-00462d1d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00462bd4) */

void __thiscall FUN_00462b70(int *param_1,int *param_2)

{
  uint uVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  bool bVar13;
  bool bVar14;
  
  uVar1 = param_2[2];
  pbVar6 = (byte *)param_2[1];
  pbVar3 = pbVar6;
  if (pbVar6 == (byte *)0x0) {
    pbVar3 = &DAT_004d2404;
  }
  uVar10 = param_1[0x29];
  uVar9 = uVar10;
  if (uVar1 <= uVar10) {
    uVar9 = uVar1;
  }
  bVar13 = false;
  iVar4 = 0;
  bVar14 = true;
  pbVar11 = (byte *)param_1[0x28];
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    bVar13 = *pbVar11 < *pbVar3;
    bVar14 = *pbVar11 == *pbVar3;
    pbVar11 = pbVar11 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar14);
  if (!bVar14) {
    iVar4 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
  }
  if (((iVar4 != 0) || (uVar10 < uVar1)) || (uVar10 != uVar1)) {
    if (param_1 + 0x27 == param_2) {
      if ((uint)param_1[0x29] < uVar1) {
        FUN_004bc243();
      }
      FUN_00412a80();
      iVar5 = param_1[0x29] - uVar1;
      iVar4 = -1;
      if (iVar5 != -1) {
        iVar4 = iVar5;
      }
      if (iVar4 != 0) {
        FUN_004bef90(param_1[0x28] + uVar1,param_1[0x28] + uVar1 + iVar4,iVar5 - iVar4);
        iVar5 = param_1[0x29];
        cVar2 = FUN_0040b600(iVar5 - iVar4,0);
        if (cVar2 != '\0') {
          FUN_0040b5e0(iVar5 - iVar4);
        }
      }
      FUN_00412a80();
      (**(code **)(*param_1 + 0x44))();
      return;
    }
    if (uVar1 != 0) {
      if (pbVar6 == (byte *)0x0) {
        pbVar6 = &DAT_004d2404;
      }
      if (pbVar6[-1] < 0xfe) {
        iVar4 = param_1[0x28];
        if (iVar4 != 0) {
          cVar2 = *(char *)(iVar4 + -1);
          if ((cVar2 == '\0') || (cVar2 == -1)) {
            FUN_004bc150((char *)(iVar4 + -1));
          }
          else {
            *(char *)(iVar4 + -1) = cVar2 + -1;
          }
        }
        param_1[0x28] = 0;
        param_1[0x29] = 0;
        param_1[0x2a] = 0;
        puVar7 = (undefined1 *)param_2[1];
        if (puVar7 == (undefined1 *)0x0) {
          puVar7 = &DAT_004d2404;
        }
        param_1[0x28] = (int)puVar7;
        param_1[0x29] = param_2[2];
        param_1[0x2a] = param_2[3];
        puVar7[-1] = puVar7[-1] + '\x01';
        (**(code **)(*param_1 + 0x44))();
        return;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar8 = (undefined4 *)param_2[1];
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)&DAT_004d2404;
      }
      puVar12 = (undefined4 *)param_1[0x28];
      for (uVar10 = uVar1 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar10 = uVar1 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      FUN_0040b5e0(uVar1);
    }
    (**(code **)(*param_1 + 0x44))();
  }
  return;
}

