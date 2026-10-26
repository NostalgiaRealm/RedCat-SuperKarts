/*
 * FUN_00438fb0 at 00438fb0
 * undefined FUN_00438fb0(void)
 * Address ranges: 00438fb0-0043922d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00438fb0(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  puVar2 = operator_new(0x10);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(puVar2 + 4) = 0;
    *puVar2 = (undefined1)param_2;
    *(undefined4 *)(puVar2 + 8) = 0;
    *(undefined4 *)(puVar2 + 0xc) = 0;
  }
  *(undefined1 **)(param_1 + 4) = puVar2;
  puVar1 = *(undefined1 **)(param_2 + 4);
  if (puVar2 == puVar1) {
    return param_1;
  }
  iVar9 = *(int *)(puVar1 + 4);
  if (iVar9 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (*(int *)(puVar1 + 8) - iVar9) / 0x14;
  }
  uVar5 = 0;
  iVar8 = *(int *)(puVar2 + 4);
  if (iVar8 != 0) {
    uVar5 = (*(int *)(puVar2 + 8) - iVar8) / 0x14;
  }
  if (uVar7 <= uVar5) {
    iVar6 = *(int *)(puVar1 + 8);
    for (; iVar9 != iVar6; iVar9 = iVar9 + 0x14) {
      FUN_0043a290(iVar9);
      iVar8 = iVar8 + 0x14;
    }
    iVar9 = *(int *)(puVar2 + 8);
    for (; iVar8 != iVar9; iVar8 = iVar8 + 0x14) {
      FUN_0043a3e0(0);
    }
    if (*(int *)(puVar1 + 4) == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = (*(int *)(puVar1 + 8) - *(int *)(puVar1 + 4)) / 0x14;
    }
    *(int *)(puVar2 + 8) = *(int *)(puVar2 + 4) + iVar9 * 0x14;
    return param_1;
  }
  if (iVar9 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (*(int *)(puVar1 + 8) - iVar9) / 0x14;
  }
  if (iVar8 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(puVar2 + 0xc) - iVar8) / 0x14;
  }
  if (uVar7 <= uVar5) {
    if (iVar8 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = (*(int *)(puVar2 + 8) - iVar8) / 0x14;
    }
    iVar8 = iVar9 + iVar8 * 0x14;
    for (; iVar9 != iVar8; iVar9 = iVar9 + 0x14) {
      FUN_0043a290(iVar9);
    }
    iVar9 = *(int *)(puVar1 + 8);
    iVar6 = *(int *)(puVar2 + 8);
    for (; iVar8 != iVar9; iVar8 = iVar8 + 0x14) {
      FUN_0043a140(iVar6,iVar8);
      iVar6 = iVar6 + 0x14;
    }
    if (*(int *)(puVar1 + 4) == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = (*(int *)(puVar1 + 8) - *(int *)(puVar1 + 4)) / 0x14;
    }
    *(int *)(puVar2 + 8) = *(int *)(puVar2 + 4) + iVar9 * 0x14;
    return param_1;
  }
  iVar9 = *(int *)(puVar2 + 8);
  for (; iVar8 != iVar9; iVar8 = iVar8 + 0x14) {
    FUN_0043a3e0(0);
  }
  FUN_004bc150(*(undefined4 *)(puVar2 + 4));
  iVar9 = FUN_004398c0();
  if (iVar9 < 0) {
    iVar9 = 0;
  }
  pvVar3 = operator_new(iVar9 * 0x14);
  *(void **)(puVar2 + 4) = pvVar3;
  uVar4 = FUN_00439a80(*(undefined4 *)(puVar1 + 4),*(undefined4 *)(puVar1 + 8),pvVar3);
  *(undefined4 *)(puVar2 + 8) = uVar4;
  *(undefined4 *)(puVar2 + 0xc) = uVar4;
  return param_1;
}

