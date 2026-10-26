/*
 * FUN_0047f130 at 0047f130
 * undefined FUN_0047f130(void)
 * Address ranges: 0047f130-0047f36a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0047f130(int param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined1 auStack_5c [4];
  int iStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined1 local_4c [4];
  undefined1 *local_48;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d11d7;
  pvStack_c = ExceptionList;
  local_4c[0] = *param_2;
  ExceptionList = &pvStack_c;
  FUN_0040b4f0(0);
  FUN_00412870(param_2,0,0xffffffff);
  local_4 = 0;
  iVar2 = FUN_00481730();
  if (iVar2 == 0) {
    FUN_00460300(&DAT_00545018,0,0xffffffff);
  }
  FUN_00474410(param_1 + 0x5c,local_4c);
  local_4 = CONCAT31(local_4._1_3_,1);
  cVar1 = FUN_00474b20();
  if (cVar1 == '\0') {
    puVar3 = local_48;
    if (local_48 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004afee0(s__s__d____Error_reading_section___004f9168,
                 s_D__work_rcsk_Code_game_Requester_004f9140,0x1d3,puVar3);
  }
  puVar3 = *(undefined1 **)(param_1 + 0x60);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar3);
  auStack_5c[0] = param_2._0_1_;
  FUN_0040b4f0(0);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00474850(auStack_5c);
  while (iStack_54 != 0) {
    FUN_0047ed50(local_4c,auStack_5c);
    FUN_004749a0(auStack_5c);
  }
  FUN_00412870(param_2,0,0xffffffff);
  puVar3 = *(undefined1 **)(param_1 + 8);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Current_requester__s_004f91b8,s_D__work_rcsk_Code_game_Requester_004f9190,
               0x1e6,puVar3);
  uVar4 = 0xffffffff;
  pcVar7 = (char *)&DAT_0054503c;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    puVar6 = &DAT_0054503c;
    puVar8 = *(undefined4 **)(param_1 + 0x18);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    *(uint *)(param_1 + 0x1c) = uVar4;
    *(undefined1 *)(*(int *)(param_1 + 0x18) + uVar4) = 0;
  }
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  if (iStack_58 != 0) {
    cVar1 = *(char *)(iStack_58 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iStack_58 + -1));
    }
    else {
      *(char *)(iStack_58 + -1) = cVar1 + -1;
    }
  }
  iStack_58 = 0;
  iStack_54 = 0;
  uStack_50 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_004746d0();
  if (local_48 != (undefined1 *)0x0) {
    cVar1 = local_48[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      local_48[-1] = cVar1 + -1;
      ExceptionList = pvStack_c;
      return;
    }
    FUN_004bc150(local_48 + -1);
  }
  ExceptionList = pvStack_c;
  return;
}

