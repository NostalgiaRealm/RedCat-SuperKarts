/*
 * FUN_00480ab0 at 00480ab0
 * undefined FUN_00480ab0(void)
 * Address ranges: 00480ab0-00480dc3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00480ab0(int param_1,int param_2,uint param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 8);
  if (param_3 <= (uint)((*(int *)(param_1 + 0xc) - iVar5) / 0x14)) {
    if (param_3 <= (uint)((iVar5 - param_2) / 0x14)) {
      if (param_3 != 0) {
        iVar2 = iVar5;
        for (iVar7 = iVar5 + param_3 * -0x14; iVar7 != iVar5; iVar7 = iVar7 + 0x14) {
          FUN_00480dd0(iVar2,iVar7);
          iVar2 = iVar2 + 0x14;
        }
        iVar5 = *(int *)(param_1 + 8);
        iVar2 = *(int *)(param_1 + 8) + param_3 * -0x14;
        while (param_2 != iVar2) {
          FUN_00412870(iVar2 + -0x14,0,0xffffffff);
          *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar2 + -4);
          iVar5 = iVar5 + -0x14;
          iVar2 = iVar2 + -0x14;
        }
        iVar5 = param_3 * 0x14 + param_2;
        for (; param_2 != iVar5; param_2 = param_2 + 0x14) {
          FUN_00412870(param_4,0,0xffffffff);
          *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_4 + 0x10);
        }
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x14;
      }
      return;
    }
    iVar2 = param_3 * 0x14 + param_2;
    for (iVar7 = param_2; iVar7 != iVar5; iVar7 = iVar7 + 0x14) {
      FUN_00480dd0(iVar2,iVar7);
      iVar2 = iVar2 + 0x14;
    }
    iVar5 = *(int *)(param_1 + 8);
    for (iVar2 = param_3 - (iVar5 - param_2) / 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_00480dd0(iVar5,param_4);
      iVar5 = iVar5 + 0x14;
    }
    iVar5 = *(int *)(param_1 + 8);
    for (; param_2 != iVar5; param_2 = param_2 + 0x14) {
      FUN_00412870(param_4,0,0xffffffff);
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_4 + 0x10);
    }
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x14;
    return;
  }
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (uVar4 = (iVar5 - iVar2) / 0x14, uVar4 <= param_3)) {
    uVar4 = param_3;
  }
  if (iVar2 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (iVar5 - iVar2) / 0x14;
  }
  iVar5 = iVar5 + uVar4;
  iVar2 = iVar5;
  if (iVar5 < 0) {
    iVar2 = 0;
  }
  pvVar3 = operator_new(iVar2 * 0x14);
  pvVar6 = pvVar3;
  for (iVar2 = *(int *)(param_1 + 4); uVar4 = param_3, pvVar1 = pvVar6, iVar2 != param_2;
      iVar2 = iVar2 + 0x14) {
    FUN_00480dd0(pvVar6,iVar2);
    pvVar6 = (void *)((int)pvVar6 + 0x14);
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    FUN_00480dd0(pvVar1,param_4);
    pvVar1 = (void *)((int)pvVar1 + 0x14);
  }
  pvVar6 = (void *)((int)pvVar6 + param_3 * 0x14);
  iVar2 = *(int *)(param_1 + 8);
  for (; param_2 != iVar2; param_2 = param_2 + 0x14) {
    FUN_00480dd0(pvVar6,param_2);
    pvVar6 = (void *)((int)pvVar6 + 0x14);
  }
  iVar2 = *(int *)(param_1 + 8);
  for (iVar7 = *(int *)(param_1 + 4); iVar7 != iVar2; iVar7 = iVar7 + 0x14) {
    FUN_0040b4b0();
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  iVar2 = *(int *)(param_1 + 4);
  *(void **)(param_1 + 0xc) = (void *)((int)pvVar3 + iVar5 * 0x14);
  if (iVar2 != 0) {
    *(void **)(param_1 + 4) = pvVar3;
    *(void **)(param_1 + 8) =
         (void *)((int)pvVar3 + (param_3 + (*(int *)(param_1 + 8) - iVar2) / 0x14) * 0x14);
    return;
  }
  *(void **)(param_1 + 4) = pvVar3;
  *(void **)(param_1 + 8) = (void *)((int)pvVar3 + param_3 * 0x14);
  return;
}

