/*
 * FUN_00468d30 at 00468d30
 * undefined FUN_00468d30(void)
 * Address ranges: 00468d30-00468f09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00468d30(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int iStack_3c;
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
  puStack_8 = &LAB_004cfd7f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x8c))();
  iStack_3c = 0;
  if (0 < iVar2) {
    do {
      uVar4 = 0xffffffff;
      pcStack_28 = (char *)0x0;
      uStack_24 = 0;
      piVar3 = *(int **)(*(int *)(*(int *)(param_1 + 0x90) + 4) + iStack_3c * 4);
      pcVar6 = s_D__work_rcsk_Code_game_Rco_Overl_004f4ff0;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4 - 1;
      uStack_20 = 0;
      cVar1 = FUN_0040b600(uVar4,1);
      if (cVar1 != '\0') {
        pcVar6 = s_D__work_rcsk_Code_game_Rco_Overl_004f4ff0;
        pcVar7 = pcStack_28;
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
        FUN_0040b5e0(uVar4);
      }
      uVar4 = 0xffffffff;
      uStack_4 = 0;
      pcVar6 = s_Invalid_element_in_element_array_004f5018;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      iStack_18 = 0;
      uStack_14 = 0;
      uStack_10 = 0;
      FUN_0040b540(s_Invalid_element_in_element_array_004f5018,~uVar4 - 1);
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      FUN_00464530(piVar3,auStack_1c,auStack_2c,0x149);
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
      uStack_4 = 0xffffffff;
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
      (**(code **)(*piVar3 + 8))();
      iStack_3c = iStack_3c + 1;
    } while (iStack_3c < iVar2);
  }
  piVar3 = (int *)FUN_00469110();
  (**(code **)(*piVar3 + 8))();
  piVar3 = (int *)FUN_00469260();
  (**(code **)(*piVar3 + 8))();
  piVar3 = (int *)FUN_004693b0();
  (**(code **)(*piVar3 + 8))();
  FUN_00469500();
  FUN_00464a70();
  ExceptionList = pvStack_c;
  return;
}

