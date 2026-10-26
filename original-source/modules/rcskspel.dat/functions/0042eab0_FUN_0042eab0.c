/*
 * FUN_0042eab0 at 0042eab0
 * undefined FUN_0042eab0(void)
 * Address ranges: 0042eab0-0042ebc9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0042ead7) */

undefined1 * __thiscall FUN_0042eab0(undefined1 *param_1,undefined1 *param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar1 = *(uint *)(param_2 + 8);
  if (param_1 == param_2) {
    if (uVar1 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = *(int *)(param_1 + 8) - uVar1;
    iVar6 = -1;
    if (iVar3 != -1) {
      iVar6 = iVar3;
    }
    if (iVar6 != 0) {
      FUN_004bef90(*(int *)(param_1 + 4) + uVar1,*(int *)(param_1 + 4) + uVar1 + iVar6,iVar3 - iVar6
                  );
      iVar3 = *(int *)(param_1 + 8);
      cVar2 = FUN_0040b600(iVar3 - iVar6,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar3 - iVar6);
      }
    }
    FUN_00412a80();
    return param_1;
  }
  if (uVar1 != 0) {
    puVar4 = *(undefined1 **)(param_2 + 4);
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    if ((byte)puVar4[-1] < 0xfe) {
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
      return param_1;
    }
  }
  cVar2 = FUN_0040b600(uVar1,1);
  if (cVar2 != '\0') {
    puVar7 = *(undefined4 **)(param_2 + 4);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)&DAT_004d2404;
    }
    puVar8 = *(undefined4 **)(param_1 + 4);
    for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    FUN_0040b5e0(uVar1);
  }
  return param_1;
}

