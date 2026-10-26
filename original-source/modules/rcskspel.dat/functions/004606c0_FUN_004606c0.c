/*
 * FUN_004606c0 at 004606c0
 * undefined FUN_004606c0(void)
 * Address ranges: 004606c0-00460930
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004606c0(int param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 local_45;
  undefined4 local_3c;
  char *local_38;
  uint local_34;
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cefb7;
  local_c = ExceptionList;
  bVar6 = false;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x34) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x38) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  local_3c = 0;
  local_38 = (char *)0x0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  local_34 = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x28) = DAT_004f3920;
  *(undefined4 *)(param_1 + 0x24) = _DAT_004f3924;
  *(float *)(param_1 + 0x2c) = (float)DAT_004fe934 / (float)DAT_004fe930;
  pvVar2 = operator_new(0x84);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    local_3c = CONCAT31(local_3c._1_3_,local_45);
    FUN_0040b4f0(0);
    pcVar7 = s__Screen_004f3927;
    uVar4 = 0xffffffff;
    do {
      pcVar7 = pcVar7 + 1;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
    } while (*pcVar7 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar7 = s__Screen_004f3927 + 1;
      pcVar8 = local_38;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      local_38[uVar4] = '\0';
      local_34 = uVar4;
    }
    bVar6 = true;
    local_4 = CONCAT31(local_4._1_3_,1);
    uVar3 = FUN_004585e0(&local_3c);
  }
  *(undefined4 *)(param_1 + 4) = uVar3;
  local_4 = 0xffffffff;
  if (bVar6) {
    FUN_0040b4f0(1);
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  uVar4 = 0xffffffff;
  pcVar7 = s_D__work_rcsk_Code_game_Hud_Manag_004f3930;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3930,~uVar4 - 1);
  local_4 = 3;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar7 = s_Unable_to_create_overlay_top_004f3958;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar7 = s_Unable_to_create_overlay_top_004f3958;
    pcVar8 = local_18;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    local_18[uVar4] = '\0';
    local_14 = uVar4;
  }
  local_4._0_1_ = 4;
  FUN_00464530(*(undefined4 *)(param_1 + 4),local_1c,local_2c,0x50);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  if (local_28 != 0) {
    cVar1 = *(char *)(local_28 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(local_28 + -1));
    }
    else {
      *(char *)(local_28 + -1) = cVar1 + -1;
    }
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  FUN_00462770();
  ExceptionList = local_c;
  return;
}

