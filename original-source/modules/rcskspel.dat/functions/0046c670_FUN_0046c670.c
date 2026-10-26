/*
 * FUN_0046c670 at 0046c670
 * undefined FUN_0046c670(void)
 * Address ranges: 0046c670-0046c855
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0046c670(int param_1,undefined4 param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int unaff_ESI;
  char *pcVar8;
  char *pcVar9;
  undefined1 local_2c [4];
  char *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0358;
  pvStack_c = ExceptionList;
  bVar2 = false;
  bVar1 = false;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_1 + 8) == 1) {
    local_2c[0] = (undefined1)param_2;
    uVar6 = 0xffffffff;
    pcVar8 = s_D__work_rcsk_Code_game_Rco_Speci_004f5a58;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    uVar6 = ~uVar6 - 1;
    local_28 = (char *)0x0;
    local_24 = 0;
    local_20 = 0;
    ExceptionList = &pvStack_c;
    cVar3 = FUN_0040b600(uVar6,1);
    if (cVar3 != '\0') {
      pcVar8 = s_D__work_rcsk_Code_game_Rco_Speci_004f5a58;
      pcVar9 = local_28;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      FUN_0040b5e0(uVar6);
    }
    local_1c[0] = (undefined1)param_2;
    uVar6 = 0xffffffff;
    local_4 = 0;
    pcVar8 = s_m_State____ST_MOVING_004f5a88;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    local_18 = (void *)0x0;
    local_14 = 0;
    local_10 = 0;
    FUN_0040b540(s_m_State____ST_MOVING_004f5a88,~uVar6 - 1);
    bVar2 = true;
    bVar1 = true;
    local_4 = 1;
    FUN_00464610(local_1c,local_2c,0xd7);
  }
  if (bVar1) {
    if (local_18 != (void *)0x0) {
      cVar3 = *(char *)((int)local_18 + -1);
      if ((cVar3 == '\0') || (cVar3 == -1)) {
        FUN_004bc150((char *)((int)local_18 + -1));
      }
      else {
        *(char *)((int)local_18 + -1) = cVar3 + -1;
      }
    }
    local_18 = (void *)0x0;
    local_14 = 0;
    local_10 = 0;
  }
  local_4 = 0xffffffff;
  if (bVar2) {
    if (local_28 != (char *)0x0) {
      cVar3 = local_28[-1];
      if ((cVar3 == '\0') || (cVar3 == -1)) {
        FUN_004bc150(local_28 + -1);
      }
      else {
        local_28[-1] = cVar3 + -1;
      }
    }
    local_28 = (char *)0x0;
    local_24 = 0;
    local_20 = 0;
  }
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  piVar4 = (int *)FUN_0046c510();
  FUN_00458400(&DAT_00544b30);
  (**(code **)(*piVar4 + 0x28))(&DAT_00544b4c);
  (**(code **)(*piVar4 + 0x24))(&DAT_00544b40);
  (**(code **)(*piVar4 + 0x3c))(0x3f800000);
  iVar5 = *(int *)(unaff_ESI + 0x6c) * 8;
  *(undefined4 *)(unaff_ESI + 0x28) = *(undefined4 *)(&DAT_004d2d40 + iVar5);
  *(undefined4 *)(unaff_ESI + 100) = *(undefined4 *)(&DAT_004d2d44 + iVar5);
  ExceptionList = local_18;
  return;
}

