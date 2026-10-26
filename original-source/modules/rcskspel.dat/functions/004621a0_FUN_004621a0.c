/*
 * FUN_004621a0 at 004621a0
 * undefined FUN_004621a0(void)
 * Address ranges: 004621a0-0046231c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004621a0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cf3c7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x10))();
  iVar8 = 0;
  if (0 < iVar2) {
    do {
      auStack_2c[0] = (undefined1)param_2;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar9 = s_D__work_rcsk_Code_game_Hud_Manag_004f3e7c;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6 - 1;
      cVar1 = FUN_0040b600(uVar6,1);
      if (cVar1 != '\0') {
        pcVar9 = s_D__work_rcsk_Code_game_Hud_Manag_004f3e7c;
        pcVar5 = pcStack_28;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar5 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar5 = pcVar5 + 4;
        }
        for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *pcVar5 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar5 = pcVar5 + 1;
        }
        FUN_0040b5e0(uVar6);
      }
      iStack_4 = 0;
      uVar3 = FUN_00412710(auStack_1c,s_Invalid_string_while_looking_for_004f3ea4,param_2);
      iStack_4._0_1_ = 1;
      FUN_00464530(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 4) + iVar8 * 4),uVar3,
                   auStack_2c,0x200);
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      FUN_0040b4f0(1);
      iStack_4 = 0xffffffff;
      if (pcStack_28 != (char *)0x0) {
        cVar1 = pcStack_28[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(pcStack_28 + -1);
        }
        else {
          pcStack_28[-1] = cVar1 + -1;
        }
      }
      pcStack_28 = (char *)0x0;
      uStack_24 = 0;
      uStack_20 = 0;
      pcVar9 = "";
      if (*(char **)(param_2 + 4) != (char *)0x0) {
        pcVar9 = *(char **)(param_2 + 4);
      }
      iVar4 = FUN_004583c0();
      pcVar5 = *(char **)(iVar4 + 4);
      if (pcVar5 == (char *)0x0) {
        pcVar5 = "";
      }
      iVar4 = __strcmpi(pcVar5,pcVar9);
      if (iVar4 == 0) {
        ExceptionList = pvStack_c;
        return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 4) + iVar8 * 4);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar2);
  }
  ExceptionList = pvStack_c;
  return 0;
}

