/*
 * FUN_00476790 at 00476790
 * undefined FUN_00476790(void)
 * Address ranges: 00476790-004768c6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x004767cf) */

undefined1 * FUN_00476790(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  char cVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  FUN_00476510(param_2);
  puVar4 = (undefined1 *)FUN_00475110();
  uVar1 = *puVar4;
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = uVar1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar2 = *(uint *)(puVar4 + 8);
  if (param_1 == puVar4) {
    if (uVar2 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar5 = *(int *)(param_1 + 8) - uVar2;
    iVar8 = -1;
    if (iVar5 != -1) {
      iVar8 = iVar5;
    }
    if (iVar8 != 0) {
      FUN_004bef90(uVar2 + *(int *)(param_1 + 4),uVar2 + *(int *)(param_1 + 4) + iVar8,iVar5 - iVar8
                  );
      iVar5 = *(int *)(param_1 + 8);
      cVar3 = FUN_0040b600(iVar5 - iVar8,0);
      if (cVar3 != '\0') {
        FUN_0040b5e0(iVar5 - iVar8);
      }
    }
    FUN_00412a80();
    return param_1;
  }
  if (uVar2 != 0) {
    puVar6 = *(undefined1 **)(puVar4 + 4);
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_004d2404;
    }
    if ((byte)puVar6[-1] < 0xfe) {
      FUN_0040b4f0(1);
      puVar6 = *(undefined1 **)(puVar4 + 4);
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_004d2404;
      }
      *(undefined1 **)(param_1 + 4) = puVar6;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(puVar4 + 8);
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(puVar4 + 0xc);
      puVar6[-1] = puVar6[-1] + '\x01';
      return param_1;
    }
  }
  cVar3 = FUN_0040b600(uVar2,1);
  if (cVar3 != '\0') {
    puVar9 = *(undefined4 **)(puVar4 + 4);
    if (puVar9 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)&DAT_004d2404;
    }
    puVar10 = *(undefined4 **)(param_1 + 4);
    for (uVar7 = uVar2 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar7 = uVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    *(uint *)(param_1 + 8) = uVar2;
    *(undefined1 *)(*(int *)(param_1 + 4) + uVar2) = 0;
  }
  return param_1;
}

