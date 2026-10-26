/*
 * FUN_00476990 at 00476990
 * undefined FUN_00476990(void)
 * Address ranges: 00476990-00476c92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00476990(int param_1,int param_2,uint param_3,int param_4)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  
  iVar5 = *(int *)(param_1 + 8);
  if (param_3 <= (uint)(*(int *)(param_1 + 0xc) - iVar5 >> 5)) {
    if ((uint)(iVar5 - param_2 >> 5) < param_3) {
      iVar3 = param_3 * 0x20 + param_2;
      for (iVar6 = param_2; iVar6 != iVar5; iVar6 = iVar6 + 0x20) {
        FUN_00477060(iVar3,iVar6);
        iVar3 = iVar3 + 0x20;
      }
      iVar5 = *(int *)(param_1 + 8);
      for (iVar3 = param_3 - (iVar5 - param_2 >> 5); iVar3 != 0; iVar3 = iVar3 + -1) {
        FUN_00477060(iVar5,param_4);
        iVar5 = iVar5 + 0x20;
      }
      iVar5 = *(int *)(param_1 + 8);
      if (param_2 != iVar5) {
        do {
          FUN_00412870(param_4,0,0xffffffff);
          FUN_00412870(param_4 + 0x10,0,0xffffffff);
          param_2 = param_2 + 0x20;
        } while (param_2 != iVar5);
        *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x20;
        return;
      }
    }
    else {
      if (param_3 == 0) {
        return;
      }
      iVar3 = iVar5;
      for (iVar6 = iVar5 + param_3 * -0x20; iVar6 != iVar5; iVar6 = iVar6 + 0x20) {
        FUN_00477060(iVar3,iVar6);
        iVar3 = iVar3 + 0x20;
      }
      iVar5 = *(int *)(param_1 + 8) + param_3 * -0x20;
      if (param_2 != iVar5) {
        iVar3 = iVar5 + 0x10;
        do {
          iVar5 = iVar5 + -0x20;
          iVar3 = iVar3 + -0x20;
          FUN_00412870(iVar5,0,0xffffffff);
          FUN_00412870(iVar3,0,0xffffffff);
        } while (iVar5 != param_2);
      }
      iVar5 = param_3 * 0x20 + param_2;
      if (param_2 != iVar5) {
        do {
          FUN_00412870(param_4,0,0xffffffff);
          FUN_00412870(param_4 + 0x10,0,0xffffffff);
          param_2 = param_2 + 0x20;
        } while (param_2 != iVar5);
      }
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x20;
    return;
  }
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (uVar2 = iVar5 - iVar3 >> 5, uVar2 <= param_3)) {
    uVar2 = param_3;
  }
  if (iVar3 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = iVar5 - iVar3 >> 5;
  }
  iVar5 = uVar2 + iVar5;
  iVar3 = iVar5;
  if (iVar5 < 0) {
    iVar3 = 0;
  }
  pvVar4 = operator_new(iVar3 << 5);
  pvVar7 = pvVar4;
  for (iVar3 = *(int *)(param_1 + 4); uVar2 = param_3, pvVar1 = pvVar7, iVar3 != param_2;
      iVar3 = iVar3 + 0x20) {
    FUN_00477060(pvVar7,iVar3);
    pvVar7 = (void *)((int)pvVar7 + 0x20);
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    FUN_00477060(pvVar1,param_4);
    pvVar1 = (void *)((int)pvVar1 + 0x20);
  }
  pvVar7 = (void *)(param_3 * 0x20 + (int)pvVar7);
  iVar3 = *(int *)(param_1 + 8);
  for (; param_2 != iVar3; param_2 = param_2 + 0x20) {
    FUN_00477060(pvVar7,param_2);
    pvVar7 = (void *)((int)pvVar7 + 0x20);
  }
  iVar3 = *(int *)(param_1 + 8);
  for (iVar6 = *(int *)(param_1 + 4); iVar6 != iVar3; iVar6 = iVar6 + 0x20) {
    FUN_00445a40();
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  iVar3 = *(int *)(param_1 + 4);
  *(void **)(param_1 + 0xc) = (void *)(iVar5 * 0x20 + (int)pvVar4);
  if (iVar3 == 0) {
    *(void **)(param_1 + 4) = pvVar4;
    *(void **)(param_1 + 8) = (void *)(param_3 * 0x20 + (int)pvVar4);
    return;
  }
  *(void **)(param_1 + 4) = pvVar4;
  *(void **)(param_1 + 8) =
       (void *)(((*(int *)(param_1 + 8) - iVar3 >> 5) + param_3) * 0x20 + (int)pvVar4);
  return;
}

