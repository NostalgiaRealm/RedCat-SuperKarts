/*
 * FUN_0045ac50 at 0045ac50
 * undefined FUN_0045ac50(void)
 * Address ranges: 0045ac50-0045ad3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0045ac50(int param_1,byte param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  byte local_1c [4];
  char *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce258;
  local_c = ExceptionList;
  local_1c[0] = param_2;
  uVar3 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Hud_Font__004f2bf4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = 0;
  ExceptionList = &local_c;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_D__work_rcsk_Code_game_Hud_Font__004f2bf4;
    pcVar6 = local_18;
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
    local_18[uVar3] = '\0';
    local_14 = uVar3;
  }
  uVar3 = (uint)param_2;
  local_4 = 0;
  FUN_00464260(uVar3,0,0xff,local_1c,0x27);
  if (local_18 == (char *)0x0) {
    uVar2 = *(undefined4 *)(param_1 + uVar3 * 8);
  }
  else {
    cVar1 = local_18[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_18 + -1);
      uVar2 = *(undefined4 *)(param_1 + uVar3 * 8);
    }
    else {
      local_18[-1] = cVar1 + -1;
      uVar2 = *(undefined4 *)(param_1 + uVar3 * 8);
    }
  }
  ExceptionList = local_c;
  return uVar2;
}

