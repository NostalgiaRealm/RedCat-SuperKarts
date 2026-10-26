/*
 * FUN_0040e760 at 0040e760
 * undefined FUN_0040e760(void)
 * Address ranges: 0040e760-0040ea48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040e760(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  char *unaff_EBP;
  undefined1 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  float10 fVar11;
  undefined1 local_2c [4];
  char *local_28;
  undefined4 *local_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccda0;
  local_c = ExceptionList;
  puVar7 = (undefined1 *)(param_1 * 0x11c);
  if ((&DAT_00503fe0)[(int)puVar7] != '\0') {
    ExceptionList = &local_c;
    fVar11 = (float10)FUN_0048f4d0();
    param_1._0_1_ = SUB41(puVar7,0);
    if (fVar11 - (float10)*(float *)(&DAT_00503fe4 + (int)puVar7) < (float10)5.0) {
      local_2c[0] = (undefined1)param_1;
      FUN_0040b4f0(0);
      uVar4 = 0xffffffff;
      pcVar8 = (char *)&DAT_004df1a4;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      puVar5 = (undefined4 *)(~uVar4 - 1);
      cVar2 = FUN_0040b600(puVar5,1);
      if (cVar2 != '\0') {
        pcVar8 = (char *)&DAT_004df1a4;
        pcVar9 = local_28;
        for (uVar4 = (uint)puVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar4 = (uint)puVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar9 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar9 = pcVar9 + 1;
        }
        local_28[(int)puVar5] = '\0';
        local_24 = puVar5;
      }
      local_4 = 0;
      piVar3 = (int *)FUN_0044a700(iVar1);
      (**(code **)(*piVar3 + 0xc))(local_2c,6,6);
      uStack_10 = 0xffffffff;
      FUN_0040b4f0(1);
      FUN_0040b4f0(0);
      uVar4 = 0xffffffff;
      pcVar8 = s_IDLE_TURBO_004df1ac;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      uVar4 = ~uVar4 - 1;
      cVar2 = FUN_0040b600(uVar4,1);
      if (cVar2 != '\0') {
        pcVar8 = s_IDLE_TURBO_004df1ac;
        pcVar9 = unaff_EBP;
        for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar6 = uVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar9 = pcVar9 + 1;
        }
        unaff_EBP[uVar4] = '\0';
      }
      uStack_10 = 1;
      piVar3 = (int *)FUN_0044a700(iVar1);
      (**(code **)(*piVar3 + 0xc))(&stack0xffffffc8,0,6);
      uStack_1c = 0xffffffff;
      FUN_0040b4f0(1);
      ExceptionList = local_24;
      return;
    }
    local_2c[0] = (undefined1)param_1;
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar8 = s_TURBO_IDLE_004df1b8;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    puVar5 = (undefined4 *)(~uVar4 - 1);
    cVar2 = FUN_0040b600(puVar5,1);
    if (cVar2 != '\0') {
      pcVar8 = s_TURBO_IDLE_004df1b8;
      pcVar9 = local_28;
      for (uVar4 = (uint)puVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar4 = (uint)puVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      local_28[(int)puVar5] = '\0';
      local_24 = puVar5;
    }
    local_4 = 2;
    piVar3 = (int *)FUN_0044a700(iVar1);
    (**(code **)(*piVar3 + 0xc))(local_2c,6,0);
    uStack_10 = 0xffffffff;
    if (unaff_EBP != (char *)0x0) {
      cVar2 = unaff_EBP[-1];
      if ((cVar2 == '\0') || (cVar2 == -1)) {
        FUN_004bc150(unaff_EBP + -1);
      }
      else {
        unaff_EBP[-1] = cVar2 + -1;
      }
    }
    local_28 = (char *)CONCAT31(local_28._1_3_,puStack_8._0_1_);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar8 = (char *)&DAT_004df1c4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar2 = FUN_0040b600(uVar4,1);
    if (cVar2 != '\0') {
      puVar5 = &DAT_004df1c4;
      puVar10 = local_24;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar10 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar6 = uVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      *(undefined1 *)((int)local_24 + uVar4) = 0;
      puVar7 = puStack_8;
      uStack_20 = uVar4;
    }
    uStack_10 = 3;
    piVar3 = (int *)FUN_0044a700(iVar1);
    (**(code **)(*piVar3 + 0xc))(&local_28,0,0);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    (&DAT_00503fe0)[(int)puVar7] = 0;
  }
  ExceptionList = local_c;
  return;
}

