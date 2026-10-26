/*
 * FUN_004053e0 at 004053e0
 * undefined __fastcall FUN_004053e0(undefined4 param_1)
 * Address ranges: 004053e0-0040573a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004053e0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  uint in_EAX;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  undefined4 auStack_330 [192];
  uint local_30;
  uint local_24;
  
  *(undefined4 *)(in_EAX + 0x3f8) = 0;
  local_30 = in_EAX;
  if (-1 < *(int *)(in_EAX + 0x370) - *(int *)(in_EAX + 0xc)) {
    if ((*(byte *)(in_EAX + 0x14) & 1) == 0) {
      *(undefined4 *)(in_EAX + 0x370) = 0;
    }
    else {
      if (*(int *)(in_EAX + 0x370) == *(int *)(in_EAX + 0xc)) {
        if ((*(byte *)(in_EAX + 0x385) & 2) == 0) {
          *(undefined4 *)(in_EAX + 0x3b0) = *(undefined4 *)(in_EAX + 0x3ac);
          FUN_004059b0(param_1,*(undefined4 **)(in_EAX + 0x3ac));
        }
        goto LAB_00405495;
      }
      *(undefined4 *)(in_EAX + 0x370) = 1;
    }
    FUN_00405740(param_1,in_EAX);
  }
LAB_00405495:
  pbVar7 = *(byte **)(local_30 + 0x3b0);
  *(byte **)(local_30 + 0x3c0) = pbVar7;
  bVar4 = *(byte *)(*(int *)(local_30 + 0x3bc) + *(int *)(local_30 + 0x370));
  if ((bVar4 & 1) != 0) {
    pbVar7 = pbVar7 + (uint)*pbVar7 * 4;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 2) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3c4) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 4) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3c8) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 8) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3cc) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x10) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3d0) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x20) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3d4) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x40) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3d8) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x80) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3dc) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  *(byte **)(local_30 + 0x3e0) = pbVar7;
  if ((bVar4 & 1) != 0) {
    iVar1 = *(int *)(local_30 + 0x3b0);
    puVar8 = (undefined4 *)(local_30 + 0x6c);
    local_24 = 0;
    puVar9 = puVar8;
    puVar11 = auStack_330;
    for (iVar5 = 0xc0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    pbVar7 = (byte *)(iVar1 + 1);
    do {
      bVar4 = *pbVar7;
      if ((bVar4 & 0x80) == 0) {
        if ((bVar4 & 0x40) == 0) {
          puVar9 = (undefined4 *)((int)puVar8 + 3);
          uVar2 = *(undefined4 *)pbVar7;
          pbVar7 = pbVar7 + 3;
          local_24 = local_24 + 1;
          *puVar8 = uVar2;
        }
        else {
          bVar4 = (bVar4 & 0x3f) + 1;
          uVar3 = (uint)bVar4 * 3;
          puVar9 = (undefined4 *)((int)auStack_330 + (uint)pbVar7[1] * 3);
          puVar11 = puVar8;
          for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          puVar9 = (undefined4 *)((int)puVar8 + uVar3);
          local_24 = local_24 + bVar4;
          pbVar7 = pbVar7 + 2;
        }
      }
      else {
        bVar4 = (bVar4 & 0x7f) + 1;
        uVar3 = (uint)bVar4 * 3;
        puVar9 = (undefined4 *)((int)auStack_330 + (local_24 & 0xffff) * 3);
        puVar11 = puVar8;
        for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        puVar9 = (undefined4 *)((int)puVar8 + uVar3);
        local_24 = local_24 + bVar4;
        pbVar7 = pbVar7 + 1;
      }
      puVar8 = puVar9;
    } while ((ushort)local_24 < 0x100);
    if (*(int *)(local_30 + 0x3b4) != *(int *)(local_30 + 0x370)) {
      *(undefined4 *)(local_30 + 0x68) = 1;
      return;
    }
  }
  *(undefined4 *)(local_30 + 0x68) = 0;
  return;
}

