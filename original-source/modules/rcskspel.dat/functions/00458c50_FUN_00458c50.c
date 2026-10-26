/*
 * FUN_00458c50 at 00458c50
 * undefined FUN_00458c50(void)
 * Address ranges: 00458c50-00458ddf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00458c50(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  int local_38;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cdf6b;
  pvStack_c = ExceptionList;
  puVar3 = *(undefined1 **)(param_1 + 0x38);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  ExceptionList = &pvStack_c;
  FUN_004afce0(s_Name____s__Composite__004f283c,puVar3);
  local_38 = 0;
  iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x74))();
  if (0 < iVar4) {
    do {
      uVar6 = 0xffffffff;
      piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x78) + 4) + local_38 * 4);
      pcStack_28 = (char *)0x0;
      pcVar8 = s_D__work_rcsk_Code_game_Hud_Compo_004f2854;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      uVar6 = ~uVar6 - 1;
      uStack_24 = 0;
      uStack_20 = 0;
      cVar2 = FUN_0040b600(uVar6,1);
      if (cVar2 != '\0') {
        pcVar8 = s_D__work_rcsk_Code_game_Hud_Compo_004f2854;
        pcVar9 = pcStack_28;
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
      uStack_4 = 0;
      uVar5 = FUN_00412710(auStack_1c,s_NULL_Component_in_Child_Componen_004f2880,param_1 + 0x34);
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      FUN_00464530(piVar1,uVar5,auStack_2c,0x128);
      if (iStack_18 != 0) {
        cVar2 = *(char *)(iStack_18 + -1);
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_004bc150((char *)(iStack_18 + -1));
        }
        else {
          *(char *)(iStack_18 + -1) = cVar2 + -1;
        }
      }
      iStack_18 = 0;
      uStack_14 = 0;
      uStack_10 = 0;
      uStack_4 = 0xffffffff;
      if (pcStack_28 != (char *)0x0) {
        cVar2 = pcStack_28[-1];
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_004bc150(pcStack_28 + -1);
        }
        else {
          pcStack_28[-1] = cVar2 + -1;
        }
      }
      pcStack_28 = (char *)0x0;
      uStack_24 = 0;
      uStack_20 = 0;
      (**(code **)(*piVar1 + 0x2c))();
      local_38 = local_38 + 1;
      iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x74))();
    } while (local_38 < iVar4);
  }
  ExceptionList = pvStack_c;
  return;
}

