/*
 * FUN_00465080 at 00465080
 * undefined FUN_00465080(void)
 * Address ranges: 00465080-004653bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00465080(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_4c [4];
  char *local_48;
  undefined1 local_3c [4];
  char *local_38;
  undefined1 local_2c [4];
  char *local_28;
  undefined1 local_1c [4];
  char *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf760;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_BackArrow_004f41e8;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_BackArrow_004f41e8;
    pcVar6 = local_48;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 0;
  uVar2 = FUN_00461470(local_4c);
  *(undefined4 *)(param_1 + 8) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_JunctionArrow_004f41f4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_JunctionArrow_004f41f4;
    pcVar6 = local_48;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 1;
  uVar2 = FUN_00461470(local_4c);
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Rco_Arrow_004f4204;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_D__work_rcsk_Code_game_Rco_Arrow_004f4204;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)local_38 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      local_38 = local_38 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_38 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      local_38 = local_38 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 2;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_Element_BackArrow_not_found_in_o_004f422c;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_Element_BackArrow_not_found_in_o_004f422c;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)local_48 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      local_48 = local_48 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_48 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      local_48 = local_48 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4._0_1_ = 3;
  FUN_00464530(*(undefined4 *)(param_1 + 8),local_4c,local_3c,0x2d);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Rco_Arrow_004f4254;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_D__work_rcsk_Code_game_Rco_Arrow_004f4254;
    pcVar6 = local_18;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 4;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_Element_JunctionArrow_not_found_i_004f427c;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_Element_JunctionArrow_not_found_i_004f427c;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)local_28 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      local_28 = local_28 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_28 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      local_28 = local_28 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4._0_1_ = 5;
  FUN_00464530(*(undefined4 *)(param_1 + 0xc),local_2c,local_1c,0x2e);
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_0040b4f0(1);
  if (local_18 != (char *)0x0) {
    cVar1 = local_18[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      local_18[-1] = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150(local_18 + -1);
  }
  ExceptionList = local_c;
  return;
}

