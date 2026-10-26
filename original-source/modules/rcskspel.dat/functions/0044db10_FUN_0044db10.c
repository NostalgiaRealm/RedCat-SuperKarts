/*
 * FUN_0044db10 at 0044db10
 * undefined FUN_0044db10(void)
 * Address ranges: 0044db10-0044de37
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044db10(int param_1,int param_2,uint param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - iVar5) / 0x70) < param_3) {
    iVar2 = *(int *)(param_1 + 4);
    if ((iVar2 == 0) || (uVar4 = (iVar5 - iVar2) / 0x70, uVar4 <= param_3)) {
      uVar4 = param_3;
    }
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (iVar5 - iVar2) / 0x70;
    }
    iVar5 = iVar5 + uVar4;
    iVar2 = iVar5;
    if (iVar5 < 0) {
      iVar2 = 0;
    }
    pvVar3 = operator_new(iVar2 * 0x70);
    pvVar6 = pvVar3;
    for (iVar2 = *(int *)(param_1 + 4); uVar4 = param_3, pvVar1 = pvVar6, iVar2 != param_2;
        iVar2 = iVar2 + 0x70) {
      FUN_0044de40(pvVar6,iVar2);
      pvVar6 = (void *)((int)pvVar6 + 0x70);
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      FUN_0044de40(pvVar1,param_4);
      pvVar1 = (void *)((int)pvVar1 + 0x70);
    }
    pvVar6 = (void *)(param_3 * 0x70 + (int)pvVar6);
    iVar2 = *(int *)(param_1 + 8);
    for (; param_2 != iVar2; param_2 = param_2 + 0x70) {
      FUN_0044de40(pvVar6,param_2);
      pvVar6 = (void *)((int)pvVar6 + 0x70);
    }
    iVar2 = *(int *)(param_1 + 8);
    for (iVar7 = *(int *)(param_1 + 4); iVar7 != iVar2; iVar7 = iVar7 + 0x70) {
      FUN_0044d8f0();
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(void **)(param_1 + 0xc) = (void *)(iVar5 * 0x70 + (int)pvVar3);
    if (*(int *)(param_1 + 4) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x70;
    }
    *(void **)(param_1 + 4) = pvVar3;
    *(void **)(param_1 + 8) = (void *)((param_3 + iVar5) * 0x70 + (int)pvVar3);
    return;
  }
  if ((uint)((iVar5 - param_2) / 0x70) < param_3) {
    iVar2 = param_3 * 0x70 + param_2;
    for (iVar7 = param_2; iVar7 != iVar5; iVar7 = iVar7 + 0x70) {
      FUN_0044de40(iVar2,iVar7);
      iVar2 = iVar2 + 0x70;
    }
    iVar5 = *(int *)(param_1 + 8);
    for (iVar2 = param_3 - (iVar5 - param_2) / 0x70; iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_0044de40(iVar5,param_4);
      iVar5 = iVar5 + 0x70;
    }
    iVar5 = *(int *)(param_1 + 8);
    for (; param_2 != iVar5; param_2 = param_2 + 0x70) {
      FUN_0044b450(param_4);
      *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_4 + 0x68);
      *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_4 + 0x6c);
    }
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x70;
    return;
  }
  if (param_3 != 0) {
    iVar2 = iVar5;
    for (iVar7 = iVar5 + param_3 * -0x70; iVar7 != iVar5; iVar7 = iVar7 + 0x70) {
      FUN_0044de40(iVar2,iVar7);
      iVar2 = iVar2 + 0x70;
    }
    iVar5 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 8) + param_3 * -0x70;
    while (param_2 != iVar2) {
      FUN_0044b450(iVar2 + -0x70);
      *(undefined4 *)(iVar5 + -8) = *(undefined4 *)(iVar2 + -8);
      *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar2 + -4);
      iVar5 = iVar5 + -0x70;
      iVar2 = iVar2 + -0x70;
    }
    iVar5 = param_2 + param_3 * 0x70;
    for (; param_2 != iVar5; param_2 = param_2 + 0x70) {
      FUN_0044b450(param_4);
      *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_4 + 0x68);
      *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_4 + 0x6c);
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x70;
  }
  return;
}

