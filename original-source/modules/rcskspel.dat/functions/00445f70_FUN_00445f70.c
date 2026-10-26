/*
 * FUN_00445f70 at 00445f70
 * undefined FUN_00445f70(void)
 * Address ranges: 00445f70-004460a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00445f8a) */

void __thiscall FUN_00445f70(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  
  uVar1 = *(uint *)(param_2 + 8);
  if (param_1 + 0x10 == param_2) {
    if (*(uint *)(param_1 + 0x18) < uVar1) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = *(int *)(param_1 + 0x18) - uVar1;
    iVar8 = -1;
    if (iVar3 != -1) {
      iVar8 = iVar3;
    }
    if (iVar8 != 0) {
      iVar6 = uVar1 + *(int *)(param_1 + 0x14);
      FUN_004bef90(iVar6,iVar6 + iVar8,iVar3 - iVar8);
      iVar8 = *(int *)(param_1 + 0x18) - iVar8;
      cVar2 = FUN_0040b600(iVar8,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar8);
      }
    }
    FUN_00412a80();
    return;
  }
  if (uVar1 != 0) {
    puVar4 = *(undefined1 **)(param_2 + 4);
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    if ((byte)puVar4[-1] < 0xfe) {
      iVar8 = *(int *)(param_1 + 0x14);
      if (iVar8 != 0) {
        cVar2 = *(char *)(iVar8 + -1);
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_004bc150((char *)(iVar8 + -1));
        }
        else {
          *(char *)(iVar8 + -1) = cVar2 + -1;
        }
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      puVar4 = *(undefined1 **)(param_2 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      *(undefined1 **)(param_1 + 0x14) = puVar4;
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0xc);
      puVar4[-1] = puVar4[-1] + '\x01';
      return;
    }
  }
  cVar2 = FUN_0040b600(uVar1,1);
  if (cVar2 != '\0') {
    puVar7 = (undefined4 *)&DAT_004d2404;
    if (*(undefined4 **)(param_2 + 4) != (undefined4 *)0x0) {
      puVar7 = *(undefined4 **)(param_2 + 4);
    }
    puVar9 = *(undefined4 **)(param_1 + 0x14);
    for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    *(uint *)(param_1 + 0x18) = uVar1;
    *(undefined1 *)(*(int *)(param_1 + 0x14) + uVar1) = 0;
  }
  return;
}

