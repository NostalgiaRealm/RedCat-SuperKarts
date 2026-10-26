/*
 * FUN_0046aa80 at 0046aa80
 * undefined FUN_0046aa80(void)
 * Address ranges: 0046aa80-0046b290
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046aa80(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined **ppuVar14;
  int iVar15;
  char *pcVar16;
  int local_154;
  undefined **local_14c;
  undefined1 local_148 [4];
  char *local_144;
  undefined1 local_138 [4];
  char *local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 local_128 [4];
  char *local_124;
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [4];
  undefined1 *local_f4;
  undefined1 local_e8 [16];
  undefined1 local_d8 [28];
  undefined1 local_bc [16];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 local_7c [16];
  undefined1 local_6c [16];
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0195;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004b1d60(s_Race_ini_004f5610);
  local_154 = FUN_004b1ed0(s_CHARDATA_004f561c,s_Count_004f523c);
  if (local_154 < 6) {
    iVar13 = 0;
    if (0 < local_154) {
      do {
        FUN_0040b4f0(0);
        uVar10 = 0xffffffff;
        pcVar8 = s_CHARDATA_004f56ac;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(s_CHARDATA_004f56ac,~uVar10 - 1);
        local_4 = 0xf;
        uVar2 = FUN_00463d20(local_e8,iVar13);
        local_4._0_1_ = 0x10;
        FUN_00464150(local_f8,local_118,uVar2);
        local_4._0_1_ = 0x13;
        FUN_0040b4f0(1);
        local_4._0_1_ = 0x12;
        FUN_0040b4f0(1);
        puVar6 = local_f4;
        if (local_f4 == (undefined1 *)0x0) {
          puVar6 = &DAT_004d2404;
        }
        iVar7 = FUN_004b1f60(puVar6,&DAT_004f56b8);
        if (iVar7 < 4) {
          FUN_0040b4f0(0);
          uVar10 = 0xffffffff;
          pcVar8 = &DAT_004f56ec;
          goto code_r0x0046b0ab;
        }
        iVar7 = FUN_004b20c0(2);
        if (iVar7 == -1) {
          *(int *)(param_1 + 0x84) = iVar13;
        }
        iVar7 = -1;
        FUN_00464060(local_148,0);
        local_4 = CONCAT31(local_4._1_3_,0x1f);
        iVar15 = 0;
        ppuVar14 = &PTR_s_RedCat_004d2504;
        do {
          if (iVar7 != -1) goto LAB_0046ae4e;
          pcVar8 = local_144;
          if (local_144 == (char *)0x0) {
            pcVar8 = "";
          }
          iVar9 = __strcmpi(pcVar8,*ppuVar14);
          if (iVar9 == 0) {
            iVar7 = iVar15;
          }
          ppuVar14 = ppuVar14 + 1;
          iVar15 = iVar15 + 1;
        } while ((int)ppuVar14 < 0x4d2514);
        if (iVar7 == -1) {
          uVar10 = 0xffffffff;
          pcVar8 = (char *)&DAT_004f5740;
          do {
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar1 != '\0');
          uVar10 = ~uVar10 - 1;
          cVar1 = FUN_0040b600(uVar10,1);
          if (cVar1 != '\0') {
            pcVar8 = (char *)&DAT_004f5740;
            pcVar16 = local_144;
            for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pcVar16 = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              pcVar16 = pcVar16 + 4;
            }
            for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
              *pcVar16 = *pcVar8;
              pcVar8 = pcVar8 + 1;
              pcVar16 = pcVar16 + 1;
            }
            FUN_0040b5e0(uVar10);
          }
        }
LAB_0046ae4e:
        FUN_0046b2a0(iVar13,local_148);
        local_4 = CONCAT31(local_4._1_3_,0x12);
        FUN_0040b4f0(1);
        local_4 = 0xffffffff;
        FUN_0040b4f0(1);
        iVar13 = iVar13 + 1;
      } while (iVar13 < local_154);
      if (0 < local_154) {
        local_14c = &PTR_s_First_004d2cf8;
        puVar12 = (undefined4 *)(param_1 + 0x1c);
        do {
          pcVar8 = *local_14c;
          FUN_0040b4f0(0);
          uVar10 = 0xffffffff;
          pcVar16 = pcVar8;
          do {
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            cVar1 = *pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (cVar1 != '\0');
          uVar10 = ~uVar10 - 1;
          cVar1 = FUN_0040b600(uVar10,1);
          if (cVar1 != '\0') {
            pcVar16 = local_144;
            for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pcVar16 = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              pcVar16 = pcVar16 + 4;
            }
            for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
              *pcVar16 = *pcVar8;
              pcVar8 = pcVar8 + 1;
              pcVar16 = pcVar16 + 1;
            }
            FUN_0040b5e0(uVar10);
          }
          local_4 = 0x20;
          uVar2 = FUN_00461470(local_148);
          *puVar12 = uVar2;
          local_4 = 0xffffffff;
          FUN_0040b4f0(1);
          FUN_0040b4f0(0);
          uVar10 = 0xffffffff;
          pcVar8 = s_D__work_rcsk_Code_game_Rco_Portr_004f5744;
          do {
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar1 != '\0');
          uVar10 = ~uVar10 - 1;
          cVar1 = FUN_0040b600(uVar10,1);
          if (cVar1 != '\0') {
            pcVar8 = s_D__work_rcsk_Code_game_Rco_Portr_004f5744;
            pcVar16 = local_134;
            for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pcVar16 = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              pcVar16 = pcVar16 + 4;
            }
            for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
              *pcVar16 = *pcVar8;
              pcVar8 = pcVar8 + 1;
              pcVar16 = pcVar16 + 1;
            }
            FUN_0040b5e0(uVar10);
          }
          pcVar8 = *local_14c;
          local_4 = 0x21;
          FUN_0040b4f0(0);
          uVar10 = 0xffffffff;
          pcVar16 = pcVar8;
          do {
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            cVar1 = *pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (cVar1 != '\0');
          uVar10 = ~uVar10 - 1;
          cVar1 = FUN_0040b600(uVar10,1);
          if (cVar1 != '\0') {
            pcVar16 = local_124;
            for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pcVar16 = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              pcVar16 = pcVar16 + 4;
            }
            for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
              *pcVar16 = *pcVar8;
              pcVar8 = pcVar8 + 1;
              pcVar16 = pcVar16 + 1;
            }
            FUN_0040b5e0(uVar10);
          }
          local_4._0_1_ = 0x22;
          uVar2 = FUN_00412710(local_bc,s_Invalid_element_004f5770,local_128);
          local_4._0_1_ = 0x23;
          FUN_00464530(*puVar12,uVar2,local_138,0x22c);
          local_4._0_1_ = 0x22;
          FUN_0040b4f0(1);
          local_4 = CONCAT31(local_4._1_3_,0x21);
          FUN_0040b4f0(1);
          local_4 = 0xffffffff;
          if (local_134 != (char *)0x0) {
            cVar1 = local_134[-1];
            if ((cVar1 == '\0') || (cVar1 == -1)) {
              FUN_004bc150(local_134 + -1);
            }
            else {
              local_134[-1] = cVar1 + -1;
            }
          }
          local_134 = (char *)0x0;
          local_130 = 0;
          local_12c = 0;
          FUN_00458460(1);
          local_14c = local_14c + 1;
          puVar12 = puVar12 + 1;
          local_154 = local_154 + -1;
        } while (local_154 != 0);
      }
    }
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00463d20(local_e8,5);
  local_4 = 0;
  uVar3 = FUN_00463d20(local_f8,local_154);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar10 = 0xffffffff;
  pcVar8 = &DAT_004f5658;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f5658,~uVar10 - 1);
  local_4._0_1_ = 2;
  uVar4 = FUN_00463d20(local_1c,0x204);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar10 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Rco_Portr_004f5660;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Portr_004f5660,~uVar10 - 1);
  local_4._0_1_ = 4;
  FUN_0040b4f0(0);
  uVar10 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f568c;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f568c,~uVar10 - 1);
  local_4._0_1_ = 5;
  uVar5 = FUN_00459040(local_2c,local_148,local_118);
  local_4._0_1_ = 6;
  uVar5 = FUN_0041b630(local_8c,uVar5,&DAT_004f565c);
  local_4._0_1_ = 7;
  uVar4 = FUN_00459040(local_4c,uVar5,uVar4);
  local_4._0_1_ = 8;
  uVar4 = FUN_00459040(local_6c,uVar4,local_108);
  local_4._0_1_ = 9;
  uVar4 = FUN_0041b630(local_ac,uVar4,s_Count_too_high_in_ini_file__004f5638);
  local_4._0_1_ = 10;
  uVar3 = FUN_00459040(local_9c,uVar4,uVar3);
  local_4._0_1_ = 0xb;
  uVar3 = FUN_0041b630(local_7c,uVar3,s_maximum_004f562c);
  local_4._0_1_ = 0xc;
  uVar2 = FUN_00459040(local_5c,uVar3,uVar2);
  local_4._0_1_ = 0xd;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f5628);
  local_4 = CONCAT31(local_4._1_3_,0xe);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_d8,&DAT_004d6580);
  while( true ) {
    uVar10 = uVar10 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar1 == '\0') break;
code_r0x0046b0ab:
    if (uVar10 == 0) break;
  }
  FUN_0040b540(&DAT_004f56ec,~uVar10 - 1);
  local_4._0_1_ = 0x14;
  uVar2 = FUN_00463d20(local_3c,0x20f);
  local_4._0_1_ = 0x15;
  FUN_0040b4f0(0);
  uVar10 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Rco_Portr_004f56f4;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Portr_004f56f4,~uVar10 - 1);
  local_4._0_1_ = 0x16;
  FUN_0040b4f0(0);
  uVar10 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f5720;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f5720,~uVar10 - 1);
  local_4._0_1_ = 0x17;
  uVar3 = FUN_00459040(local_5c,local_128,local_108);
  local_4._0_1_ = 0x18;
  uVar3 = FUN_0041b630(local_7c,uVar3,&DAT_004f56f0);
  local_4._0_1_ = 0x19;
  uVar2 = FUN_00459040(local_9c,uVar3,uVar2);
  local_4._0_1_ = 0x1a;
  uVar2 = FUN_00459040(local_ac,uVar2,local_138);
  local_4._0_1_ = 0x1b;
  uVar2 = FUN_0041b630(local_6c,uVar2,s_Not_enough_arguments_in_ini_file_004f56c0);
  local_4._0_1_ = 0x1c;
  uVar2 = FUN_00459040(local_4c,uVar2,local_f8);
  local_4._0_1_ = 0x1d;
  uVar2 = FUN_0041b630(local_8c,uVar2,&DAT_004f56bc);
  local_4 = CONCAT31(local_4._1_3_,0x1e);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_d8,&DAT_004d6580);
}

