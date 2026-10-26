/*
 * FUN_00476ca0 at 00476ca0
 * undefined FUN_00476ca0(void)
 * Address ranges: 00476ca0-0047705e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00476ca0(int param_1,int param_2,uint param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  
  iVar4 = *(int *)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - iVar4) / 0x60) < param_3) {
    iVar2 = *(int *)(param_1 + 4);
    if ((iVar2 == 0) || (uVar5 = (iVar4 - iVar2) / 0x60, uVar5 <= param_3)) {
      uVar5 = param_3;
    }
    if (iVar2 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (iVar4 - iVar2) / 0x60;
    }
    iVar4 = iVar4 + uVar5;
    iVar2 = iVar4;
    if (iVar4 < 0) {
      iVar2 = 0;
    }
    pvVar3 = operator_new(iVar2 * 0x60);
    pvVar6 = pvVar3;
    for (iVar2 = *(int *)(param_1 + 4); uVar5 = param_3, pvVar1 = pvVar6, iVar2 != param_2;
        iVar2 = iVar2 + 0x60) {
      FUN_004771b0(pvVar6,iVar2);
      pvVar6 = (void *)((int)pvVar6 + 0x60);
    }
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      FUN_004771b0(pvVar1,param_4);
      pvVar1 = (void *)((int)pvVar1 + 0x60);
    }
    pvVar6 = (void *)(param_3 * 0x60 + (int)pvVar6);
    iVar2 = *(int *)(param_1 + 8);
    for (; param_2 != iVar2; param_2 = param_2 + 0x60) {
      FUN_004771b0(pvVar6,param_2);
      pvVar6 = (void *)((int)pvVar6 + 0x60);
    }
    iVar2 = *(int *)(param_1 + 8);
    for (iVar7 = *(int *)(param_1 + 4); iVar7 != iVar2; iVar7 = iVar7 + 0x60) {
      FUN_0042e9a0();
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(void **)(param_1 + 0xc) = (void *)(iVar4 * 0x60 + (int)pvVar3);
    if (*(int *)(param_1 + 4) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x60;
    }
    *(void **)(param_1 + 4) = pvVar3;
    *(void **)(param_1 + 8) = (void *)((param_3 + iVar4) * 0x60 + (int)pvVar3);
    return;
  }
  if ((uint)((iVar4 - param_2) / 0x60) < param_3) {
    iVar2 = param_3 * 0x60 + param_2;
    for (iVar7 = param_2; iVar7 != iVar4; iVar7 = iVar7 + 0x60) {
      FUN_004771b0(iVar2,iVar7);
      iVar2 = iVar2 + 0x60;
    }
    iVar4 = *(int *)(param_1 + 8);
    for (iVar2 = param_3 - (iVar4 - param_2) / 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_004771b0(iVar4,param_4);
      iVar4 = iVar4 + 0x60;
    }
    iVar4 = *(int *)(param_1 + 8);
    for (; param_2 != iVar4; param_2 = param_2 + 0x60) {
      FUN_00477320(param_4);
    }
  }
  else {
    if (param_3 == 0) {
      return;
    }
    iVar2 = iVar4;
    for (iVar7 = iVar4 + param_3 * -0x60; iVar7 != iVar4; iVar7 = iVar7 + 0x60) {
      FUN_004771b0(iVar2,iVar7);
      iVar2 = iVar2 + 0x60;
    }
    iVar4 = *(int *)(param_1 + 8) + param_3 * -0x60;
    if (param_2 != iVar4) {
      iVar2 = iVar4 + 0x20;
      do {
        iVar4 = iVar4 + -0x60;
        FUN_00412870(iVar4,0,0xffffffff);
        FUN_00412870(iVar2 + -0x70,0,0xffffffff);
        FUN_00412870(iVar2 + -0x60,0,0xffffffff);
        FUN_00412870(iVar2 + -0x50,0,0xffffffff);
        FUN_00412870(iVar2 + -0x40,0,0xffffffff);
        FUN_004775e0(iVar2 + -0x30);
        iVar2 = iVar2 + -0x60;
      } while (iVar4 != param_2);
    }
    iVar4 = param_3 * 0x60 + param_2;
    if (param_2 != iVar4) {
      iVar2 = param_2 + 0x20;
      do {
        FUN_00412870(param_4,0,0xffffffff);
        FUN_00412870(param_4 + 0x10,0,0xffffffff);
        FUN_00412870(param_4 + 0x20,0,0xffffffff);
        FUN_00412870(param_4 + 0x30,0,0xffffffff);
        FUN_00412870(param_4 + 0x40,0,0xffffffff);
        FUN_004775e0(param_4 + 0x50);
        iVar7 = iVar2 + 0x40;
        iVar2 = iVar2 + 0x60;
      } while (iVar7 != iVar4);
    }
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x60;
  return;
}

