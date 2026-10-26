/*
 * FUN_0042bbf0 at 0042bbf0
 * undefined FUN_0042bbf0(void)
 * Address ranges: 0042bbf0-0042c09c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bbf0(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined1 local_cc [4];
  char local_c8 [200];
  
  FUN_004afce0(s_load_track_info_004e9960);
  FUN_004b1d60(s_track_INI_004e9974);
  iVar9 = 0;
  if (0 < DAT_0053a6a0) {
    pcVar8 = (char *)&DAT_0053a6a8;
    do {
      FUN_004bea92(local_cc,&DAT_004e9980,iVar9);
      FUN_004b1f10(&DAT_004e9984,local_cc,local_c8,199);
      iVar5 = -1;
      pcVar4 = local_c8;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if (iVar5 == -2) {
        FUN_004afee0(s__load_track_info___s__d____No_va_004e99b0,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e998c,0x39b,iVar9);
      }
      iVar5 = FUN_004b1f60(local_c8,0);
      if (iVar5 != 0xf) {
        FUN_004afee0(s__load_track_info___s__d____Inval_004e9a14,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e99f0,0x3a5,iVar9);
      }
      uVar3 = FUN_004b20c0(0);
      *(undefined4 *)(pcVar8 + -4) = uVar3;
      FUN_004b2110(1,local_c8,0xd);
      pcVar4 = (char *)FUN_004bfcb1(local_c8);
      uVar6 = 0xffffffff;
      do {
        pcVar10 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar4 = pcVar10 + -uVar6;
      pcVar10 = pcVar8;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar10 = pcVar10 + 1;
      }
      FUN_004b2110(2,local_c8,0xd);
      uVar3 = FUN_004bfcb1(local_c8);
      FUN_004bea92(pcVar8 + 0xe,s__s_pcx_004e9a58,uVar3);
      FUN_004b2110(3,local_c8,0xd);
      uVar3 = FUN_004bfcb1(local_c8);
      FUN_004bea92(pcVar8 + 0x1c,s__s_pcx_004e9a60,uVar3);
      FUN_004b2110(4,local_c8,0xd);
      uVar3 = FUN_004bfcb1(local_c8);
      FUN_004bea92(pcVar8 + 0x2a,s__s_pcx_004e9a68,uVar3);
      FUN_004b2110(5,local_c8,0xd);
      uVar3 = FUN_004bfcb1(local_c8);
      FUN_004bea92(pcVar8 + 0x38,s__s_pcx_004e9a70,uVar3);
      FUN_004b2110(6,local_c8,0xd);
      uVar3 = FUN_004bfcb1(local_c8);
      FUN_004bea92(pcVar8 + 0x46,s__s_pcx_004e9a78,uVar3);
      FUN_004b2110(7,local_c8,0xd);
      uVar3 = FUN_004bfcb1(local_c8);
      FUN_004bea92(pcVar8 + 0x54,s__s_pcx_004e9a80,uVar3);
      FUN_004b2110(8,local_c8,0x1e);
      pcVar4 = (char *)FUN_004bfcb1(local_c8);
      uVar6 = 0xffffffff;
      do {
        pcVar10 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar4 = pcVar10 + -uVar6;
      pcVar10 = pcVar8 + 0x62;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar10 = pcVar10 + 1;
      }
      FUN_004b2110(0xb,local_c8,3);
      uVar2 = FUN_004bf812(local_c8);
      *(undefined2 *)(pcVar8 + 0x82) = uVar2;
      FUN_004b2110(0xc,local_c8,3);
      uVar2 = FUN_004bf812(local_c8);
      *(undefined2 *)(pcVar8 + 0x84) = uVar2;
      FUN_004b2110(0xd,local_c8,3);
      uVar2 = FUN_004bf812(local_c8);
      *(undefined2 *)(pcVar8 + 0x86) = uVar2;
      FUN_004b2110(0xe,local_c8,3);
      uVar3 = FUN_004bf812(local_c8);
      *(undefined4 *)(pcVar8 + 0x8c) = uVar3;
      cVar1 = FUN_004b20c0(9);
      pcVar8[0x80] = cVar1;
      uVar3 = FUN_004b20c0(10);
      *(undefined4 *)(pcVar8 + 0x88) = uVar3;
      iVar9 = iVar9 + 1;
      pcVar8 = pcVar8 + 0x94;
    } while (iVar9 < DAT_0053a6a0);
  }
  FUN_004b1d60(s_track_INI_004e9a88);
  FUN_0042ac20();
  uVar6 = FUN_004b1ed0(s_ZIPPER_BOOST_004e9aa0,s_HighForward_004e9a94);
  DAT_0053d2a8 = (float)uVar6;
  uVar6 = FUN_004b1ed0(s_ZIPPER_BOOST_004e9ab8,s_HighUp_004e9ab0);
  DAT_0053d2ac = (float)uVar6;
  uVar6 = FUN_004b1ed0(s_ZIPPER_BOOST_004e9ad8,s_MediumForward_004e9ac8);
  DAT_0053d2a0 = (float)uVar6;
  uVar6 = FUN_004b1ed0(s_ZIPPER_BOOST_004e9af4,s_MediumUp_004e9ae8);
  DAT_0053d2a4 = (float)uVar6;
  uVar6 = FUN_004b1ed0(s_ZIPPER_BOOST_004e9b10,s_LowForward_004e9b04);
  DAT_0053d298 = (float)uVar6;
  uVar6 = FUN_004b1ed0(s_ZIPPER_BOOST_004e9b28,s_LowUp_004e9b20);
  DAT_0053d29c = (float)uVar6;
  iVar9 = FUN_0042abc0();
  if (iVar9 == 1) {
    FUN_004b1d60(s_track_INI_004e9b38);
    iVar9 = DAT_0053b9f4 + DAT_0053b9b4 * 3;
    FUN_004bea92(local_cc,&DAT_004e9b44,iVar9);
    FUN_004b1f10(s_TIME_GATES_004e9b48,local_cc,local_c8,199);
    iVar5 = -1;
    pcVar8 = local_c8;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    if (iVar5 == -2) {
      FUN_004afee0(s__load_track_info___s__d____No_va_004e9b78,
                   s_D__work_rcsk_Code_game_Gm_ini_cp_004e9b54,0x3fe,iVar9);
    }
    iVar5 = FUN_004b1f60(local_c8,0);
    if (0xb < iVar5) {
      FUN_004afee0(s__load_track_info___s__d____Inval_004e9be0,
                   s_D__work_rcsk_Code_game_Gm_ini_cp_004e9bbc,0x408,iVar9);
    }
    DAT_0053d338 = FUN_004b20c0(0);
    if ((0 < DAT_0053d338) && (iVar9 = 0, DAT_0053d338 != -1 && -1 < DAT_0053d338 + 1)) {
      puVar11 = &DAT_0053d2b0;
      do {
        iVar9 = iVar9 + 1;
        uVar3 = FUN_004b20c0(iVar9);
        iVar5 = DAT_0053d338;
        *puVar11 = uVar3;
        puVar11 = puVar11 + 1;
      } while (iVar9 < iVar5 + 1);
    }
  }
  return;
}

