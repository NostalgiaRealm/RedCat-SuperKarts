/*
 * FUN_0044b450 at 0044b450
 * undefined FUN_0044b450(void)
 * Address ranges: 0044b450-0044b6a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044b481) */

int __thiscall FUN_0044b450(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint local_8;
  
  FUN_00412870(param_2 + 4,0,0xffffffff);
  uVar7 = *(uint *)(param_2 + 0x1c);
  if (param_1 + 0x14 == param_2 + 0x14) {
    FUN_004478a0(uVar7,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar7 != 0) {
      puVar3 = *(undefined1 **)(param_2 + 0x18);
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      if ((byte)puVar3[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar3 = *(undefined1 **)(param_2 + 0x18);
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 0x18) = puVar3;
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
        puVar3[-1] = puVar3[-1] + '\x01';
        goto LAB_0044b528;
      }
    }
    cVar2 = FUN_0040b600(uVar7,1);
    if (cVar2 != '\0') {
      puVar10 = *(undefined4 **)(param_2 + 0x18);
      if (puVar10 == (undefined4 *)0x0) {
        puVar10 = (undefined4 *)&DAT_004d2404;
      }
      puVar11 = *(undefined4 **)(param_1 + 0x18);
      for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar4 = uVar7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      FUN_0040b5e0(uVar7);
    }
  }
LAB_0044b528:
  if (param_1 + 0x24 != param_2 + 0x24) {
    iVar8 = *(int *)(param_2 + 0x28);
    if (iVar8 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = (*(int *)(param_2 + 0x2c) - iVar8) / 0x60;
    }
    iVar9 = *(int *)(param_1 + 0x28);
    if (iVar9 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (*(int *)(param_1 + 0x2c) - iVar9) / 0x60;
    }
    if (uVar7 < local_8) {
      uVar7 = FUN_0044b7a0();
      uVar4 = FUN_0044b770();
      if (uVar4 < uVar7) {
        FUN_0044aa50(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
        FUN_004bc150(*(undefined4 *)(param_1 + 0x28));
        iVar8 = FUN_0044b7a0();
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        pvVar5 = operator_new(iVar8 * 0x60);
        *(void **)(param_1 + 0x28) = pvVar5;
        uVar6 = FUN_0044b7d0(*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_2 + 0x2c),pvVar5)
        ;
        *(undefined4 *)(param_1 + 0x2c) = uVar6;
        *(undefined4 *)(param_1 + 0x30) = uVar6;
      }
      else {
        iVar8 = *(int *)(param_2 + 0x28);
        iVar9 = FUN_0044b7a0();
        iVar8 = iVar9 * 0x60 + iVar8;
        FUN_0044bb50(*(undefined4 *)(param_2 + 0x28),iVar8,*(undefined4 *)(param_1 + 0x28));
        FUN_0044b7d0(iVar8,*(undefined4 *)(param_2 + 0x2c),*(undefined4 *)(param_1 + 0x2c));
        iVar8 = FUN_0044b7a0();
        *(int *)(param_1 + 0x2c) = iVar8 * 0x60 + *(int *)(param_1 + 0x28);
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x2c);
      for (; iVar8 != iVar1; iVar8 = iVar8 + 0x60) {
        FUN_0044c670(iVar8);
        iVar9 = iVar9 + 0x60;
      }
      FUN_0044aa50(iVar9,*(undefined4 *)(param_1 + 0x2c));
      iVar8 = FUN_0044b7a0();
      *(int *)(param_1 + 0x2c) = iVar8 * 0x60 + *(int *)(param_1 + 0x28);
    }
  }
  FUN_00439490(param_2 + 0x34);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
  return param_1;
}

