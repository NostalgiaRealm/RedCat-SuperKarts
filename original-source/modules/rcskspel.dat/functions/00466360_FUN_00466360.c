/*
 * FUN_00466360 at 00466360
 * undefined FUN_00466360(void)
 * Address ranges: 00466360-00466827
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00466360(int param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int local_a0;
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 auStack_7c [4];
  int iStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 auStack_6c [4];
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 auStack_2c [16];
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf9ab;
  pvStack_c = ExceptionList;
  bVar3 = false;
  bVar2 = false;
  DAT_00544af4 = DAT_00544af4 & DAT_0053ba6c == 1;
  ExceptionList = &pvStack_c;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar8 = s_DotPlayer_004f4878;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_DotPlayer_004f4878,~uVar5 - 1);
  local_4 = 0;
  uVar4 = FUN_00461470(local_9c);
  *(undefined4 *)(param_1 + 0x2c) = uVar4;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_rco_map_c_004f4890;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_rco_map_c_004f4890,~uVar5 - 1);
  local_4 = 1;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar8 = s_Element_004f48cc;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Element_004f48cc,~uVar5 - 1);
  local_4._0_1_ = 2;
  uVar4 = FUN_0041b630(local_4c,local_9c,s_DotPlayer_004f4878);
  local_4._0_1_ = 3;
  uVar4 = FUN_0041b630(local_3c,uVar4,s_not_found_in_overlay_004f48b4);
  local_4._0_1_ = 4;
  FUN_00464530(*(undefined4 *)(param_1 + 0x2c),uVar4,local_8c,0x3c);
  local_4._0_1_ = 3;
  FUN_0040b4f0(1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_00458460(1);
  if (9 < DAT_00508610) {
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar8 = s_D__work_rcsk_Code_game_rco_map_c_004f48d8;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_D__work_rcsk_Code_game_rco_map_c_004f48d8,~uVar5 - 1);
    local_4 = 5;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar8 = s_g_NumberOfOpponents_<__MAX_NUM_O_004f48fc;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_g_NumberOfOpponents_<__MAX_NUM_O_004f48fc,~uVar5 - 1);
    bVar3 = true;
    bVar2 = true;
    local_4 = 6;
    FUN_00464610(local_8c,local_9c,0x40);
  }
  local_4 = 5;
  if (bVar2) {
    FUN_0040b4f0(1);
  }
  local_4 = 0xffffffff;
  if (bVar3) {
    FUN_0040b4f0(1);
  }
  local_a0 = 0;
  if (0 < DAT_00508610) {
    puVar7 = (undefined4 *)(param_1 + 8);
    do {
      FUN_00463d20(auStack_6c,local_a0);
      local_4 = 7;
      uVar4 = FUN_00412710(local_4c,s_DotRacer_004f4884,auStack_6c);
      local_4._0_1_ = 8;
      uVar4 = FUN_00461470(uVar4);
      *puVar7 = uVar4;
      local_4._0_1_ = 7;
      FUN_0040b4f0(1);
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar8 = s_D__work_rcsk_Code_game_rco_map_c_004f4928;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_rco_map_c_004f4928,~uVar5 - 1);
      local_4._0_1_ = 9;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar8 = s_Element_004f495c;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_Element_004f495c,~uVar5 - 1);
      local_4._0_1_ = 10;
      uVar4 = FUN_0041b630(auStack_1c,auStack_5c,s_DotPlayer_004f4878);
      local_4._0_1_ = 0xb;
      uVar4 = FUN_0041b630(auStack_2c,uVar4,s_not_in_overlay_004f494c);
      local_4._0_1_ = 0xc;
      FUN_00464530(*puVar7,uVar4,auStack_7c,0x45);
      local_4._0_1_ = 0xb;
      FUN_0040b4f0(1);
      local_4._0_1_ = 10;
      FUN_0040b4f0(1);
      local_4._0_1_ = 9;
      FUN_0040b4f0(1);
      local_4 = CONCAT31(local_4._1_3_,7);
      if (iStack_78 != 0) {
        cVar1 = *(char *)(iStack_78 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(iStack_78 + -1));
        }
        else {
          *(char *)(iStack_78 + -1) = cVar1 + -1;
        }
      }
      iStack_78 = 0;
      uStack_74 = 0;
      uStack_70 = 0;
      FUN_00458460(1);
      local_4 = 0xffffffff;
      if (iStack_68 != 0) {
        cVar1 = *(char *)(iStack_68 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(iStack_68 + -1);
        }
        else {
          *(char *)(iStack_68 + -1) = cVar1 + -1;
        }
      }
      local_a0 = local_a0 + 1;
      puVar7 = puVar7 + 1;
      iStack_68 = 0;
      uStack_64 = 0;
      uStack_60 = 0;
    } while (local_a0 < DAT_00508610);
  }
  puVar7 = (undefined4 *)(&DAT_004f4620 + DAT_0053b9b4 * 0x14);
  puVar9 = (undefined4 *)(param_1 + 0x30);
  for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  ExceptionList = pvStack_c;
  return;
}

