/*
 * FUN_0049ed10 at 0049ed10
 * undefined FUN_0049ed10(void)
 * Address ranges: 0049ed10-0049ef7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0049edcc) */
/* WARNING: Removing unreachable block (ram,0x0049ee89) */

void __thiscall FUN_0049ed10(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  
  FUN_0049f2a0(*param_1 != 0,s__s___d__Sound_types_not_allocate_004fc568,
               s_D__work_rcracer_oursoundlib_soun_004fc4a8,0xed);
  FUN_0049f250(param_1[1],0,param_1[2] + -1,s_D__work_rcracer_oursoundlib_soun_004fc4a8,0xef);
  puVar9 = *(undefined1 **)(param_2 + 0x1c);
  if (puVar9 == (undefined1 *)0x0) {
    puVar9 = &DAT_004d2404;
  }
  uVar4 = FUN_004b98e0(puVar9);
  FUN_0049f2a0(uVar4,s__s___d__Can_t_find_filename__s_w_004fc528,
               s_D__work_rcracer_oursoundlib_soun_004fc4a8,0xf6,puVar9);
  iVar1 = param_1[1];
  param_1[1] = iVar1 + 1;
  iVar1 = *param_1 + iVar1 * 0x38;
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  uVar2 = *(uint *)(param_2 + 0x20);
  if (iVar1 + 0x18 == param_2 + 0x18) {
    FUN_004478a0(uVar2,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar2 != 0) {
      puVar9 = *(undefined1 **)(param_2 + 0x1c);
      if (puVar9 == (undefined1 *)0x0) {
        puVar9 = &DAT_004d2404;
      }
      if ((byte)puVar9[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar9 = *(undefined1 **)(param_2 + 0x1c);
        if (puVar9 == (undefined1 *)0x0) {
          puVar9 = &DAT_004d2404;
        }
        *(undefined1 **)(iVar1 + 0x1c) = puVar9;
        *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
        *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
        puVar9[-1] = puVar9[-1] + '\x01';
        goto LAB_0049ee74;
      }
    }
    cVar3 = FUN_0040b600(uVar2,1);
    if (cVar3 != '\0') {
      puVar5 = *(undefined4 **)(param_2 + 0x1c);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)&DAT_004d2404;
      }
      puVar11 = *(undefined4 **)(iVar1 + 0x1c);
      for (uVar7 = uVar2 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar11 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar7 = uVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      *(uint *)(iVar1 + 0x20) = uVar2;
      *(undefined1 *)(*(int *)(iVar1 + 0x1c) + uVar2) = 0;
    }
  }
LAB_0049ee74:
  uVar2 = *(uint *)(param_2 + 0x30);
  if (iVar1 + 0x28 == param_2 + 0x28) {
    if (*(uint *)(iVar1 + 0x30) < uVar2) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar6 = *(int *)(iVar1 + 0x30) - uVar2;
    iVar10 = -1;
    if (iVar6 != -1) {
      iVar10 = iVar6;
    }
    if (iVar10 != 0) {
      iVar8 = uVar2 + *(int *)(iVar1 + 0x2c);
      FUN_004bef90(iVar8,iVar8 + iVar10,iVar6 - iVar10);
      iVar10 = *(int *)(iVar1 + 0x30) - iVar10;
      cVar3 = FUN_0040b600(iVar10,0);
      if (cVar3 != '\0') {
        FUN_0040b5e0(iVar10);
      }
    }
    FUN_004478a0(0,0);
    return;
  }
  if (uVar2 != 0) {
    puVar9 = *(undefined1 **)(param_2 + 0x2c);
    if (puVar9 == (undefined1 *)0x0) {
      puVar9 = &DAT_004d2404;
    }
    if ((byte)puVar9[-1] < 0xfe) {
      FUN_0040b4f0(1);
      puVar9 = *(undefined1 **)(param_2 + 0x2c);
      if (puVar9 == (undefined1 *)0x0) {
        puVar9 = &DAT_004d2404;
      }
      *(undefined1 **)(iVar1 + 0x2c) = puVar9;
      *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
      *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      puVar9[-1] = puVar9[-1] + '\x01';
      return;
    }
  }
  cVar3 = FUN_0040b600(uVar2,1);
  if (cVar3 != '\0') {
    puVar5 = (undefined4 *)&DAT_004d2404;
    if (*(undefined4 **)(param_2 + 0x2c) != (undefined4 *)0x0) {
      puVar5 = *(undefined4 **)(param_2 + 0x2c);
    }
    puVar11 = *(undefined4 **)(iVar1 + 0x2c);
    for (uVar7 = uVar2 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar11 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar11 = puVar11 + 1;
    }
    for (uVar7 = uVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    *(uint *)(iVar1 + 0x30) = uVar2;
    *(undefined1 *)(*(int *)(iVar1 + 0x2c) + uVar2) = 0;
  }
  return;
}

