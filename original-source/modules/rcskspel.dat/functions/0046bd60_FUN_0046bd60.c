/*
 * FUN_0046bd60 at 0046bd60
 * undefined FUN_0046bd60(void)
 * Address ranges: 0046bd60-0046bf79
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046bd60(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 local_3c [4];
  char *local_38;
  uint local_34;
  undefined4 local_30;
  undefined1 local_2c [4];
  char *local_28;
  uint local_24;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d029a;
  pvStack_c = ExceptionList;
  uVar4 = 0xffffffff;
  pcVar6 = s_STRING_SPECIAL_004f58d4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  ExceptionList = &pvStack_c;
  FUN_0040b540(s_STRING_SPECIAL_004f58d4,~uVar4 - 1);
  local_4 = 0;
  uVar2 = FUN_004621a0(local_1c);
  *(undefined4 *)(param_1 + 0x30) = uVar2;
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
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Speci_004f58e4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar6 = s_D__work_rcsk_Code_game_Rco_Speci_004f58e4;
    pcVar7 = local_38;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    local_38[uVar4] = '\0';
    local_34 = uVar4;
  }
  local_4 = 1;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar6 = s_String_STRING_SPECIAL_not_found_i_004f5914;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar6 = s_String_STRING_SPECIAL_not_found_i_004f5914;
    pcVar7 = local_28;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    local_28[uVar4] = '\0';
    local_24 = uVar4;
  }
  local_4._0_1_ = 2;
  FUN_00464530(*(undefined4 *)(param_1 + 0x30),local_2c,local_3c,0x47);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  if (local_38 != (char *)0x0) {
    cVar1 = local_38[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_38 + -1);
    }
    else {
      local_38[-1] = cVar1 + -1;
    }
  }
  local_38 = (char *)0x0;
  local_34 = 0;
  local_30 = 0;
  puVar3 = (undefined4 *)FUN_00458590();
  _DAT_00544b4c = *puVar3;
  puVar3 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x30) + 0x20))();
  _DAT_00544b40 = *puVar3;
  _DAT_00544b44 = puVar3[1];
  _DAT_00544b48 = puVar3[2];
  puVar3 = (undefined4 *)FUN_004583d0();
  _DAT_00544b30 = *puVar3;
  _DAT_00544b34 = puVar3[1];
  ExceptionList = pvStack_c;
  _DAT_00544b38 = puVar3[2];
  return;
}

