/*
 * FUN_0046e330 at 0046e330
 * undefined FUN_0046e330(void)
 * Address ranges: 0046e330-0046e5a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046e330(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 *local_54;
  int local_50;
  undefined1 local_4c [4];
  undefined4 *local_48;
  uint local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c [4];
  char *local_28;
  uint local_24;
  undefined1 local_1c [4];
  undefined4 *local_18;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d05a6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_D__work_rcsk_Code_game_Rco_stars_004f5ddc;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_D__work_rcsk_Code_game_Rco_stars_004f5ddc;
    pcVar6 = local_28;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    local_28[uVar2] = '\0';
    local_24 = uVar2;
  }
  local_4 = 0;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = (char *)&DAT_00544b68;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar5 = &DAT_00544b68;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *local_18 = *puVar5;
      puVar5 = puVar5 + 1;
      local_18 = local_18 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)local_18 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      local_18 = (undefined4 *)((int)local_18 + 1);
    }
    FUN_0040b5e0(uVar2);
  }
  local_4._0_1_ = 1;
  FUN_00464530(*(undefined4 *)(param_1 + 8),local_1c,local_2c,0xa2);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  local_54 = (undefined4 *)(param_1 + 0xc);
  local_50 = 0xc;
  do {
    uVar2 = 0xffffffff;
    local_38 = 0;
    pcVar4 = s_D__work_rcsk_Code_game_Rco_stars_004f5e04;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    local_34 = 0;
    local_30 = 0;
    FUN_0040b540(s_D__work_rcsk_Code_game_Rco_stars_004f5e04,~uVar2 - 1);
    local_4 = 2;
    FUN_0040b4f0(0);
    uVar2 = 0xffffffff;
    pcVar4 = (char *)&DAT_00544b6c;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 != '\0') {
      puVar5 = &DAT_00544b6c;
      puVar7 = local_48;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      *(undefined1 *)((int)local_48 + uVar2) = 0;
      local_44 = uVar2;
    }
    local_4 = CONCAT31(local_4._1_3_,3);
    FUN_00464530(*local_54,local_4c,local_3c,0xa5);
    if (local_48 != (undefined4 *)0x0) {
      cVar1 = *(char *)((int)local_48 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)((int)local_48 + -1));
      }
      else {
        *(char *)((int)local_48 + -1) = cVar1 + -1;
      }
    }
    local_48 = (undefined4 *)0x0;
    local_44 = 0;
    local_40 = 0;
    local_4 = 0xffffffff;
    if (local_38 != 0) {
      cVar1 = *(char *)(local_38 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_38 + -1));
      }
      else {
        *(char *)(local_38 + -1) = cVar1 + -1;
      }
    }
    local_54 = local_54 + 1;
    local_50 = local_50 + -1;
    if (local_50 == 0) {
      ExceptionList = local_c;
      return;
    }
  } while( true );
}

