/*
 * FUN_004616a0 at 004616a0
 * undefined FUN_004616a0(void)
 * Address ranges: 004616a0-00461861
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004616a0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  int iStack_38;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cf19f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (*(code *)**(undefined4 **)(param_1 + 8))();
  iStack_38 = 0;
  if (0 < iVar3) {
    do {
      auStack_2c[0] = (undefined1)param_2;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar9 = s_D__work_rcsk_Code_game_Hud_Manag_004f3c08;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      uVar6 = ~uVar6 - 1;
      cVar2 = FUN_0040b600(uVar6,1);
      if (cVar2 != '\0') {
        pcVar9 = s_D__work_rcsk_Code_game_Hud_Manag_004f3c08;
        pcVar11 = pcStack_28;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *pcVar11 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar11 = pcVar11 + 1;
        }
        pcStack_28[uVar6] = '\0';
        uStack_24 = uVar6;
      }
      iStack_4 = 0;
      uVar4 = FUN_00412710(auStack_1c,s_Invalid_font_while_looking_for_004f3c30,param_2);
      iStack_4._0_1_ = 1;
      FUN_00464530(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 4) + iStack_38 * 4),uVar4,
                   auStack_2c,0x183);
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      FUN_0040b4f0(1);
      iStack_4 = 0xffffffff;
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
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 4) + iStack_38 * 4);
      uVar6 = *(uint *)(param_2 + 8);
      pbVar12 = &DAT_004d2404;
      if (*(byte **)(param_2 + 4) != (byte *)0x0) {
        pbVar12 = *(byte **)(param_2 + 4);
      }
      uVar7 = *(uint *)(iVar1 + 0x810);
      uVar8 = uVar7;
      if (uVar6 <= uVar7) {
        uVar8 = uVar6;
      }
      bVar13 = false;
      iVar5 = 0;
      bVar14 = true;
      pbVar10 = *(byte **)(iVar1 + 0x80c);
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar13 = *pbVar10 < *pbVar12;
        bVar14 = *pbVar10 == *pbVar12;
        pbVar10 = pbVar10 + 1;
        pbVar12 = pbVar12 + 1;
      } while (bVar14);
      if (!bVar14) {
        iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      }
      if (((iVar5 == 0) && (uVar6 <= uVar7)) && (uVar7 == uVar6)) {
        ExceptionList = pvStack_c;
        return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 4) + iStack_38 * 4);
      }
      iStack_38 = iStack_38 + 1;
    } while (iStack_38 < iVar3);
  }
  ExceptionList = pvStack_c;
  return 0;
}

