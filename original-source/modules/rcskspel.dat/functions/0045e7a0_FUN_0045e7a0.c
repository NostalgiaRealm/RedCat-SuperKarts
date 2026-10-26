/*
 * FUN_0045e7a0 at 0045e7a0
 * undefined FUN_0045e7a0(void)
 * Address ranges: 0045e7a0-0045ed5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0045e7a0(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_EBX;
  char *pcVar9;
  char *pcVar10;
  float10 fVar11;
  undefined4 uStack_94;
  undefined1 uStack_91;
  undefined4 local_8c;
  char *local_88 [4];
  undefined1 local_78 [12];
  int iStack_6c;
  int local_68;
  int local_64;
  undefined1 local_60 [12];
  int iStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined1 auStack_30 [4];
  undefined1 local_2c [12];
  int iStack_20;
  undefined1 local_1c [8];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cebe3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_64 = param_1;
  uVar2 = FUN_0045bba0(param_2);
  puVar3 = *(undefined1 **)(param_2 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  local_68 = FUN_004b1ed0(puVar3,s_Length_004f2d40);
  local_78[0] = uStack_91;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar9 = &DAT_004f2d64;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f2d64,~uVar7 - 1);
  local_4 = 0;
  FUN_00464150(local_1c,param_2,local_78);
  local_4._0_1_ = 2;
  FUN_0040b4f0(1);
  local_8c = FUN_0045f8a0(local_1c);
  local_88[0] = (char *)CONCAT31(local_88[0]._1_3_,uStack_91);
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar9 = &DAT_004f2d48;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f2d48,~uVar7 - 1);
  local_4._0_1_ = 3;
  FUN_00464150(&local_3c,param_2,local_88);
  local_4._0_1_ = 5;
  FUN_0040b4f0(1);
  iVar4 = FUN_004616a0(&local_3c);
  local_60[0] = uStack_91;
  local_40 = iVar4;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar9 = s_D__work_rcsk_Code_game_Hud_IniFi_004f352c;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f352c,~uVar7 - 1);
  local_4._0_1_ = 6;
  local_78[0] = (undefined1)local_3c;
  FUN_0040b4f0(0);
  FUN_00412870(&local_3c,0,0xffffffff);
  local_4._0_1_ = 7;
  uVar5 = FUN_00412710(local_2c,s_Unknown_font_004f3558,local_78);
  local_4._0_1_ = 8;
  FUN_00464530(iVar4,uVar5,local_60,0x348);
  local_4._0_1_ = 7;
  FUN_0040b4f0(1);
  local_4._0_1_ = 6;
  FUN_0040b4f0(1);
  local_4._0_1_ = 5;
  FUN_0040b4f0(1);
  piVar6 = (int *)FUN_00461b50(uVar2,param_2,local_68,iVar4,local_8c);
  FUN_0045caa0(piVar6);
  FUN_0045bf10(piVar6);
  local_60[0] = uStack_91;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar9 = s_Alignment_004f2d58;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Alignment_004f2d58,~uVar7 - 1);
  local_4._0_1_ = 9;
  FUN_00464150(&local_50,param_2,local_60);
  local_4 = CONCAT31(local_4._1_3_,0xb);
  FUN_0040b4f0(1);
  uVar7 = 0xffffffff;
  pcVar9 = &DAT_00544ac4;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  iVar4 = FUN_00460440(0,local_48,&DAT_00544ac4,~uVar7 - 1);
  if (iVar4 != 0) {
    uVar2 = FUN_0045fae0(&local_50);
    (**(code **)(*piVar6 + 0x48))(uVar2);
  }
  local_78[0] = uStack_91;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar9 = &DAT_004f2d50;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f2d50,~uVar7 - 1);
  local_4._0_1_ = 0xc;
  uVar2 = FUN_00464150(local_2c,param_2,local_78);
  local_4 = CONCAT31(local_4._1_3_,0xd);
  (**(code **)(*piVar6 + 0x50))(uVar2);
  puStack_8._0_1_ = 0xc;
  FUN_0040b4f0(1);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,0xb);
  FUN_0040b4f0(1);
  local_8c = CONCAT31(local_8c._1_3_,(char)((uint)unaff_EBX >> 0x18));
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar9 = s_MaxCharWidth_004f2d6c;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7 - 1;
  cVar1 = FUN_0040b600(uVar7,1);
  if (cVar1 != '\0') {
    pcVar9 = s_MaxCharWidth_004f2d6c;
    pcVar10 = local_88[0];
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pcVar10 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar10 = pcVar10 + 1;
    }
    FUN_0040b5e0(uVar7);
    param_1 = local_68;
  }
  puStack_8._0_1_ = 0xe;
  iVar4 = FUN_00464150(auStack_30,param_2,&local_8c);
  uVar7 = 0xffffffff;
  puStack_8._0_1_ = 0xf;
  pcVar9 = &DAT_00544ac8;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  iVar4 = FUN_00460440(0,*(undefined4 *)(iVar4 + 8),&DAT_00544ac8,~uVar7 - 1);
  puStack_8._0_1_ = 0xe;
  FUN_0040b4f0(1);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,0xb);
  FUN_0040b4f0(1);
  if (iVar4 != 0) {
    local_8c = CONCAT31(local_8c._1_3_,iVar4 != 0);
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar9 = s_MaxCharWidth_004f2d6c;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7 - 1;
    cVar1 = FUN_0040b600(uVar7,1);
    if (cVar1 != '\0') {
      pcVar9 = s_MaxCharWidth_004f2d6c;
      pcVar10 = local_88[0];
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
      FUN_0040b5e0(uVar7);
      param_1 = local_68;
    }
    puStack_8._0_1_ = 0x10;
    fVar11 = (float10)FUN_00463fb0(param_2,&local_8c);
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,0xb);
    FUN_0040b4f0(1);
    fVar11 = (float10)(float)fVar11;
  }
  else {
    fVar11 = (float10)FUN_0045ae40();
  }
  (**(code **)(*piVar6 + 0x3c))
            ((float)(((float10)iStack_6c * fVar11) / (float10)*(float *)(param_1 + 0x18)));
  if (iStack_54 != 0) {
    cVar1 = *(char *)(iStack_54 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(iStack_54 + -1);
    }
    else {
      *(char *)(iStack_54 + -1) = cVar1 + -1;
    }
  }
  iStack_54 = 0;
  local_50 = 0;
  uStack_4c = 0;
  if (local_40 != 0) {
    cVar1 = *(char *)(local_40 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_40 + -1);
    }
    else {
      *(char *)(local_40 + -1) = cVar1 + -1;
    }
  }
  local_40 = 0;
  local_3c = 0;
  uStack_38 = 0;
  if (iStack_20 != 0) {
    cVar1 = *(char *)(iStack_20 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(iStack_20 + -1) = cVar1 + -1;
      ExceptionList = pvStack_14;
      return;
    }
    FUN_004bc150(iStack_20 + -1);
  }
  ExceptionList = pvStack_14;
  return;
}

