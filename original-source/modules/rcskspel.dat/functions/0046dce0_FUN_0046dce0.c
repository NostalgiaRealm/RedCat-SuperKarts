/*
 * FUN_0046dce0 at 0046dce0
 * undefined FUN_0046dce0(void)
 * Address ranges: 0046dce0-0046e06b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046dce0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  undefined1 local_4c [4];
  char *local_48;
  undefined4 local_44;
  undefined4 local_40;
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
  puStack_8 = &LAB_004d0550;
  local_c = ExceptionList;
  DAT_00544b5c = DAT_00544b5c & DAT_0053ba6c == 1;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f5c74;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = (char *)&DAT_004f5c74;
    pcVar7 = local_38;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 0;
  uVar2 = FUN_00461470(local_3c);
  *(undefined4 *)(param_1 + 8) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Rco_stars_004f5c80;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_D__work_rcsk_Code_game_Rco_stars_004f5c80;
    pcVar7 = local_28;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_Element_Starflag_not_found_in_ov_004f5ca8;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_Element_Starflag_not_found_in_ov_004f5ca8;
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
  local_4._0_1_ = 2;
  FUN_00464530(*(undefined4 *)(param_1 + 8),local_3c,local_2c,0x39);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_00458460(1);
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_Stars_004f5cd0;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_Stars_004f5cd0;
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
  local_4 = 3;
  uVar2 = FUN_004614b0(local_2c);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Rco_stars_004f5cd8;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_D__work_rcsk_Code_game_Rco_stars_004f5cd8;
    pcVar7 = local_48;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 4;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_Composite_Stars_not_found_in_ove_004f5d00;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_Composite_Stars_not_found_in_ove_004f5d00;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)local_18 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      local_18 = local_18 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_18 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      local_18 = local_18 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  iVar6 = 0;
  local_4._0_1_ = 5;
  FUN_00464530(uVar2,local_1c,local_4c,0x3e);
  local_4 = CONCAT31(local_4._1_3_,4);
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
  FUN_00458460(1);
  do {
    FUN_0046e070(iVar6,uVar2);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xc);
  ExceptionList = local_c;
  return;
}

