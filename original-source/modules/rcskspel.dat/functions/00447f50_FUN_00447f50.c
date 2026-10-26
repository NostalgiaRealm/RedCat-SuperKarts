/*
 * FUN_00447f50 at 00447f50
 * undefined FUN_00447f50(void)
 * Address ranges: 00447f50-0044817e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00447f6a) */
/* WARNING: Removing unreachable block (ram,0x0044806a) */

int __thiscall FUN_00447f50(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar1 = *(uint *)(param_2 + 8);
  if (param_1 == param_2) {
    if (*(uint *)(param_1 + 8) < uVar1) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = *(int *)(param_1 + 8) - uVar1;
    iVar7 = -1;
    if (iVar3 != -1) {
      iVar7 = iVar3;
    }
    if (iVar7 != 0) {
      iVar5 = *(int *)(param_1 + 4) + uVar1;
      FUN_004bef90(iVar5,iVar5 + iVar7,iVar3 - iVar7);
      iVar7 = *(int *)(param_1 + 8) - iVar7;
      cVar2 = FUN_0040b600(iVar7,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar7);
      }
    }
    FUN_004478a0(0,0);
  }
  else {
    if (uVar1 != 0) {
      puVar4 = *(undefined1 **)(param_2 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = *(undefined1 **)(param_2 + 4);
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 4) = puVar4;
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_00448051;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar8 = *(undefined4 **)(param_2 + 4);
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)&DAT_004d2404;
      }
      puVar9 = *(undefined4 **)(param_1 + 4);
      for (uVar6 = uVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_0040b5e0(uVar1);
    }
  }
LAB_00448051:
  uVar1 = *(uint *)(param_2 + 0x18);
  if (param_1 + 0x10 == param_2 + 0x10) {
    if (*(uint *)(param_1 + 0x18) < uVar1) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = *(int *)(param_1 + 0x18) - uVar1;
    iVar7 = -1;
    if (iVar3 != -1) {
      iVar7 = iVar3;
    }
    if (iVar7 != 0) {
      iVar5 = *(int *)(param_1 + 0x14) + uVar1;
      FUN_004bef90(iVar5,iVar5 + iVar7,iVar3 - iVar7);
      iVar7 = *(int *)(param_1 + 0x18) - iVar7;
      cVar2 = FUN_0040b600(iVar7,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar7);
      }
    }
    FUN_004478a0(0,0);
  }
  else {
    if (uVar1 != 0) {
      puVar4 = *(undefined1 **)(param_2 + 0x14);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = *(undefined1 **)(param_2 + 0x14);
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 0x14) = puVar4;
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_00448159;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar8 = *(undefined4 **)(param_2 + 0x14);
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)&DAT_004d2404;
      }
      puVar9 = *(undefined4 **)(param_1 + 0x14);
      for (uVar6 = uVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_0040b5e0(uVar1);
    }
  }
LAB_00448159:
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  *(undefined1 *)(param_1 + 0x28) = *(undefined1 *)(param_2 + 0x28);
  *(undefined1 *)(param_1 + 0x29) = *(undefined1 *)(param_2 + 0x29);
  return param_1;
}

