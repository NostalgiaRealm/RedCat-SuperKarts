/*
 * FUN_00458760 at 00458760
 * undefined FUN_00458760(void)
 * Address ranges: 00458760-004588f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00458760(int *param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cdf2f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cVar2 = FUN_004583b0();
  if (cVar2 != '\0') {
    (**(code **)(*param_1 + 0x30))(param_2);
    iVar3 = (**(code **)param_1[0x1d])();
    param_2 = 0;
    if (0 < iVar3) {
      do {
        pcStack_28 = (char *)0x0;
        uStack_24 = 0;
        uStack_20 = 0;
        uVar1 = *(undefined4 *)(*(int *)(param_1[0x1e] + 4) + param_2 * 4);
        auStack_2c[0] = (undefined1)param_2;
        uVar5 = 0xffffffff;
        pcVar7 = s_D__work_rcsk_Code_game_Hud_Compo_004f27c4;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        uVar5 = ~uVar5 - 1;
        cVar2 = FUN_0040b600(uVar5,1);
        if (cVar2 != '\0') {
          pcVar7 = s_D__work_rcsk_Code_game_Hud_Compo_004f27c4;
          pcVar8 = pcStack_28;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar8 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar8 = pcVar8 + 1;
          }
          FUN_0040b5e0(uVar5);
        }
        uStack_4 = 0;
        uVar4 = FUN_00412710(auStack_1c,s_NULL_Component_in_Child_Componen_004f27f0,param_1 + 0xd);
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        FUN_00464530(uVar1,uVar4,auStack_2c,0x3e);
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
        FUN_00458550(param_1 + 0x11);
        param_2 = param_2 + 1;
      } while (param_2 < iVar3);
    }
  }
  ExceptionList = local_c;
  return;
}

