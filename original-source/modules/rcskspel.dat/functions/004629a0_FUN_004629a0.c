/*
 * FUN_004629a0 at 004629a0
 * undefined FUN_004629a0(void)
 * Address ranges: 004629a0-00462b3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void * __thiscall FUN_004629a0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  void *pvVar8;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 4);
  iVar7 = (int)param_2 - iVar3 >> 2;
  if (*(int *)(param_1 + 0xc) - iVar2 >> 2 != 0) {
    if (iVar2 - (int)param_2 >> 2 == 0) {
      FUN_00476950(param_2,iVar2,param_2 + 1);
      FUN_0044ec00(*(int *)(param_1 + 8),1 - (*(int *)(param_1 + 8) - (int)param_2 >> 2),param_3);
      puVar6 = *(undefined4 **)(param_1 + 8);
      for (; param_2 != puVar6; param_2 = param_2 + 1) {
        *param_2 = *param_3;
      }
    }
    else {
      FUN_00476950(iVar2 + -4,iVar2,iVar2);
      puVar6 = *(undefined4 **)(param_1 + 8);
      puVar1 = puVar6;
      while (param_2 != puVar1 + -1) {
        puVar6 = puVar6 + -1;
        *puVar6 = puVar1[-2];
        puVar1 = puVar1 + -1;
      }
      puVar6 = param_2 + 1;
      for (; param_2 != puVar6; param_2 = param_2 + 1) {
        *param_2 = *param_3;
      }
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
    return (void *)(*(int *)(param_1 + 4) + iVar7 * 4);
  }
  if ((iVar3 == 0) || (uVar5 = iVar2 - iVar3 >> 2, uVar5 < 2)) {
    uVar5 = 1;
  }
  if (iVar3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 - iVar3 >> 2;
  }
  iVar2 = iVar2 + uVar5;
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = 0;
  }
  pvVar4 = operator_new(iVar3 * 4);
  pvVar8 = pvVar4;
  for (puVar6 = *(undefined4 **)(param_1 + 4); puVar6 != param_2; puVar6 = puVar6 + 1) {
    FUN_0043a120(pvVar8,puVar6);
    pvVar8 = (void *)((int)pvVar8 + 4);
  }
  FUN_0043a120(pvVar8,param_3);
  FUN_00476950(param_2,*(undefined4 *)(param_1 + 8),(int)pvVar8 + 4);
  FUN_0048b600(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(void **)(param_1 + 0xc) = (void *)((int)pvVar4 + iVar2 * 4);
  iVar2 = FUN_0044ca80();
  *(void **)(param_1 + 4) = pvVar4;
  *(int *)(param_1 + 8) = (int)pvVar4 + iVar2 * 4 + 4;
  return (void *)((int)pvVar4 + iVar7 * 4);
}

