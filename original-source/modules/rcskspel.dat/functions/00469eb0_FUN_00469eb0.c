/*
 * FUN_00469eb0 at 00469eb0
 * undefined FUN_00469eb0(void)
 * Address ranges: 00469eb0-0046a1e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00469eb0(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
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
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cff2c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_D__work_rcsk_Code_game_Rco_Portr_004f535c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_D__work_rcsk_Code_game_Rco_Portr_004f535c;
    pcVar5 = local_38;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    FUN_0040b5e0(uVar2);
  }
  local_4 = 0;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_Invalid_foreground_004f5388;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_Invalid_foreground_004f5388;
    pcVar5 = local_48;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    FUN_0040b5e0(uVar2);
  }
  local_4._0_1_ = 1;
  FUN_00464530(*(undefined4 *)(param_1 + 0x30),local_4c,local_3c,0x60);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_D__work_rcsk_Code_game_Rco_Portr_004f539c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_D__work_rcsk_Code_game_Rco_Portr_004f539c;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)local_48 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      local_48 = local_48 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *local_48 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      local_48 = local_48 + 1;
    }
    FUN_0040b5e0(uVar2);
  }
  local_4 = 2;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_Invalid_frame_004f53c8;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_Invalid_frame_004f53c8;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)local_38 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      local_38 = local_38 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *local_38 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      local_38 = local_38 + 1;
    }
    FUN_0040b5e0(uVar2);
  }
  local_4._0_1_ = 3;
  FUN_00464530(*(undefined4 *)(param_1 + 0x34),local_3c,local_4c,0x61);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_D__work_rcsk_Code_game_Rco_Portr_004f53d8;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_D__work_rcsk_Code_game_Rco_Portr_004f53d8;
    pcVar5 = local_18;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    FUN_0040b5e0(uVar2);
  }
  local_4 = 4;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_Invalid_background_004f5404;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_Invalid_background_004f5404;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)local_28 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      local_28 = local_28 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *local_28 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      local_28 = local_28 + 1;
    }
    FUN_0040b5e0(uVar2);
  }
  local_4._0_1_ = 5;
  FUN_00464530(*(undefined4 *)(param_1 + 0x38),local_2c,local_1c,0x62);
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

