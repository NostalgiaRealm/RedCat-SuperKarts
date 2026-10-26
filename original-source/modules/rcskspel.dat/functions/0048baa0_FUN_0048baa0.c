/*
 * FUN_0048baa0 at 0048baa0
 * undefined FUN_0048baa0(void)
 * Address ranges: 0048baa0-0048bc8c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0048baa0(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  
  puVar3 = operator_new(0x10);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar3 + 4) = 0;
    *puVar3 = (undefined1)param_2;
    *(undefined4 *)(puVar3 + 8) = 0;
    *(undefined4 *)(puVar3 + 0xc) = 0;
  }
  *(undefined1 **)(param_1 + 4) = puVar3;
  puVar1 = *(undefined1 **)(param_2 + 4);
  if (puVar3 == puVar1) {
    return param_1;
  }
  puVar2 = *(undefined4 **)(puVar1 + 4);
  if (puVar2 == (undefined4 *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(int *)(puVar1 + 8) - (int)puVar2 >> 5;
  }
  puVar11 = *(undefined4 **)(puVar3 + 4);
  if (puVar11 == (undefined4 *)0x0) {
    uVar10 = 0;
  }
  else {
    uVar10 = *(int *)(puVar3 + 8) - (int)puVar11 >> 5;
  }
  if (uVar7 <= uVar10) {
    puVar9 = *(undefined4 **)(puVar1 + 8);
    while (puVar2 != puVar9) {
      puVar13 = puVar2;
      puVar14 = puVar11;
      for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar14 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar14 = puVar14 + 1;
      }
      puVar11 = puVar11 + 8;
      puVar2 = puVar2 + 8;
    }
    if (*(int *)(puVar1 + 4) != 0) {
      *(int *)(puVar3 + 8) =
           (*(int *)(puVar1 + 8) - *(int *)(puVar1 + 4) >> 5) * 0x20 + *(int *)(puVar3 + 4);
      return param_1;
    }
    *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(puVar3 + 4);
    return param_1;
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(int *)(puVar1 + 8) - (int)puVar2 >> 5;
  }
  if (puVar11 == (undefined4 *)0x0) {
    uVar10 = 0;
  }
  else {
    uVar10 = *(int *)(puVar3 + 0xc) - (int)puVar11 >> 5;
  }
  if (uVar10 < uVar7) {
    FUN_004bc150(puVar11);
    iVar8 = FUN_0048b1b0();
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    pvVar5 = operator_new(iVar8 << 5);
    *(void **)(puVar3 + 4) = pvVar5;
    uVar6 = FUN_0048ba30(*(undefined4 *)(puVar1 + 4),*(undefined4 *)(puVar1 + 8),pvVar5);
    *(undefined4 *)(puVar3 + 8) = uVar6;
    *(undefined4 *)(puVar3 + 0xc) = uVar6;
    return param_1;
  }
  if (puVar11 == (undefined4 *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(puVar3 + 8) - (int)puVar11 >> 5;
  }
  puVar9 = puVar2 + iVar8 * 8;
  while (puVar2 != puVar9) {
    puVar4 = puVar2 + 8;
    puVar12 = puVar11 + 8;
    puVar13 = puVar2;
    puVar14 = puVar11;
    for (iVar8 = 8; puVar2 = puVar4, puVar11 = puVar12, iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
  }
  iVar8 = *(int *)(puVar3 + 8);
  puVar2 = *(undefined4 **)(puVar1 + 8);
  for (; puVar9 != puVar2; puVar9 = puVar9 + 8) {
    FUN_0048bc90(iVar8,puVar9);
    iVar8 = iVar8 + 0x20;
  }
  if (*(int *)(puVar1 + 4) != 0) {
    *(int *)(puVar3 + 8) =
         (*(int *)(puVar1 + 8) - *(int *)(puVar1 + 4) >> 5) * 0x20 + *(int *)(puVar3 + 4);
    return param_1;
  }
  *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(puVar3 + 4);
  return param_1;
}

