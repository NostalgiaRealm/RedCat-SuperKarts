/*
 * FUN_00468a00 at 00468a00
 * undefined FUN_00468a00(void)
 * Address ranges: 00468a00-00468b74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00468a00(int param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *local_34;
  void *local_30;
  undefined1 local_2c [4];
  int local_28;
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
  puStack_8 = &LAB_004cfd40;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_30 = operator_new(0x40);
  local_4 = 0;
  if (local_30 == (void *)0x0) {
    local_34 = (int *)0x0;
  }
  else {
    local_34 = (int *)FUN_0046dcb0(param_1);
  }
  uVar2 = 0xffffffff;
  local_4 = 0xffffffff;
  pcVar3 = s_D__work_rcsk_Code_game_Rco_Overl_004f4f7c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Overl_004f4f7c,~uVar2 - 1);
  uVar2 = 0xffffffff;
  local_4 = 1;
  pcVar3 = s_Unable_to_create_overlay_element_004f4fa4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  FUN_0040b540(s_Unable_to_create_overlay_element_004f4fa4,~uVar2 - 1);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00464530(local_34,local_2c,local_1c,0x120);
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
  (**(code **)(*local_34 + 4))();
  FUN_00459170(*(undefined4 *)(*(int *)(param_1 + 0x90) + 8),1,&local_34);
  ExceptionList = pvStack_c;
  return;
}

