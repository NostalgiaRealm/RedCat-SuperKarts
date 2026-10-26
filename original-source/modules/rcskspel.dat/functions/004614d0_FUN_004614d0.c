/*
 * FUN_004614d0 at 004614d0
 * undefined FUN_004614d0(void)
 * Address ranges: 004614d0-00461648
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004614d0(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_cc [64];
  undefined1 local_8c [72];
  undefined1 local_44 [4];
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34 [4];
  int local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  char *local_24;
  uint local_20;
  undefined4 local_1c;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_004cf185;
  local_10 = ExceptionList;
  local_14 = &stack0xffffff28;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_00462320(local_cc,local_8c,local_34,local_2c);
  local_44[0] = local_15;
  uVar2 = 0xffffffff;
  local_40 = 0;
  pcVar4 = s_D__work_rcsk_Code_game_Hud_Manag_004f3bb8;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_3c = 0;
  local_38 = 0;
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3bb8,~uVar2 - 1);
  local_28[0] = local_15;
  local_8._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_Uninitialized_overlay_004f3be0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_Uninitialized_overlay_004f3be0;
    pcVar5 = local_24;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    local_24[uVar2] = '\0';
    local_20 = uVar2;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00464530(*(undefined4 *)(local_30 + 4),local_28,local_44,0x161);
  if (local_24 != (char *)0x0) {
    cVar1 = local_24[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_24 + -1);
    }
    else {
      local_24[-1] = cVar1 + -1;
    }
  }
  local_24 = (char *)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = local_8 & 0xffffff00;
  if (local_40 != 0) {
    cVar1 = *(char *)(local_40 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(local_40 + -1));
    }
    else {
      *(char *)(local_40 + -1) = cVar1 + -1;
    }
  }
  FUN_00458550(local_30 + 0x18);
  FUN_00462610(local_cc,local_8c,local_34,local_2c);
  ExceptionList = local_10;
  return;
}

