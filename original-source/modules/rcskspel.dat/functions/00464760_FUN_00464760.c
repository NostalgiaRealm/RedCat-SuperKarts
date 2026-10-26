/*
 * FUN_00464760 at 00464760
 * undefined FUN_00464760(void)
 * Address ranges: 00464760-004649f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00464760(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c [4];
  char *local_48;
  uint local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  undefined4 *local_38;
  uint local_34;
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf700;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  _DAT_004f4138 = FUN_004a6200(s_321player_004f413c);
  local_60 = 0;
  puVar6 = (undefined4 *)(param_1 + 0xc);
  do {
    uVar2 = FUN_004314a0(local_1c,local_60);
    local_4 = 0;
    uVar2 = FUN_00412710(local_2c,s_321Timer_004f4148,uVar2);
    local_4 = CONCAT31(local_4._1_3_,1);
    uVar2 = FUN_00461470(uVar2);
    *puVar6 = uVar2;
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
    local_4 = 0xffffffff;
    if (local_18 != 0) {
      cVar1 = *(char *)(local_18 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_18 + -1));
      }
      else {
        *(char *)(local_18 + -1) = cVar1 + -1;
      }
    }
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar7 = s_D__work_rcsk_Code_game_Rco_321Pl_004f4154;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar7 = s_D__work_rcsk_Code_game_Rco_321Pl_004f4154;
      pcVar8 = local_48;
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
      local_48[uVar4] = '\0';
      local_44 = uVar4;
    }
    local_4 = 2;
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar7 = (char *)&DAT_00544ad4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      puVar3 = &DAT_00544ad4;
      puVar9 = local_38;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar9 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      *(undefined1 *)((int)local_38 + uVar4) = 0;
      local_34 = uVar4;
    }
    local_4._0_1_ = 3;
    FUN_00464530(*puVar6,local_3c,local_4c,0x36);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_0040b4f0(1);
    local_4 = 0xffffffff;
    if (local_48 != (char *)0x0) {
      cVar1 = local_48[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_48 + -1);
      }
      else {
        local_48[-1] = cVar1 + -1;
      }
    }
    local_48 = (char *)0x0;
    local_44 = 0;
    local_40 = 0;
    uVar2 = FUN_004a6200(s_321player_004f4180);
    FUN_004599f0(uVar2);
    FUN_00458460(1);
    puVar3 = (undefined4 *)FUN_004583d0();
    local_58 = *puVar3;
    local_50 = puVar3[2];
    local_54 = 0x3fa00000;
    FUN_00458400(&local_58);
    puVar6 = puVar6 + 1;
    local_60 = local_60 + 1;
    if (2 < local_60) {
      *(undefined4 *)(param_1 + 0x18) = 6;
      ExceptionList = local_c;
      return;
    }
  } while( true );
}

