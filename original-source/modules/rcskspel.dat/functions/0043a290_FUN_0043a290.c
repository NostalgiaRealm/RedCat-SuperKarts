/*
 * FUN_0043a290 at 0043a290
 * undefined FUN_0043a290(void)
 * Address ranges: 0043a290-0043a3d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0043a2a9) */

int __thiscall FUN_0043a290(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
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
      iVar6 = uVar1 + *(int *)(param_1 + 4);
      FUN_004bef90(iVar6,iVar6 + iVar7,iVar3 - iVar7);
      iVar7 = *(int *)(param_1 + 8) - iVar7;
      cVar2 = FUN_0040b600(iVar7,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar7);
      }
    }
    FUN_00412a80();
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    return param_1;
  }
  if (uVar1 != 0) {
    puVar4 = *(undefined1 **)(param_2 + 4);
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    if ((byte)puVar4[-1] < 0xfe) {
      iVar7 = *(int *)(param_1 + 4);
      if (iVar7 != 0) {
        cVar2 = *(char *)(iVar7 + -1);
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_004bc150((char *)(iVar7 + -1));
        }
        else {
          *(char *)(iVar7 + -1) = cVar2 + -1;
        }
      }
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      puVar4 = *(undefined1 **)(param_2 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      *(undefined1 **)(param_1 + 4) = puVar4;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
      puVar4[-1] = puVar4[-1] + '\x01';
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
      return param_1;
    }
  }
  cVar2 = FUN_0040b600(uVar1,1);
  if (cVar2 != '\0') {
    puVar8 = *(undefined4 **)(param_2 + 4);
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)&DAT_004d2404;
    }
    puVar9 = *(undefined4 **)(param_1 + 4);
    for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    *(uint *)(param_1 + 8) = uVar1;
    *(undefined1 *)(uVar1 + *(int *)(param_1 + 4)) = 0;
  }
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return param_1;
}

