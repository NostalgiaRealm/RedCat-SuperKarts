/*
 * FUN_0040de60 at 0040de60
 * undefined FUN_0040de60(void)
 * Address ranges: 0040de60-0040dfca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040de60(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 local_2c [4];
  char *local_28;
  uint local_24;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccd6c;
  local_c = ExceptionList;
  if ((&DAT_00503ef4)[param_1 * 0x47] != 9) {
    local_2c[0] = (undefined1)param_1;
    uVar4 = 0xffffffff;
    pcVar6 = s_CHEER_004deff0;
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
    ExceptionList = &local_c;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = s_CHEER_004deff0;
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
    local_4 = 0;
    puVar2 = (undefined4 *)FUN_0044a700(param_1);
    (**(code **)*puVar2)(local_2c);
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
    FUN_004afce0(s__s__d____Enemy___d__hit_redcat_s_004df028,
                 s_D__work_rcsk_Code_game_ai_rcr_ch_004deff8,0x238,param_1);
    uVar3 = FUN_00437ff0(auStack_1c);
    local_4 = 1;
    FUN_004387a0(param_1,uVar3);
    local_4 = 0xffffffff;
    if (iStack_18 != 0) {
      cVar1 = *(char *)(iStack_18 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(iStack_18 + -1));
      }
      else {
        *(char *)(iStack_18 + -1) = cVar1 + -1;
      }
    }
    iStack_18 = 0;
    uStack_14 = 0;
    uStack_10 = 0;
    FUN_004afce0(s__s__d____Done_enemy___d__hit_red_004df080,
                 s_D__work_rcsk_Code_game_ai_rcr_ch_004df050,0x23e,param_1);
  }
  ExceptionList = local_c;
  return;
}

