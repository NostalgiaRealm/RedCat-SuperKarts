/*
 * FUN_0045ad40 at 0045ad40
 * undefined FUN_0045ad40(void)
 * Address ranges: 0045ad40-0045ae32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 __thiscall FUN_0045ad40(int param_1,byte param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  float10 fVar6;
  byte local_1c [4];
  char *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce26a;
  local_c = ExceptionList;
  local_1c[0] = param_2;
  uVar2 = 0xffffffff;
  pcVar4 = s_D__work_rcsk_Code_game_Hud_Font__004f2c18;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = 0;
  ExceptionList = &local_c;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_D__work_rcsk_Code_game_Hud_Font__004f2c18;
    pcVar5 = local_18;
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
    local_18[uVar2] = '\0';
    local_14 = uVar2;
  }
  uVar2 = (uint)param_2;
  local_4 = 0;
  FUN_00464260(uVar2,0,0xff,local_1c,0x36);
  if (local_18 == (char *)0x0) {
    fVar6 = (float10)*(float *)(param_1 + 4 + uVar2 * 8);
  }
  else {
    cVar1 = local_18[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_18 + -1);
      fVar6 = (float10)*(float *)(param_1 + 4 + uVar2 * 8);
    }
    else {
      local_18[-1] = cVar1 + -1;
      fVar6 = (float10)*(float *)(param_1 + 4 + uVar2 * 8);
    }
  }
  ExceptionList = local_c;
  return fVar6;
}

