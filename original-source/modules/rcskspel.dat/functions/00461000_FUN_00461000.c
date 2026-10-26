/*
 * FUN_00461000 at 00461000
 * undefined FUN_00461000(void)
 * Address ranges: 00461000-00461166
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __thiscall FUN_00461000(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_2c [4];
  char *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf137;
  pvStack_c = ExceptionList;
  local_2c[0] = (undefined1)param_2;
  uVar3 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Hud_Manag_004f3ad4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  local_28 = (char *)0x0;
  local_24 = 0;
  local_20 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_D__work_rcsk_Code_game_Hud_Manag_004f3ad4;
    pcVar6 = local_28;
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
  local_1c[0] = (undefined1)param_2;
  uVar3 = 0xffffffff;
  local_4 = 0;
  pcVar5 = s_Invalid_element_m_Top_in_overlay_004f3afc;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_18 = 0;
  local_14 = 0;
  local_10 = (void *)0x0;
  FUN_0040b540(s_Invalid_element_m_Top_in_overlay_004f3afc,~uVar3 - 1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00464530(*(undefined4 *)(param_1 + 4),local_1c,local_2c,0xbd);
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
  local_10 = (void *)0x0;
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
  iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0xc))(param_2);
  ExceptionList = local_10;
  return iVar2 != 0;
}

