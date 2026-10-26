/*
 * FUN_0040b0b0 at 0040b0b0
 * undefined FUN_0040b0b0(void)
 * Address ranges: 0040b0b0-0040b473
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040b0b0(char *param_1)

{
  float *pfVar1;
  char cVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *unaff_EBP;
  char *unaff_ESI;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcStack_44;
  char *pcStack_40;
  char acStack_2c [4];
  undefined4 uStack_28;
  undefined1 uStack_20;
  undefined4 uStack_1c;
  undefined1 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004ccc38;
  pvStack_c = ExceptionList;
  pcStack_40 = (char *)0x40b0d5;
  ExceptionList = &pvStack_c;
  pcVar3 = (char *)FUN_004028c0();
  pcStack_40 = param_1;
  pcStack_44 = (char *)0x40b0dd;
  FUN_0048c030();
  if (pcVar3 != (char *)0xffffffff) {
    pcStack_40 = (char *)0x40b0f1;
    FUN_004024d0();
    pcStack_44 = (char *)0x40b0f7;
    pcStack_40 = pcVar3;
    FUN_00406940();
    pcStack_44 = pcVar3;
    FUN_0040e760();
    if (DAT_0053b9c0 == 3) {
      pcStack_40 = (char *)0x40b114;
      cVar2 = FUN_00417e90();
      iVar5 = DAT_0053be60;
      if (cVar2 == '\0') {
        iVar5 = (&DAT_005081b8)[(int)pcVar3 * 0x1c];
      }
      if (iVar5 == 0) {
        acStack_2c[0] = (char)param_1;
        pcStack_40 = (char *)0x40b14a;
        FUN_0040b4f0();
        iVar5 = -1;
        pcVar8 = s_CHEER_004dee9c;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          cVar2 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar2 != '\0');
        pcStack_40 = s_CHEER_004dee9c;
        pcStack_44 = (char *)0x40b167;
        FUN_0040b540();
        uStack_4 = 0;
        pcStack_40 = (char *)0x40b17a;
        piVar4 = (int *)FUN_0044a700();
        pcStack_44 = acStack_2c;
        pcStack_40 = (char *)0x0;
        (**(code **)(*piVar4 + 0xc))();
        uStack_4 = 0xffffffff;
        pcStack_40 = (char *)0x40b199;
        FUN_0040b4f0();
      }
    }
    pcStack_40 = (char *)0x0;
    acStack_2c[0] = (char)param_1;
    pcStack_44 = (char *)0x40b1ad;
    FUN_0040b4f0();
    uVar6 = 0xffffffff;
    pcVar8 = s_TURBO_IDLE_004deea4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    pcStack_40 = (char *)(~uVar6 - 1);
    pcStack_44 = s_TURBO_IDLE_004deea4;
    FUN_0040b540();
    uStack_4 = 1;
    pcStack_44 = (char *)0x40b1dd;
    pcStack_40 = pcVar3;
    piVar4 = (int *)FUN_0044a700();
    pcStack_40 = (char *)0x0;
    pcStack_44 = (char *)0x6;
    (**(code **)(*piVar4 + 0xc))(acStack_2c);
    uStack_10 = 0xffffffff;
    FUN_0040b4f0(1);
    FUN_0040b4f0(0);
    uVar6 = 0xffffffff;
    pcVar8 = s_RIGHT_IDLE_004deeb0;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6 - 1;
    cVar2 = FUN_0040b600(uVar6,1);
    if (cVar2 != '\0') {
      pcVar8 = s_RIGHT_IDLE_004deeb0;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)unaff_ESI = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        unaff_ESI = unaff_ESI + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *unaff_ESI = *pcVar8;
        pcVar8 = pcVar8 + 1;
        unaff_ESI = unaff_ESI + 1;
      }
      FUN_0040b5e0(uVar6);
    }
    uStack_10 = 2;
    piVar4 = (int *)FUN_0044a700(pcVar3);
    (**(code **)(*piVar4 + 0xc))(&stack0xffffffc8,4,0);
    uStack_1c = 0xffffffff;
    FUN_0040b4f0(1);
    pcStack_44 = (char *)CONCAT31(pcStack_44._1_3_,uStack_14);
    FUN_0040b4f0(0);
    uVar6 = 0xffffffff;
    pcVar8 = s_LEFT_IDLE_004deebc;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6 - 1;
    cVar2 = FUN_0040b600(uVar6,1);
    if (cVar2 != '\0') {
      pcVar8 = s_LEFT_IDLE_004deebc;
      pcVar10 = pcStack_40;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar10 = pcVar10 + 1;
      }
      FUN_0040b5e0(uVar6);
    }
    uStack_1c = 3;
    piVar4 = (int *)FUN_0044a700(pcVar3);
    (**(code **)(*piVar4 + 0xc))(&pcStack_44,3,0);
    uStack_28 = 0xffffffff;
    FUN_0040b4f0(1);
    pcStack_40 = (char *)CONCAT31(pcStack_40._1_3_,uStack_20);
    FUN_0040b4f0(0);
    uVar6 = 0xffffffff;
    pcVar8 = (char *)&DAT_004deec8;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6 - 1;
    cVar2 = FUN_0040b600(uVar6,1);
    if (cVar2 != '\0') {
      puVar9 = &DAT_004deec8;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *unaff_EBP = *puVar9;
        puVar9 = puVar9 + 1;
        unaff_EBP = unaff_EBP + 1;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)unaff_EBP = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        unaff_EBP = (undefined4 *)((int)unaff_EBP + 1);
      }
      FUN_0040b5e0(uVar6);
    }
    uStack_28 = 4;
    piVar4 = (int *)FUN_0044a700(pcVar3);
    (**(code **)(*piVar4 + 0xc))(&pcStack_40,0,0);
    pcStack_40 = (char *)0x1;
    uStack_4 = 0xffffffff;
    pcStack_44 = (char *)0x40b3a0;
    FUN_0040b4f0();
    pcStack_44 = (char *)0x40b3a6;
    pcStack_40 = pcVar3;
    FUN_0040ea50();
    cVar2 = DAT_0053bec4;
    if (((int)pcVar3 < DAT_00508610) && (-1 < (int)pcVar3)) {
      cVar2 = (&DAT_00508214)[(int)pcVar3 * 0x70];
    }
    if ((cVar2 != '\0') ||
       (*(int *)(*(int *)((int)param_1 * 0xd0 + 0x24 + DAT_0067ee20) * 0x50 + 4 + DAT_00680ae0) ==
        0x44)) {
      pcStack_40 = param_1;
      pcStack_44 = (char *)0x40b405;
      FUN_00481a70();
      pfVar1 = (float *)((int)param_1 * 0xd0 + 0x9c + DAT_0067ee20);
      *pfVar1 = *(float *)((int)param_1 * 0xd0 + 0x9c + DAT_0067ee20) * 0.98;
      pfVar1[1] = pfVar1[1] * 0.98;
      pfVar1[2] = pfVar1[2] * 0.98;
    }
    pcStack_40 = (char *)0x40b450;
    FUN_0044a6c0();
  }
  pcStack_40 = (char *)0x40b45a;
  FUN_0041b910();
  ExceptionList = pvStack_c;
  return 1;
}

