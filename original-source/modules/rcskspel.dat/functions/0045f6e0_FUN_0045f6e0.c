/*
 * FUN_0045f6e0 at 0045f6e0
 * undefined FUN_0045f6e0(void)
 * Address ranges: 0045f6e0-0045f89a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0045f6e0(int param_1,float param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  char *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ced88;
  pvStack_c = ExceptionList;
  bVar2 = false;
  bVar1 = false;
  ExceptionList = &pvStack_c;
  if (param_2 == 0.0) {
    local_1c[0] = param_2._0_1_;
    uVar4 = 0xffffffff;
    pcVar6 = s_D__work_rcsk_Code_game_Hud_IniFi_004f36e0;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    uVar4 = ~uVar4 - 1;
    local_18 = (char *)0x0;
    local_14 = 0;
    local_10 = 0;
    ExceptionList = &pvStack_c;
    cVar3 = FUN_0040b600(uVar4,1);
    if (cVar3 != '\0') {
      pcVar6 = s_D__work_rcsk_Code_game_Hud_IniFi_004f36e0;
      pcVar7 = local_18;
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
    local_2c[0] = param_2._0_1_;
    uVar4 = 0xffffffff;
    local_4 = 0;
    pcVar6 = s_a_Depth____0_0f_004f370c;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    FUN_0040b540(s_a_Depth____0_0f_004f370c,~uVar4 - 1);
    bVar2 = true;
    bVar1 = true;
    local_4 = 1;
    FUN_00464610(local_2c,local_1c,0x3ef);
  }
  if (bVar1) {
    if (local_28 != 0) {
      cVar3 = *(char *)(local_28 + -1);
      if ((cVar3 == '\0') || (cVar3 == -1)) {
        FUN_004bc150((char *)(local_28 + -1));
      }
      else {
        *(char *)(local_28 + -1) = cVar3 + -1;
      }
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
  }
  if (bVar2) {
    if (local_18 == (char *)0x0) {
      *(float *)(param_1 + 0x20) = param_2;
      ExceptionList = pvStack_c;
      return;
    }
    cVar3 = local_18[-1];
    if ((cVar3 == '\0') || (cVar3 == -1)) {
      FUN_004bc150(local_18 + -1);
      *(float *)(param_1 + 0x20) = param_2;
      ExceptionList = pvStack_c;
      return;
    }
    local_18[-1] = cVar3 + -1;
  }
  *(float *)(param_1 + 0x20) = param_2;
  ExceptionList = pvStack_c;
  return;
}

