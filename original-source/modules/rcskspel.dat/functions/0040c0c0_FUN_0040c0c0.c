/*
 * FUN_0040c0c0 at 0040c0c0
 * undefined FUN_0040c0c0(void)
 * Address ranges: 0040c0c0-0040c365
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040c0c0(undefined4 param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *unaff_EBP;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined1 local_2c [4];
  char *local_28;
  undefined4 *local_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccc80;
  pvStack_c = ExceptionList;
  if (param_2 < 0) {
    ExceptionList = &pvStack_c;
    FUN_0040f350();
    local_2c[0] = (undefined1)param_1;
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar6 = s_IDLE_RIGHT_004deeec;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar4 = (undefined4 *)(~uVar3 - 1);
    cVar1 = FUN_0040b600(puVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = s_IDLE_RIGHT_004deeec;
      pcVar7 = local_28;
      for (uVar3 = (uint)puVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar3 = (uint)puVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      local_28[(int)puVar4] = '\0';
      local_24 = puVar4;
    }
    local_4 = 0;
    piVar2 = (int *)FUN_0044a700(param_1);
    (**(code **)(*piVar2 + 0xc))(local_2c,0,4);
    uStack_10 = 0xffffffff;
    FUN_0040b4f0(1);
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar6 = s_RIGHT_004deee4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar6 = s_RIGHT_004deee4;
      pcVar7 = unaff_EBP;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = uVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      unaff_EBP[uVar3] = '\0';
    }
    uStack_10 = 1;
    piVar2 = (int *)FUN_0044a700(param_1);
    (**(code **)(*piVar2 + 0xc))(&stack0xffffffc8,4,4);
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_0040f320(param_1);
    local_2c[0] = (undefined1)param_1;
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar6 = s_IDLE_LEFT_004deed8;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar4 = (undefined4 *)(~uVar3 - 1);
    cVar1 = FUN_0040b600(puVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = s_IDLE_LEFT_004deed8;
      pcVar7 = local_28;
      for (uVar3 = (uint)puVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar3 = (uint)puVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      local_28[(int)puVar4] = '\0';
      local_24 = puVar4;
    }
    local_4 = 2;
    piVar2 = (int *)FUN_0044a700(param_1);
    (**(code **)(*piVar2 + 0xc))(local_2c,0,3);
    uStack_10 = 0xffffffff;
    if (unaff_EBP != (char *)0x0) {
      cVar1 = unaff_EBP[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(unaff_EBP + -1);
      }
      else {
        unaff_EBP[-1] = cVar1 + -1;
      }
    }
    local_28 = (char *)CONCAT31(local_28._1_3_,puStack_8._0_1_);
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar6 = (char *)&DAT_004deed0;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      puVar4 = &DAT_004deed0;
      puVar8 = local_24;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar5 = uVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      *(undefined1 *)((int)local_24 + uVar3) = 0;
      uStack_20 = uVar3;
    }
    uStack_10 = 3;
    piVar2 = (int *)FUN_0044a700(param_1);
    (**(code **)(*piVar2 + 0xc))(&local_28,3,3);
  }
  uStack_1c = 0xffffffff;
  FUN_0040b4f0(1);
  ExceptionList = local_24;
  return;
}

