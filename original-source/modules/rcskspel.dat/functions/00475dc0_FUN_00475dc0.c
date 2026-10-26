/*
 * FUN_00475dc0 at 00475dc0
 * undefined FUN_00475dc0(void)
 * Address ranges: 00475dc0-004764a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00475dc0(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  int local_194;
  undefined1 local_190 [4];
  undefined1 *local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined1 *local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined1 *local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined1 *local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined1 *local_14c;
  undefined4 local_148;
  undefined4 local_144;
  int local_140;
  undefined1 *local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 local_12c;
  undefined1 *local_128;
  undefined1 *local_118;
  undefined1 local_10c;
  undefined1 *local_108;
  undefined1 local_fc [28];
  undefined1 local_e0 [4];
  undefined1 *local_dc;
  undefined1 local_d0 [16];
  undefined1 local_c0 [100];
  undefined1 local_5c [80];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0bb2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar8 = 0xffffffff;
  pcVar9 = s_gen_anim_ini_004f7b78;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_gen_anim_ini_004f7b78,~uVar8 - 1);
  local_4 = 0;
  FUN_0040b4f0(0);
  uVar8 = 0xffffffff;
  pcVar9 = s_Race_INI_004f7b88;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Race_INI_004f7b88,~uVar8 - 1);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar8 = 0xffffffff;
  pcVar9 = s_chardata_004f7b94;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_chardata_004f7b94,~uVar8 - 1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar8 = 0xffffffff;
  pcVar9 = s_count_004f7ba0;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_count_004f7ba0,~uVar8 - 1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar8 = 0xffffffff;
  pcVar9 = s_player_004f7ba8;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_player_004f7ba8,~uVar8 - 1);
  local_4._0_1_ = 4;
  FUN_0040b4f0(0);
  uVar8 = 0xffffffff;
  pcVar9 = &DAT_004f7bb0;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f7bb0,~uVar8 - 1);
  local_4 = CONCAT31(local_4._1_3_,5);
  puVar2 = local_16c;
  if (local_16c == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar2);
  puVar2 = local_14c;
  if (local_14c == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  puVar3 = local_15c;
  if (local_15c == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  uVar4 = FUN_004b1ed0(puVar3,puVar2);
  puVar2 = local_138;
  if (local_138 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  puVar3 = local_17c;
  if (local_17c == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  iVar5 = FUN_004b1ed0(puVar3,puVar2);
  local_194 = 0;
  local_140 = iVar5;
  if (0 < iVar5) {
    do {
      puVar2 = local_16c;
      if (local_16c == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      FUN_004b1d60(puVar2);
      FUN_004be8cb(local_d0,0xd,&DAT_004f7bb4,local_194);
      puVar2 = local_17c;
      if (local_17c == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      FUN_004b1f10(puVar2,local_d0,local_5c,0x50);
      iVar6 = FUN_004b1f60(local_5c,&DAT_004f7bb8);
      if (iVar6 < 4) {
        FUN_004afce0(s__s__d____Racer__d__game_ini___CH_004f7c84,
                     s_D__work_rcsk_Code_game_ssr_m25_g_004f7c5c,0x1e4,local_194);
      }
      else {
        iVar5 = FUN_004b20c0(2);
        uVar7 = FUN_004b20c0(3);
        FUN_004765d0(local_190,uVar4,uVar7);
        local_4._0_1_ = 6;
        FUN_00476790(local_e0,uVar4);
        local_4._0_1_ = 7;
        FUN_00476510(uVar4);
        puVar2 = (undefined1 *)FUN_00475120();
        local_12c = *puVar2;
        FUN_0040b4f0(0);
        FUN_00412870(puVar2,0,0xffffffff);
        local_4._0_1_ = 8;
        FUN_00476510(uVar4);
        puVar2 = (undefined1 *)FUN_00475130();
        local_10c = *puVar2;
        FUN_0040b4f0(0);
        FUN_00412870(puVar2,0,0xffffffff);
        local_4._0_1_ = 9;
        puVar2 = local_18c;
        if (local_18c == (undefined1 *)0x0) {
          puVar2 = &DAT_004d2404;
        }
        FUN_004afce0(s__s__d____racer__d_Car_texture_fi_004f7be4,
                     s_D__work_rcsk_Code_game_ssr_m25_g_004f7bbc,0x1b5,local_194,puVar2);
        puVar2 = local_118;
        if (local_118 == (undefined1 *)0x0) {
          puVar2 = &DAT_004d2404;
        }
        FUN_004b1d60(puVar2);
        FUN_004be8cb(local_fc,0x19,s_RACER__d_004f7c0c,local_194 + 1);
        puVar2 = local_18c;
        if (local_18c == (undefined1 *)0x0) {
          puVar2 = &DAT_004d2404;
        }
        puVar3 = local_dc;
        if (local_dc == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        FUN_004be8cb(local_c0,100,s__s__s_004f7c18,puVar3,puVar2);
        FUN_004b1e30(local_fc,&DAT_004f7c20,local_c0);
        puVar2 = &DAT_004d2404;
        if (local_18c != (undefined1 *)0x0) {
          puVar2 = local_18c;
        }
        puVar3 = local_128;
        if (local_128 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        FUN_004be8cb(local_c0,100,s__s__s_004f7c24,puVar3,puVar2);
        FUN_004b1e30(local_fc,&DAT_004f7c2c,local_c0);
        puVar2 = &DAT_004d2404;
        if (local_18c != (undefined1 *)0x0) {
          puVar2 = local_18c;
        }
        puVar3 = local_108;
        if (local_108 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        FUN_004be8cb(local_c0,100,s__s__s_004f7c30,puVar3,puVar2);
        FUN_004b1e30(local_fc,&DAT_004f7c38,local_c0);
        puVar2 = local_18c;
        if (local_18c == (undefined1 *)0x0) {
          puVar2 = &DAT_004d2404;
        }
        FUN_004be8cb(local_c0,100,s__s__s_004f7c48,s_char_rc_d3d_004f7c3c,puVar2);
        FUN_004b1e30(local_fc,&DAT_004f7c50,local_c0);
        FUN_004b1e30(local_fc,&DAT_004f7c58,&DAT_004f7c54);
        if (iVar5 == -1) {
          *(int *)(param_1 + 0x20) = local_194;
        }
        local_4._0_1_ = 8;
        FUN_0040b4f0(1);
        local_4._0_1_ = 7;
        FUN_0040b4f0(1);
        local_4._0_1_ = 6;
        FUN_0040b4f0(1);
        local_4 = CONCAT31(local_4._1_3_,5);
        if (local_18c != (undefined1 *)0x0) {
          cVar1 = local_18c[-1];
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150(local_18c + -1);
          }
          else {
            local_18c[-1] = cVar1 + -1;
          }
        }
        local_18c = (undefined1 *)0x0;
        local_188 = 0;
        local_184 = 0;
        iVar5 = local_140;
      }
      local_194 = local_194 + 1;
    } while (local_194 < iVar5);
  }
  if (local_14c != (undefined1 *)0x0) {
    cVar1 = local_14c[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_14c + -1);
    }
    else {
      local_14c[-1] = cVar1 + -1;
    }
  }
  local_14c = (undefined1 *)0x0;
  local_148 = 0;
  local_144 = 0;
  if (local_15c != (undefined1 *)0x0) {
    cVar1 = local_15c[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_15c + -1);
    }
    else {
      local_15c[-1] = cVar1 + -1;
    }
  }
  local_15c = (undefined1 *)0x0;
  local_158 = 0;
  local_154 = 0;
  if (local_138 != (undefined1 *)0x0) {
    cVar1 = local_138[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_138 + -1);
    }
    else {
      local_138[-1] = cVar1 + -1;
    }
  }
  local_138 = (undefined1 *)0x0;
  local_134 = 0;
  local_130 = 0;
  if (local_17c != (undefined1 *)0x0) {
    cVar1 = local_17c[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_17c + -1);
    }
    else {
      local_17c[-1] = cVar1 + -1;
    }
  }
  local_17c = (undefined1 *)0x0;
  local_178 = 0;
  local_174 = 0;
  if (local_16c != (undefined1 *)0x0) {
    cVar1 = local_16c[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_16c + -1);
    }
    else {
      local_16c[-1] = cVar1 + -1;
    }
  }
  local_16c = (undefined1 *)0x0;
  local_168 = 0;
  local_164 = 0;
  if (local_118 != (undefined1 *)0x0) {
    cVar1 = local_118[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      local_118[-1] = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150(local_118 + -1);
  }
  ExceptionList = local_c;
  return;
}

