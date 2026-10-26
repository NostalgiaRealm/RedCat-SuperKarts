/*
 * _SmackToBuffer@28 at 004036e0
 * undefined __fastcall _SmackToBuffer@28(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9)
 * Address ranges: 004036e0-004038fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall
_SmackToBuffer_28(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8,int param_9)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 extraout_ECX;
  undefined4 uVar6;
  undefined4 extraout_EDX;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  int local_18;
  uint local_14;
  
                    /* 0x36e0  23  _SmackToBuffer@28 */
  if (param_3 == 0) {
    return;
  }
  if (param_8 == 0) {
    if (*(int *)(param_3 + 0x3a0) == 0) {
      return;
    }
    FUN_00402c10();
    *(undefined4 *)(param_3 + 0x3a0) = 0;
    *(int *)(param_3 + 0x45c) = *(int *)(param_3 + 0x45c) - *(int *)(param_3 + 0x3a4);
    return;
  }
  bVar1 = *(byte *)(param_3 + 0x386);
  uVar6 = CONCAT31((int3)((uint)param_2 >> 8),bVar1);
  local_18 = 3;
  uVar3 = *(uint *)(param_3 + 8) >> 1;
  if ((bVar1 & 0x10) == 0) {
    iVar8 = param_6;
    local_14 = *(uint *)(param_3 + 8);
    if ((bVar1 & 0x20) != 0) {
      local_18 = 7;
      local_14 = uVar3;
    }
  }
  else {
    iVar8 = param_6 * 2;
    local_14 = uVar3;
  }
  if (*(char **)(param_3 + 0x3a0) != (char *)0x0) {
    if (**(char **)(param_3 + 0x3a0) == '\x01') goto LAB_00403805;
    FUN_00402c10();
    *(int *)(param_3 + 0x45c) = *(int *)(param_3 + 0x45c) - *(int *)(param_3 + 0x3a4);
    uVar6 = extraout_EDX;
  }
  uVar9 = FUN_0040d520(*(undefined4 *)(param_3 + 4),uVar6,*(undefined4 *)(param_3 + 4),local_14);
  uVar3 = (int)uVar9 + 0x20;
  *(uint *)(param_3 + 0x3a4) = uVar3;
  uVar4 = *(int *)(param_3 + 0x45c) + uVar3;
  *(uint *)(param_3 + 0x45c) = uVar4;
  if (*(uint *)(param_3 + 0x49c) < uVar4) {
    *(uint *)(param_3 + 0x49c) = uVar4;
  }
  puVar5 = (undefined4 *)FUN_00402c30(extraout_ECX,uVar3,uVar3);
  *(undefined4 **)(param_3 + 0x3a0) = puVar5;
  if (puVar5 == (undefined4 *)0x0) {
    return;
  }
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
LAB_00403805:
  *(int *)(param_3 + 0x38c) = param_5;
  *(int *)(param_3 + 0x388) = param_4;
  puVar2 = *(undefined1 **)(param_3 + 0x3a0);
  *puVar2 = 1;
  puVar2[1] = (*(byte *)(param_3 + 0x386) & 0x20) != 0;
  if (param_9 != 0) {
    param_5 = (param_7 - param_5) + -1;
  }
  iVar7 = local_18 * iVar8;
  *(int *)(puVar2 + 4) = param_5 * param_6 + param_8 + param_4;
  *(uint *)(puVar2 + 8) = *(uint *)(param_3 + 4) >> 2;
  *(uint *)(puVar2 + 0xc) = local_14 >> 2;
  if (param_9 == 0) {
    *(int *)(puVar2 + 0x10) = iVar7 + -4;
    *(int *)(puVar2 + 0x14) = iVar7;
    *(int *)(puVar2 + 0x18) = iVar8;
    *(int *)(puVar2 + 0x1c) = iVar7 + (iVar8 - *(int *)(param_3 + 4));
  }
  else {
    *(int *)(puVar2 + 0x10) = -(iVar7 + 4);
    *(int *)(puVar2 + 0x14) = -iVar7;
    *(int *)(puVar2 + 0x18) = -iVar8;
    *(int *)(puVar2 + 0x1c) = -(iVar8 * (local_18 + 2) - (iVar8 - *(int *)(param_3 + 4)));
  }
  *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(param_3 + 4);
  *(uint *)(puVar2 + 0x28) = local_14;
  return;
}

