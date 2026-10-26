/*
 * FUN_00468860 at 00468860
 * undefined FUN_00468860(void)
 * Address ranges: 00468860-004689f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00468860(int param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 local_2c [4];
  char *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cfd1b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar2 = operator_new(0x70);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0046bd10(param_1);
  }
  *(undefined4 *)(param_1 + 0x94) = uVar3;
  uVar4 = 0xffffffff;
  local_4 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Overl_004f4f30;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  local_28 = (char *)0x0;
  local_24 = 0;
  local_20 = 0;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar6 = s_D__work_rcsk_Code_game_Rco_Overl_004f4f30;
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
    FUN_0040b5e0(uVar4);
  }
  uVar4 = 0xffffffff;
  local_4 = 1;
  pcVar6 = s_Unable_to_create_overlay_element_004f4f58;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_0040b540(s_Unable_to_create_overlay_element_004f4f58,~uVar4 - 1);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00464530(*(undefined4 *)(param_1 + 0x94),local_1c,local_2c,0x110);
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
  local_4 = 0xffffffff;
  if (local_28 != (char *)0x0) {
    cVar1 = local_28[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_28 + -1);
    }
    else {
      local_28[-1] = cVar1 + -1;
    }
  }
  local_28 = (char *)0x0;
  local_24 = 0;
  local_20 = 0;
  (**(code **)(**(int **)(param_1 + 0x94) + 4))();
  ExceptionList = pvStack_c;
  return;
}

