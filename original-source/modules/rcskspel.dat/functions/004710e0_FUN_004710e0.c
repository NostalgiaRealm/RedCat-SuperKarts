/*
 * FUN_004710e0 at 004710e0
 * undefined FUN_004710e0(void)
 * Address ranges: 004710e0-00471510
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_004710e0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 uVar4;
  undefined3 extraout_var_01;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined1 local_15c [4];
  undefined1 *local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined1 local_14c [4];
  char *local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined1 *local_138;
  undefined1 local_12c [4];
  char *local_128;
  undefined1 local_11c [16];
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d08c1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar9 = s_STOPPEN_004f6724;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_STOPPEN_004f6724,~uVar5 - 1);
  local_4 = 0;
  FUN_00470610(local_15c,param_2);
  local_4 = CONCAT31(local_4._1_3_,1);
  local_10c[0] = '\0';
  puVar3 = local_158;
  if (local_158 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  puVar6 = local_138;
  if (local_138 == (undefined1 *)0x0) {
    puVar6 = &DAT_004d2404;
  }
  FUN_004b1f10(puVar6,puVar3,local_10c,0x100);
  iVar7 = -1;
  pcVar9 = local_10c;
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  if (iVar7 == -2) {
    if (local_158 == (undefined1 *)0x0) {
      local_158 = &DAT_004d2404;
    }
    uVar11 = 0x1b4;
    pcVar10 = s_D__work_rcsk_Code_game_rcr_stop__004f672c;
    pcVar9 = s__s__d____No_ini_value_for__s_004f675c;
  }
  else {
    iVar7 = FUN_004b1f60(local_10c,&DAT_004f677c);
    if (2 < iVar7) {
      FUN_004b2110(0,local_10c,0x100);
      if (iVar7 == 3) {
        FUN_00470c50(param_2,local_10c);
      }
      else if ((3 < iVar7) && (iVar7 = FUN_004b20c0(3), iVar7 == 1)) {
        *(undefined4 *)(param_1 + param_2 * 4) = 0;
        iVar7 = FUN_00470560();
        pcVar9 = (&PTR_DAT_004f63d8)[iVar7];
        FUN_0040b4f0(0);
        uVar5 = 0xffffffff;
        pcVar10 = pcVar9;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar2 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar2 != '\0');
        uVar5 = ~uVar5 - 1;
        cVar2 = FUN_0040b600(uVar5,1);
        if (cVar2 != '\0') {
          pcVar10 = local_128;
          for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
            pcVar9 = pcVar9 + 4;
            pcVar10 = pcVar10 + 4;
          }
          for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar10 = *pcVar9;
            pcVar9 = pcVar9 + 1;
            pcVar10 = pcVar10 + 1;
          }
          FUN_0040b5e0(uVar5);
        }
        local_4 = CONCAT31(local_4._1_3_,2);
        FUN_0040b4f0(0);
        uVar5 = 0xffffffff;
        pcVar9 = local_10c;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar2 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar2 != '\0');
        uVar5 = ~uVar5 - 1;
        cVar2 = FUN_0040b600(uVar5,1);
        if (cVar2 != '\0') {
          pcVar9 = local_10c;
          pcVar10 = local_148;
          for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
            pcVar9 = pcVar9 + 4;
            pcVar10 = pcVar10 + 4;
          }
          for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar10 = *pcVar9;
            pcVar9 = pcVar9 + 1;
            pcVar10 = pcVar10 + 1;
          }
          FUN_0040b5e0(uVar5);
        }
        local_4._0_1_ = 3;
        uVar11 = FUN_00459040(local_11c,local_14c,local_12c);
        local_4._0_1_ = 4;
        FUN_00412870(uVar11,0,0xffffffff);
        local_4 = CONCAT31(local_4._1_3_,3);
        FUN_0040b4f0(1);
        if (local_148 != (char *)0x0) {
          cVar2 = local_148[-1];
          if ((cVar2 == '\0') || (cVar2 == -1)) {
            FUN_004bc150(local_148 + -1);
          }
          else {
            local_148[-1] = cVar2 + -1;
          }
        }
        local_148 = (char *)0x0;
        local_144 = 0;
        local_140 = 0;
        local_4 = CONCAT31(local_4._1_3_,1);
        if (local_128 != (char *)0x0) {
          cVar2 = local_128[-1];
          if ((cVar2 == '\0') || (cVar2 == -1)) {
            FUN_004bc150(local_128 + -1);
          }
          else {
            local_128[-1] = cVar2 + -1;
          }
        }
      }
      if (DAT_0053b9f0 == 0) {
        uVar11 = FUN_004b20c0(1);
        *(undefined4 *)(param_1 + 0x30 + param_2 * 8) = uVar11;
        uVar11 = FUN_004b20c0(2);
        *(undefined4 *)(param_1 + 0x34 + param_2 * 8) = uVar11;
      }
      else {
        iVar7 = FUN_004b20c0(1);
        *(int *)(param_1 + 0x30 + param_2 * 8) = (iVar7 * DAT_004fe930) / 0x280;
        iVar7 = FUN_004b20c0(2);
        *(int *)(param_1 + 0x34 + param_2 * 8) = (iVar7 * DAT_004fe934) / 0x1e0;
      }
      puVar3 = local_158;
      if (local_158 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      iVar7 = *(int *)(param_1 + 0x34 + param_2 * 8);
      iVar1 = *(int *)(param_1 + 0x30 + param_2 * 8);
      FUN_004afce0(s__s__d____Loaded_surface_for__s___004f6808,
                   s_D__work_rcsk_Code_game_rcr_stop__004f67d8,0x1e0,puVar3,param_2,iVar1,iVar7,
                   *(int *)(param_1 + 0x90 + param_2 * 8) + iVar1,
                   *(int *)(param_1 + 0x94 + param_2 * 8) + iVar7);
      uVar4 = extraout_var;
      if (local_158 != (undefined1 *)0x0) {
        cVar2 = local_158[-1];
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_004bc150(local_158 + -1);
          uVar4 = extraout_var_00;
        }
        else {
          local_158[-1] = cVar2 + -1;
        }
      }
      local_158 = (undefined1 *)0x0;
      local_154 = 0;
      local_150 = 0;
      if (local_138 != (undefined1 *)0x0) {
        cVar2 = local_138[-1];
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_004bc150(local_138 + -1);
          uVar4 = extraout_var_01;
        }
        else {
          local_138[-1] = cVar2 + -1;
        }
      }
      ExceptionList = local_c;
      return CONCAT31(uVar4,1);
    }
    if (local_158 == (undefined1 *)0x0) {
      local_158 = &DAT_004d2404;
    }
    uVar11 = 0x1be;
    pcVar10 = s_D__work_rcsk_Code_game_rcr_stop__004f6780;
    pcVar9 = s__s__d____Not_enough_parameters_f_004f67b0;
  }
  FUN_004afee0(pcVar9,pcVar10,uVar11,local_158);
  local_4 = local_4 & 0xffffff00;
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  uVar5 = FUN_0040b4f0(1);
  ExceptionList = local_c;
  return uVar5 & 0xffffff00;
}

