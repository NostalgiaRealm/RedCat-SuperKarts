/*
 * FUN_004463b0 at 004463b0
 * undefined FUN_004463b0(void)
 * Address ranges: 004463b0-0044670c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004463b0(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_17c [4];
  char *local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined1 local_16c [4];
  char *local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined1 local_15c [4];
  undefined1 *local_158;
  int local_154;
  undefined1 local_14c [4];
  char *local_148;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd6d8;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 8) == '\0') {
    ExceptionList = &local_c;
    FUN_004afce0(s__s__d____Loading_dynamic_path_ty_004ef7e8,
                 s_D__work_rcsk_Code_game_pth_PathC_004ef7b8,0x197);
    FUN_004be8cb(local_10c,0x100,s_animobj_d_ini_004ef810,DAT_0053b9b4);
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar5 = local_10c;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = local_10c;
      pcVar6 = local_148;
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
    local_4 = 0;
    FUN_004be8cb(local_10c,0x100,s_etappe_d_ini_004ef820,DAT_0053b9b4);
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar5 = local_10c;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = local_10c;
      pcVar6 = local_168;
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
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar5 = s_PATH_OBJECTS_004ef830;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = s_PATH_OBJECTS_004ef830;
      pcVar6 = local_178;
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
    local_4._0_1_ = 2;
    FUN_00474410(local_14c,local_17c);
    local_4 = CONCAT31(local_4._1_3_,3);
    cVar1 = FUN_00474b20();
    if (cVar1 == '\0') {
      FUN_004afce0(s___s__d___No_pathing_objects_for_e_004ef870,
                   s_D__work_rcsk_Code_game_pth_PathC_004ef840,0x1a9,DAT_0053b9b4);
    }
    FUN_0040b4f0(0);
    local_4 = CONCAT31(local_4._1_3_,4);
    FUN_00474850(local_15c);
    while (local_154 != 0) {
      puVar2 = local_158;
      if (local_158 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      FUN_004afce0(s__s__d____current_object_name__s_004ef8cc,
                   s_D__work_rcsk_Code_game_pth_PathC_004ef89c,0x1b6,puVar2);
      FUN_00446710(local_14c,local_16c,local_15c);
      FUN_004749a0(local_15c);
    }
    FUN_004afce0(s__s__d____Finished_loading_dynami_004ef920,
                 s_D__work_rcsk_Code_game_pth_PathC_004ef8f0,0x1bf);
    *(undefined1 *)(param_1 + 8) = 1;
    local_4._0_1_ = 3;
    FUN_0040b4f0(1);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_004746d0();
    if (local_178 != (char *)0x0) {
      cVar1 = local_178[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_178 + -1);
      }
      else {
        local_178[-1] = cVar1 + -1;
      }
    }
    local_178 = (char *)0x0;
    local_174 = 0;
    local_170 = 0;
    if (local_168 != (char *)0x0) {
      cVar1 = local_168[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_168 + -1);
      }
      else {
        local_168[-1] = cVar1 + -1;
      }
    }
    local_168 = (char *)0x0;
    local_164 = 0;
    local_160 = 0;
    if (local_148 != (char *)0x0) {
      cVar1 = local_148[-1];
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        local_148[-1] = cVar1 + -1;
        ExceptionList = local_c;
        return;
      }
      FUN_004bc150(local_148 + -1);
    }
  }
  ExceptionList = local_c;
  return;
}

