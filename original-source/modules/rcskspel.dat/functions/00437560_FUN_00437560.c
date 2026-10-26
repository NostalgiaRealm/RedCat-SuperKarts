/*
 * FUN_00437560 at 00437560
 * undefined FUN_00437560(void)
 * Address ranges: 00437560-00437b01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00437560(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  bool bVar12;
  char *local_68;
  char *local_58;
  char *local_48;
  undefined1 local_3c [4];
  char *local_38;
  undefined1 local_2c [4];
  undefined1 *local_28;
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd3fd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004afce0(s_CVoiceController__Load_004ec01c);
  FUN_004b1d60(s_Race_INI_004ec034);
  iVar2 = FUN_004b1ed0(s_GAME_SETTINGS_004ec048,s_EFFECTS_004ec040);
  *param_1 = iVar2 != 0;
  iVar2 = FUN_004b1ed0(s_GAME_SETTINGS_004ec064,s_FX_VOLUME_004ec058);
  if ((*param_1 != '\0') && (iVar2 == 0)) {
    FUN_004b1e70(s_GAME_SETTINGS_004ec07c,s_effects_004ec074,1);
    FUN_004b1e70(s_GAME_SETTINGS_004ec098,s_FX_VOLUME_004ec08c,0x4b);
    *param_1 = '\x01';
  }
  puVar3 = *(undefined1 **)(param_2 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar3);
  iVar2 = 0;
  if (-1 < DAT_00508610) {
    piVar11 = &DAT_0050820c;
    bVar12 = SBORROW4(0,DAT_00508610);
    iVar6 = -DAT_00508610;
    do {
      iVar4 = DAT_0053bebc;
      if ((bVar12 != iVar6 < 0) && (0x50820b < (int)piVar11)) {
        iVar4 = *piVar11;
      }
      pcVar7 = (&PTR_s_RedCat_004d2504)[iVar4];
      local_2c[0] = (undefined1)param_2;
      FUN_0040b4f0(0);
      uVar9 = 0xffffffff;
      pcVar8 = pcVar7;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(pcVar7,~uVar9 - 1);
      puVar3 = local_2c;
      local_4 = 0;
      uVar5 = FUN_00437ea0(iVar2,puVar3);
      FUN_00437260(uVar5,puVar3);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      uVar5 = FUN_00437ea0(iVar2,iVar2);
      FUN_00436d90(uVar5);
      iVar2 = iVar2 + 1;
      piVar11 = piVar11 + 0x1c;
      bVar12 = SBORROW4(iVar2,DAT_00508610);
      iVar6 = iVar2 - DAT_00508610;
    } while (iVar2 <= DAT_00508610);
  }
  local_2c[0] = (undefined1)param_2;
  FUN_0040b4f0(0);
  uVar9 = 0xffffffff;
  pcVar7 = s_EFFECTS_004ec0a8;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_EFFECTS_004ec0a8,~uVar9 - 1);
  local_4 = 1;
  FUN_00437260(10,local_2c);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  iVar2 = FUN_004b1ed0(s_VOLUMES_004ec0b0,s_COUNT_004ec0b8);
  param_2 = 0;
  if (0 < iVar2) {
    do {
      local_3c[0] = 0;
      FUN_0040b4f0(0);
      uVar9 = 0xffffffff;
      pcVar7 = s_VOLUMES_004ec0b0;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar9 = ~uVar9 - 1;
      cVar1 = FUN_0040b600(uVar9,1);
      if (cVar1 != '\0') {
        pcVar7 = s_VOLUMES_004ec0b0;
        pcVar8 = local_38;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
          *pcVar8 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        }
        FUN_0040b5e0(uVar9);
      }
      local_4 = 2;
      uVar5 = FUN_004314a0(local_1c,param_2);
      local_4._0_1_ = 3;
      FUN_00431390(local_2c,local_3c,uVar5);
      local_4._0_1_ = 6;
      FUN_0040b4f0(1);
      local_4 = CONCAT31(local_4._1_3_,5);
      FUN_0040b4f0(1);
      puVar3 = local_28;
      if (local_28 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      uVar5 = FUN_004b1ed0(s_VOLUMES_004ec0b0,puVar3);
      puVar3 = local_28;
      if (local_28 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      FUN_004afce0(s___for_voice_group__s__put_volume_004ec0c0,puVar3,uVar5);
      puVar3 = local_28;
      if (local_28 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      iVar6 = FUN_0049e2f0(puVar3);
      if (iVar6 != 0) {
        puVar3 = local_28;
        if (local_28 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        FUN_004afce0(s_Setting_volume_of_sound_group__s_004ec0e8,puVar3,iVar6,uVar5);
        FUN_0049e970(iVar6,uVar5);
      }
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      param_2 = param_2 + 1;
    } while (param_2 < iVar2);
  }
  cVar1 = FUN_00437550();
  if (cVar1 != '\0') {
    FUN_0040b4f0(0);
    uVar9 = 0xffffffff;
    pcVar7 = s_Race_INI_004ec118;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar1 = FUN_0040b600(uVar9,1);
    if (cVar1 != '\0') {
      pcVar7 = s_Race_INI_004ec118;
      pcVar8 = local_68;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      local_68[uVar9] = '\0';
    }
    local_4 = 7;
    FUN_0040b4f0(0);
    uVar9 = 0xffffffff;
    pcVar7 = s_game_settings_004ec124;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar1 = FUN_0040b600(uVar9,1);
    if (cVar1 != '\0') {
      pcVar7 = s_game_settings_004ec124;
      pcVar8 = local_48;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      FUN_0040b5e0(uVar9);
    }
    local_4 = CONCAT31(local_4._1_3_,8);
    FUN_0040b4f0(0);
    uVar9 = 0xffffffff;
    pcVar7 = s_fx_volume_004ec134;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar1 = FUN_0040b600(uVar9,1);
    if (cVar1 != '\0') {
      pcVar7 = s_fx_volume_004ec134;
      pcVar8 = local_58;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      FUN_0040b5e0(uVar9);
    }
    local_4 = CONCAT31(local_4._1_3_,9);
    pcVar7 = local_68;
    if (local_68 == (char *)0x0) {
      pcVar7 = "";
    }
    FUN_004b1d60(pcVar7);
    pcVar7 = local_58;
    if (local_58 == (char *)0x0) {
      pcVar7 = "";
    }
    pcVar8 = local_48;
    if (local_48 == (char *)0x0) {
      pcVar8 = "";
    }
    uVar5 = FUN_004b1ed0(pcVar8,pcVar7);
    FUN_00437e30(uVar5);
    if (local_58 != (char *)0x0) {
      cVar1 = local_58[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_58 + -1);
      }
      else {
        local_58[-1] = cVar1 + -1;
      }
    }
    if (local_48 != (char *)0x0) {
      cVar1 = local_48[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_48 + -1);
      }
      else {
        local_48[-1] = cVar1 + -1;
      }
    }
    local_4 = 0xffffffff;
    if (local_68 != (char *)0x0) {
      cVar1 = local_68[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_68 + -1);
      }
      else {
        local_68[-1] = cVar1 + -1;
      }
    }
  }
  FUN_004afce0(s_CVoiceController__Load_end_004ec140);
  ExceptionList = local_c;
  return;
}

