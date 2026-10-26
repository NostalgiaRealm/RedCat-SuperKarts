/*
 * FUN_0046eac0 at 0046eac0
 * undefined FUN_0046eac0(void)
 * Address ranges: 0046eac0-0046ecbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046eac0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_3c [4];
  char *local_38;
  uint local_34;
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c [3];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d068b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = "STRING_COUNTDOWN_VALUE";
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = "STRING_COUNTDOWN_VALUE";
    pcVar6 = local_38;
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
    local_38[uVar3] = '\0';
    local_34 = uVar3;
  }
  local_4 = 0;
  uVar2 = FUN_004621a0(local_3c);
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  uVar3 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Rco_Stati_004f5e9c;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Stati_004f5e9c,~uVar3 - 1);
  local_4 = 1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = &DAT_00544b70;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = &DAT_00544b70;
    pcVar6 = local_38;
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
    local_38[uVar3] = '\0';
    local_34 = uVar3;
  }
  local_4._0_1_ = 2;
  FUN_00464530(*(undefined4 *)(param_1 + 0x20),local_3c,local_2c,0x54);
  local_4 = CONCAT31(local_4._1_3_,1);
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
  uVar2 = FUN_0042a4d0(0x12);
  uVar2 = FUN_0046f770(local_1c,uVar2);
  local_4 = 3;
  (**(code **)(**(int **)(param_1 + 0x20) + 0x50))(uVar2);
  if (local_1c[0] != 0) {
    cVar1 = *(char *)(local_1c[0] + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_1c[0] + -1) = cVar1 + -1;
      ExceptionList = pvStack_10;
      return;
    }
    FUN_004bc150((char *)(local_1c[0] + -1));
  }
  ExceptionList = pvStack_10;
  return;
}

