/*
 * FUN_00465fd0 at 00465fd0
 * undefined FUN_00465fd0(void)
 * Address ranges: 00465fd0-00466217
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00465fd0(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 local_4c [4];
  undefined4 *local_48;
  uint local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  char *local_38;
  uint local_34;
  undefined1 local_2c [4];
  undefined4 *local_28;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf900;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_D__work_rcsk_Code_game_Rco_Bonus_004f45cc;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_D__work_rcsk_Code_game_Rco_Bonus_004f45cc;
    pcVar6 = local_38;
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
    local_38[uVar2] = '\0';
    local_34 = uVar2;
  }
  local_4 = 0;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = (char *)&DAT_00544aec;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar5 = &DAT_00544aec;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *local_28 = *puVar5;
      puVar5 = puVar5 + 1;
      local_28 = local_28 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)local_28 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      local_28 = (undefined4 *)((int)local_28 + 1);
    }
    FUN_0040b5e0(uVar2);
  }
  local_4._0_1_ = 1;
  FUN_00464530(*(undefined4 *)(param_1 + 0x30),local_2c,local_3c,0xe3);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  uVar2 = 0xffffffff;
  local_18 = 0;
  pcVar4 = s_D__work_rcsk_Code_game_Rco_Bonus_004f45f4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_14 = 0;
  local_10 = 0;
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Bonus_004f45f4,~uVar2 - 1);
  local_4 = 2;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = (char *)&DAT_00544af0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar5 = &DAT_00544af0;
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
  FUN_00464530(*(undefined4 *)(param_1 + 0x34),local_4c,local_1c,0xe4);
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
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_18 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150((char *)(local_18 + -1));
  }
  ExceptionList = local_c;
  return;
}

