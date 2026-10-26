/*
 * FUN_00459440 at 00459440
 * undefined FUN_00459440(void)
 * Address ranges: 00459440-00459900
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00459440(int param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  float *pfVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  int iVar19;
  undefined1 auStack_118 [16];
  undefined1 auStack_108 [16];
  undefined1 auStack_f8 [16];
  undefined1 auStack_e8 [28];
  undefined1 auStack_cc [16];
  undefined1 auStack_bc [16];
  undefined1 auStack_ac [16];
  undefined1 auStack_9c [16];
  undefined1 auStack_8c [16];
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [16];
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004ce062;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar7 = FUN_004583b0();
  if ((cVar7 != '\0') && (*(int *)(param_1 + 0x50) != -1)) {
    pfVar8 = (float *)FUN_004583d0();
    fVar5 = pfVar8[1];
    fVar6 = pfVar8[2];
    fVar2 = param_2[2];
    fVar3 = param_2[5];
    iVar9 = DAT_006a5c38 + *(int *)(param_1 + 0x50) * 0xa9;
    fVar4 = param_2[1];
    *(float *)(iVar9 + 0x50) = *pfVar8 * param_2[4] + *param_2;
    *(float *)(iVar9 + 0x54) = fVar5 * fVar3 + fVar4;
    *(float *)(iVar9 + 0x58) = fVar6 + fVar2 + 1.0;
    pfVar8 = (float *)FUN_004583e0();
    puVar10 = (undefined4 *)
              FUN_00405f20(*pfVar8 * param_2[6],param_2[7] * pfVar8[1],param_2[8] * pfVar8[2]);
    iVar9 = DAT_006a5c38 + *(int *)(param_1 + 0x50) * 0xa9;
    *(undefined4 *)(iVar9 + 0x80) = *puVar10;
    *(undefined4 *)(iVar9 + 0x84) = puVar10[1];
    *(undefined4 *)(iVar9 + 0x88) = puVar10[2];
    pfVar8 = (float *)FUN_004583f0();
    puVar10 = (undefined4 *)
              FUN_00405f20(*pfVar8 + param_2[9],pfVar8[1] + param_2[10],pfVar8[2] + param_2[0xb]);
    uVar11 = puVar10[1];
    uVar12 = puVar10[2];
    iVar9 = DAT_006a5c38 + *(int *)(param_1 + 0x50) * 0xa9;
    *(undefined4 *)(iVar9 + 0x74) = *puVar10;
    *(undefined4 *)(iVar9 + 0x78) = uVar11;
    *(undefined4 *)(iVar9 + 0x7c) = uVar12;
    iVar17 = *(int *)(param_1 + 0x50);
    iVar9 = DAT_006a5c38 + iVar17 + iVar17 * 0xa8;
    iVar17 = *(int *)(DAT_006a5c38 + iVar17 + iVar17 * 0xa8);
    if (iVar17 == 1) {
      piVar1 = (int *)(DAT_006a5ee0 + *(int *)(iVar9 + 0x99) * 0xbc);
      puVar10 = (undefined4 *)FUN_00458590();
      uVar11 = *puVar10;
      if ((*piVar1 == 2) && (iVar9 = 0, 0 < piVar1[0x21])) {
        iVar17 = 0;
        do {
          iVar9 = iVar9 + 1;
          *(undefined4 *)(iVar17 + 0x10 + piVar1[0x20]) = uVar11;
          iVar17 = iVar17 + 0x20;
        } while (iVar9 < piVar1[0x21]);
      }
    }
    else {
      if (iVar17 != 2) {
        uVar11 = FUN_00463d20(auStack_ac,iVar17);
        uStack_4 = 0;
        FUN_0040b4f0(0);
        uVar14 = 0xffffffff;
        pcVar18 = &DAT_004f2900;
        do {
          if (uVar14 == 0) break;
          uVar14 = uVar14 - 1;
          cVar7 = *pcVar18;
          pcVar18 = pcVar18 + 1;
        } while (cVar7 != '\0');
        FUN_0040b540(&DAT_004f2900,~uVar14 - 1);
        uStack_4._0_1_ = 1;
        uVar12 = FUN_00463d20(auStack_1c,0x52);
        uStack_4._0_1_ = 2;
        FUN_0040b4f0(0);
        uVar14 = 0xffffffff;
        pcVar18 = s_D__work_rcsk_Code_game_Hud_Eleme_004f2908;
        do {
          if (uVar14 == 0) break;
          uVar14 = uVar14 - 1;
          cVar7 = *pcVar18;
          pcVar18 = pcVar18 + 1;
        } while (cVar7 != '\0');
        FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Eleme_004f2908,~uVar14 - 1);
        uStack_4._0_1_ = 3;
        FUN_0040b4f0(0);
        uVar14 = 0xffffffff;
        pcVar18 = s_HeadUp_Display_exception_in__004f2930;
        do {
          if (uVar14 == 0) break;
          uVar14 = uVar14 - 1;
          cVar7 = *pcVar18;
          pcVar18 = pcVar18 + 1;
        } while (cVar7 != '\0');
        FUN_0040b540(s_HeadUp_Display_exception_in__004f2930,~uVar14 - 1);
        uStack_4._0_1_ = 4;
        uVar13 = FUN_00459040(auStack_cc,auStack_f8,auStack_118);
        uStack_4._0_1_ = 5;
        uVar13 = FUN_0041b630(auStack_2c,uVar13,&DAT_004f2904);
        uStack_4._0_1_ = 6;
        uVar12 = FUN_00459040(auStack_8c,uVar13,uVar12);
        uStack_4._0_1_ = 7;
        uVar12 = FUN_00459040(auStack_4c,uVar12,auStack_108);
        uStack_4._0_1_ = 8;
        uVar12 = FUN_0041b630(auStack_6c,uVar12,s_Unreachable_code_reached__004f28e4);
        uStack_4._0_1_ = 9;
        uVar13 = FUN_004583c0();
        uVar12 = FUN_00459040(auStack_bc,uVar12,uVar13);
        uStack_4._0_1_ = 10;
        uVar12 = FUN_0041b630(auStack_9c,uVar12,s___Unknown_object_type___004f28cc);
        uStack_4._0_1_ = 0xb;
        uVar11 = FUN_00459040(auStack_7c,uVar12,uVar11);
        uStack_4._0_1_ = 0xc;
        uVar11 = FUN_0041b630(auStack_5c,uVar11,&DAT_004f28c8);
        uStack_4._0_1_ = 0xd;
        uVar11 = FUN_0041b630(auStack_3c,uVar11,&DAT_004f28c4);
        uStack_4 = CONCAT31(uStack_4._1_3_,0xe);
        FUN_00459dc0(uVar11);
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(auStack_e8,&DAT_004d6580);
      }
      iVar19 = 0;
      iVar17 = *(int *)(iVar9 + 4) * 9;
      iVar9 = *(int *)(DAT_006a5f78 + iVar17);
      if (0 < iVar9) {
        do {
          piVar1 = (int *)(DAT_006a5ee0 +
                          *(int *)(*(int *)(*(int *)(DAT_006a5f78 + 4 + iVar17) + iVar19 * 4) * 0x10
                                  + DAT_006a5f30) * 0xbc);
          puVar10 = (undefined4 *)FUN_00458590();
          uVar11 = *puVar10;
          if ((*piVar1 == 2) && (iVar15 = 0, 0 < piVar1[0x21])) {
            iVar16 = 0;
            do {
              iVar15 = iVar15 + 1;
              *(undefined4 *)(iVar16 + 0x10 + piVar1[0x20]) = uVar11;
              iVar16 = iVar16 + 0x20;
            } while (iVar15 < piVar1[0x21]);
          }
          iVar19 = iVar19 + 1;
        } while (iVar19 < iVar9);
      }
    }
    FUN_004a09d0();
    FUN_004a0d80();
  }
  ExceptionList = pvStack_c;
  return;
}

