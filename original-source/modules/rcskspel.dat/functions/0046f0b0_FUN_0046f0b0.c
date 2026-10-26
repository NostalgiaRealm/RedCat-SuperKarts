/*
 * FUN_0046f0b0 at 0046f0b0
 * undefined FUN_0046f0b0(void)
 * Address ranges: 0046f0b0-0046f221
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046f0b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  undefined1 local_3c [4];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  puStack_8 = &LAB_004d075a;
  pvStack_c = ExceptionList;
  uVar3 = 0xffffffff;
  pcVar4 = s_D__work_rcsk_Code_game_Rco_Stati_004f5f98;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  ExceptionList = &pvStack_c;
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Stati_004f5f98,~uVar3 - 1);
  uVar3 = 0xffffffff;
  local_4 = 0;
  pcVar4 = &DAT_00544b74;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  FUN_0040b540(&DAT_00544b74,~uVar3 - 1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00464530(*(undefined4 *)(param_1 + 0x20),local_3c,local_2c,0xaa);
  if (local_38 != 0) {
    cVar1 = *(char *)(local_38 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(local_38 + -1));
    }
    else {
      *(char *)(local_38 + -1) = cVar1 + -1;
    }
  }
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
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
  local_4 = 2;
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

