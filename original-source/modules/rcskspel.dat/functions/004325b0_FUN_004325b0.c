/*
 * FUN_004325b0 at 004325b0
 * undefined FUN_004325b0(void)
 * Address ranges: 004325b0-0043384e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004325b0(float param_1)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  DWORD DVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  bool bVar14;
  float10 fVar15;
  undefined8 uVar16;
  char *pcStack_3c;
  undefined4 uStack_34;
  char *pcStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  char *pcStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  char *pcStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cd242;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0048c030();
  iVar11 = (int)param_1 * 0xd0;
  FUN_004afce0(s___d__prev___d_curr___d_004eb404,param_1,
               *(undefined4 *)(DAT_0067ee20 + 0x20 + iVar11),
               *(undefined4 *)(DAT_0067ee20 + 0x1c + iVar11));
  if (*(int *)(DAT_0067ee20 + 0x1c + iVar11) != *(int *)(DAT_0067ee20 + 0x20 + iVar11)) {
    FUN_004afce0(s_old_dist___d_004eb41c,DAT_0053be70);
    iVar4 = FUN_00404eb0(*(undefined4 *)(DAT_0067ee20 + 0x1c + iVar11),
                         *(undefined4 *)(DAT_0067ee20 + 0x20 + iVar11));
    uVar7 = *(undefined4 *)(DAT_0067ee20 + 0x20 + iVar11);
    uVar6 = *(undefined4 *)(DAT_0067ee20 + 0x1c + iVar11);
    if (iVar4 == 1) {
      iVar4 = FUN_00493a40(uVar6,uVar7);
      DAT_0053be70 = DAT_0053be70 + iVar4;
    }
    else {
      iVar4 = FUN_00493a40(uVar6,uVar7);
      DAT_0053be70 = DAT_0053be70 - iVar4;
    }
    FUN_004afce0(s_new_dist___d_004eb42c,DAT_0053be70);
  }
  DAT_0053be34 = __ftol();
  iVar4 = __ftol();
  if (iVar4 < -DAT_00508614) {
    uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
    FUN_0040b4f0();
    uVar9 = 0xffffffff;
    pcVar12 = s_IDLE_STEER_RIGHT_004eb43c;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar3 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    FUN_0040b540(s_IDLE_STEER_RIGHT_004eb43c,~uVar9 - 1);
    uStack_4 = 0;
    piVar5 = (int *)FUN_0044a700();
    (**(code **)(*piVar5 + 0xc))(&uStack_1c,0,4);
    uStack_10 = 0xffffffff;
    FUN_0040b4f0(1);
    uStack_28 = CONCAT31(uStack_28._1_3_,puStack_8._0_1_);
    FUN_0040b4f0(0);
    uVar9 = 0xffffffff;
    pcVar12 = s_STEER_RIGHT_004eb450;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar3 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar3 = FUN_0040b600(uVar9,1);
    if (cVar3 != '\0') {
      pcVar12 = s_STEER_RIGHT_004eb450;
      pcVar13 = pcStack_24;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FUN_0040b5e0(uVar9);
    }
    uStack_10 = 1;
    piVar5 = (int *)FUN_0044a700(DAT_00508610);
    (**(code **)(*piVar5 + 0xc))(&uStack_28,4,4);
    uStack_1c = 0xffffffff;
    FUN_0040b4f0(1);
    uStack_34 = CONCAT31(uStack_34._1_3_,(undefined1)uStack_14);
    FUN_0040b4f0(0);
    uVar9 = 0xffffffff;
    pcVar12 = s_STEER_RIGHT_IDLE_004eb45c;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar3 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar3 = FUN_0040b600(uVar9,1);
    if (cVar3 != '\0') {
      pcVar12 = s_STEER_RIGHT_IDLE_004eb45c;
      pcVar13 = pcStack_30;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FUN_0040b5e0(uVar9);
    }
    uStack_1c = 2;
    piVar5 = (int *)FUN_0044a700(DAT_00508610);
    (**(code **)(*piVar5 + 0xc))(&uStack_34,4,0);
  }
  else {
    if (iVar4 <= DAT_00508614) goto LAB_00432a3d;
    uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
    FUN_0040b4f0();
    uVar9 = 0xffffffff;
    pcVar12 = s_IDLE_STEER_LEFT_004eb470;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar3 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar3 = FUN_0040b600(uVar9,1);
    if (cVar3 != '\0') {
      pcVar12 = s_IDLE_STEER_LEFT_004eb470;
      pcVar13 = pcStack_18;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FUN_0040b5e0();
    }
    uStack_4 = 3;
    piVar5 = (int *)FUN_0044a700();
    (**(code **)(*piVar5 + 0xc))(&uStack_1c,0,3);
    uStack_10 = 0xffffffff;
    FUN_0040b4f0(1);
    uStack_28 = CONCAT31(uStack_28._1_3_,puStack_8._0_1_);
    FUN_0040b4f0(0);
    uVar9 = 0xffffffff;
    pcVar12 = s_STEER_LEFT_004eb480;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar3 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar3 = FUN_0040b600(uVar9,1);
    if (cVar3 != '\0') {
      pcVar12 = s_STEER_LEFT_004eb480;
      pcVar13 = pcStack_24;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FUN_0040b5e0(uVar9);
    }
    uStack_10 = 4;
    piVar5 = (int *)FUN_0044a700(DAT_00508610);
    (**(code **)(*piVar5 + 0xc))(&uStack_28,3,3);
    uStack_1c = 0xffffffff;
    FUN_0040b4f0(1);
    uStack_34 = CONCAT31(uStack_34._1_3_,(undefined1)uStack_14);
    FUN_0040b4f0(0);
    uVar9 = 0xffffffff;
    pcVar12 = s_STEER_LEFT_IDLE_004eb48c;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar3 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    uVar9 = ~uVar9 - 1;
    cVar3 = FUN_0040b600(uVar9,1);
    if (cVar3 != '\0') {
      pcVar12 = s_STEER_LEFT_IDLE_004eb48c;
      pcVar13 = pcStack_30;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FUN_0040b5e0(uVar9);
    }
    uStack_1c = 5;
    piVar5 = (int *)FUN_0044a700(DAT_00508610);
    (**(code **)(*piVar5 + 0xc))(&uStack_34,3,0);
  }
  uStack_4 = 0xffffffff;
  FUN_0040b4f0();
LAB_00432a3d:
  DAT_0053be40 = *(undefined4 *)(DAT_0067ee20 + 0x1c + iVar11);
  iVar1 = *(int *)(DAT_0067ee20 + iVar11 + 0xc);
  iVar4 = DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8;
  _DAT_0053be44 = *(undefined4 *)(DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8);
  DAT_0053be48 = *(undefined4 *)(iVar4 + 4);
  DAT_0053be4c = *(undefined4 *)(iVar4 + 8);
  FUN_004902a0();
  FUN_004343b0();
  FUN_004320d0();
  FUN_00435320();
  uVar7 = DAT_0053be34;
  uVar6 = __ftol();
  uVar16 = CONCAT44(uVar7,uVar6);
  uVar7 = FUN_00414e60(uVar6);
  FUN_00418c80(uVar7,uVar16);
  FUN_00406be0();
  FUN_004938e0();
  FUN_0041b790(DAT_0053be28);
  if (DAT_0053be64 == 0) {
    if (DAT_0053be54 == 0) {
      _DAT_00507290 = 0;
      DAT_0050728c = 0;
      *(undefined4 *)(DAT_0053be28 * 0xd0 + 0x9c + DAT_0067ee20) = 0;
      *(undefined4 *)(DAT_0053be28 * 0xd0 + 0xa0 + DAT_0067ee20) = 0;
      *(undefined4 *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20) = 0;
      uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
      *(undefined4 *)(DAT_0053be28 * 0xd0 + 0xac + DAT_0067ee20) = 0;
      FUN_0040b4f0();
      uVar9 = 0xffffffff;
      pcVar12 = s_CHEER_004eb49c;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar3 = *pcVar12;
        pcVar12 = pcVar12 + 1;
      } while (cVar3 != '\0');
      uVar9 = ~uVar9 - 1;
      cVar3 = FUN_0040b600(uVar9,1);
      if (cVar3 != '\0') {
        pcVar12 = s_CHEER_004eb49c;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcStack_18 = *(undefined4 *)pcVar12;
          pcVar12 = pcVar12 + 4;
          pcStack_18 = pcStack_18 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcStack_18 = *pcVar12;
          pcVar12 = pcVar12 + 1;
          pcStack_18 = pcStack_18 + 1;
        }
        FUN_0040b5e0();
      }
      uStack_4 = 6;
      piVar5 = (int *)FUN_0044a700();
      (**(code **)(*piVar5 + 0xc))(&uStack_1c,0,0);
      uStack_4 = 0xffffffff;
      FUN_0040b4f0();
      FUN_0044a6c0();
    }
    else if (DAT_0053b9e0 != 0) {
      uStack_34 = 0;
      iVar11 = DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + DAT_0067ee20 + 0xc) * 0xa9;
      FUN_00495fe0(*(undefined4 *)(iVar11 + 0x50),*(undefined4 *)(iVar11 + 0x54),
                   *(undefined4 *)(iVar11 + 0x58),&uStack_34,&uStack_2c,&pcStack_30);
      iVar11 = DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
      FUN_00496290(*(undefined4 *)(iVar11 + 0x50),*(undefined4 *)(iVar11 + 0x54),
                   *(undefined4 *)(iVar11 + 0x58),uStack_2c,pcStack_30);
      switch(DAT_0053a5d8) {
      case 1:
        FUN_00433870();
        break;
      case 2:
        FUN_00433cf0();
        break;
      case 3:
        FUN_004341d0();
        break;
      case 4:
        break;
      default:
        FUN_004afee0(s__handle_player_car___s__d____Inv_004eb4c8,
                     s_D__work_rcsk_Code_game_plr_car_c_004eb4a4,0x2e6);
      }
      __ftol();
      FUN_004273f0();
      switch(DAT_0053a5d8) {
      case 1:
      case 2:
        _DAT_0053bd84 = 3.0;
        _DAT_00505b58 = 5.0;
        _DAT_00505b5c = 25.0;
        break;
      case 3:
      case 4:
        _DAT_0053bd84 = 3.0;
        _DAT_00505b58 = 3.0;
        _DAT_00505b5c = 20.0;
      }
      if (DAT_0053ba34 == 0) {
        fVar2 = (float)DAT_0053be04;
        FUN_00414160(param_1,_DAT_0053bd70,DAT_0053bd74,fVar2);
        param_1 = fVar2;
      }
      else {
        uVar9 = __ftol();
        param_1 = -((_DAT_0053bd84 / _DAT_0053be68) *
                   (float)(int)((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f)));
        fVar15 = (float10)FUN_004bfa20();
        FUN_004b1850(0,10,0x1ae,s__3_3f_004eb4fc,
                     (double)(((float10)_DAT_0053bd70 - (float10)30.0) *
                              (((float10)_DAT_00505b5c - (float10)_DAT_00505b58) * fVar15 +
                              (float10)_DAT_00505b58) * (float10)0.0005817764173148148));
      }
      FUN_0041c0b0();
      FUN_00435a30();
      FUN_00435c30();
      FUN_00435a30();
      FUN_00435d50();
      if ((DAT_0053b9c0 == 3) && (DAT_0053be60 == 0)) {
        uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
        FUN_0040b4f0();
        uVar9 = 0xffffffff;
        pcVar12 = s_CHEER_004eb504;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar3 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9 - 1;
        cVar3 = FUN_0040b600(uVar9,1);
        if (cVar3 != '\0') {
          pcVar12 = s_CHEER_004eb504;
          pcVar13 = pcStack_18;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
          FUN_0040b5e0();
        }
        uStack_4 = 7;
        piVar5 = (int *)FUN_0044a700();
        (**(code **)(*piVar5 + 0xc))(&uStack_1c,0,0);
        uStack_4 = 0xffffffff;
        FUN_0040b4f0();
      }
      if (0.0 <= *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)) {
        if ((DAT_0053be04 < 1) && (DAT_0053bdf4 != 1)) {
          DVar8 = GetTickCount();
          if (DVar8 - (&DAT_0053a22c)[DAT_00508610] < 5000) {
            uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
            FUN_0040b4f0();
            uVar9 = 0xffffffff;
            pcVar12 = (char *)&DAT_004eb540;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              cVar3 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar3 != '\0');
            uVar9 = ~uVar9 - 1;
            cVar3 = FUN_0040b600(uVar9,1);
            if (cVar3 != '\0') {
              pcVar12 = (char *)&DAT_004eb540;
              pcVar13 = pcStack_18;
              for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
                pcVar12 = pcVar12 + 4;
                pcVar13 = pcVar13 + 4;
              }
              for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *pcVar13 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                pcVar13 = pcVar13 + 1;
              }
              pcStack_18[uVar9] = '\0';
              uStack_14 = uVar9;
            }
            uStack_4 = 0xd;
            piVar5 = (int *)FUN_0044a700();
            (**(code **)(*piVar5 + 0xc))(&uStack_1c,6,6);
            uStack_10 = 0xffffffff;
            FUN_0040b4f0(1);
            uStack_28 = CONCAT31(uStack_28._1_3_,puStack_8._0_1_);
            FUN_0040b4f0(0);
            uVar9 = 0xffffffff;
            pcVar12 = s_IDLE_TURBO_004eb548;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              cVar3 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar3 != '\0');
            uVar9 = ~uVar9 - 1;
            cVar3 = FUN_0040b600(uVar9,1);
            if (cVar3 != '\0') {
              pcVar12 = s_IDLE_TURBO_004eb548;
              pcVar13 = pcStack_24;
              for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
                pcVar12 = pcVar12 + 4;
                pcVar13 = pcVar13 + 4;
              }
              for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *pcVar13 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                pcVar13 = pcVar13 + 1;
              }
              pcStack_24[uVar9] = '\0';
              uStack_20 = uVar9;
            }
            uStack_10 = 0xe;
            piVar5 = (int *)FUN_0044a700(DAT_00508610);
            (**(code **)(*piVar5 + 0xc))(&uStack_28,0,6);
          }
          else {
            uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
            FUN_0040b4f0();
            uVar9 = 0xffffffff;
            pcVar12 = s_TURBO_IDLE_004eb554;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              cVar3 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar3 != '\0');
            uVar9 = ~uVar9 - 1;
            cVar3 = FUN_0040b600(uVar9,1);
            if (cVar3 != '\0') {
              pcVar12 = s_TURBO_IDLE_004eb554;
              pcVar13 = pcStack_18;
              for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
                pcVar12 = pcVar12 + 4;
                pcVar13 = pcVar13 + 4;
              }
              for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *pcVar13 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                pcVar13 = pcVar13 + 1;
              }
              pcStack_18[uVar9] = '\0';
              uStack_14 = uVar9;
            }
            uStack_4 = 0xf;
            piVar5 = (int *)FUN_0044a700();
            (**(code **)(*piVar5 + 0xc))(&uStack_1c,6,0);
          }
          uStack_1c = 0xffffffff;
          FUN_0040b4f0(1);
          uStack_34 = CONCAT31(uStack_34._1_3_,(undefined1)uStack_14);
          FUN_0040b4f0(0);
          uVar9 = 0xffffffff;
          pcVar12 = s_BRAKE_IDLE_004eb560;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar3 = *pcVar12;
            pcVar12 = pcVar12 + 1;
          } while (cVar3 != '\0');
          uVar9 = ~uVar9 - 1;
          cVar3 = FUN_0040b600(uVar9,1);
          if (cVar3 != '\0') {
            pcVar12 = s_BRAKE_IDLE_004eb560;
            pcVar13 = pcStack_30;
            for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
              pcVar12 = pcVar12 + 4;
              pcVar13 = pcVar13 + 4;
            }
            for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *pcVar13 = *pcVar12;
              pcVar12 = pcVar12 + 1;
              pcVar13 = pcVar13 + 1;
            }
            pcStack_30[uVar9] = '\0';
            uStack_2c = uVar9;
          }
          uStack_1c = 0x10;
          piVar5 = (int *)FUN_0044a700(DAT_00508610);
          (**(code **)(*piVar5 + 0xc))(&uStack_34,5,0);
        }
        else {
          uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
          FUN_0040b4f0();
          uVar9 = 0xffffffff;
          pcVar12 = s_BRAKE_004eb52c;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar3 = *pcVar12;
            pcVar12 = pcVar12 + 1;
          } while (cVar3 != '\0');
          uVar9 = ~uVar9 - 1;
          cVar3 = FUN_0040b600(uVar9,1);
          if (cVar3 != '\0') {
            pcVar12 = s_BRAKE_004eb52c;
            pcVar13 = pcStack_18;
            for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
              pcVar12 = pcVar12 + 4;
              pcVar13 = pcVar13 + 4;
            }
            for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *pcVar13 = *pcVar12;
              pcVar12 = pcVar12 + 1;
              pcVar13 = pcVar13 + 1;
            }
            pcStack_18[uVar9] = '\0';
            uStack_14 = uVar9;
          }
          uStack_4 = 0xb;
          piVar5 = (int *)FUN_0044a700();
          (**(code **)(*piVar5 + 0xc))(&uStack_1c,5,5);
          uStack_10 = 0xffffffff;
          FUN_0040b4f0(1);
          uStack_28 = CONCAT31(uStack_28._1_3_,puStack_8._0_1_);
          FUN_0040b4f0(0);
          uVar9 = 0xffffffff;
          pcVar12 = s_IDLE_BRAKE_004eb534;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar3 = *pcVar12;
            pcVar12 = pcVar12 + 1;
          } while (cVar3 != '\0');
          uVar9 = ~uVar9 - 1;
          cVar3 = FUN_0040b600(uVar9,1);
          if (cVar3 != '\0') {
            pcVar12 = s_IDLE_BRAKE_004eb534;
            pcVar13 = pcStack_24;
            for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
              pcVar12 = pcVar12 + 4;
              pcVar13 = pcVar13 + 4;
            }
            for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *pcVar13 = *pcVar12;
              pcVar12 = pcVar12 + 1;
              pcVar13 = pcVar13 + 1;
            }
            pcStack_24[uVar9] = '\0';
            uStack_20 = uVar9;
          }
          uStack_10 = 0xc;
          piVar5 = (int *)FUN_0044a700(DAT_00508610);
          (**(code **)(*piVar5 + 0xc))(&uStack_28,0,5);
        }
        uStack_28 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_0040b4f0(0);
        uVar9 = 0xffffffff;
        pcVar12 = s_BACK_IDLE_004eb56c;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar3 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9 - 1;
        cVar3 = FUN_0040b600(uVar9,1);
        if (cVar3 != '\0') {
          pcVar12 = s_BACK_IDLE_004eb56c;
          pcVar13 = pcStack_3c;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
          pcStack_3c[uVar9] = '\0';
        }
        uStack_28 = 0x11;
        piVar5 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar5 + 0xc))(&stack0xffffffc0,1,0);
        uStack_34 = 0xffffffff;
        FUN_0040b4f0(1);
        uVar9 = 0xffffffff;
        pcVar12 = &DAT_004eb578;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar3 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar3 != '\0');
        FUN_0040b540(&DAT_004eb578,~uVar9 - 1);
        uStack_34 = 0x12;
        piVar5 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar5 + 0xc))(&stack0xffffffb4,0,0);
        uStack_4 = 0xffffffff;
        if (pcStack_18 != (char *)0x0) {
          cVar3 = pcStack_18[-1];
          if ((cVar3 == '\0') || (cVar3 == -1)) {
            FUN_004bc150();
          }
          else {
            pcStack_18[-1] = cVar3 + -1;
          }
        }
      }
      else {
        uStack_1c = CONCAT31(uStack_1c._1_3_,param_1._0_1_);
        FUN_0040b4f0();
        uVar9 = 0xffffffff;
        pcVar12 = s_IDLE_BACK_004eb50c;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar3 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9 - 1;
        cVar3 = FUN_0040b600(uVar9,1);
        if (cVar3 != '\0') {
          pcVar12 = s_IDLE_BACK_004eb50c;
          pcVar13 = pcStack_18;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
          pcStack_18[uVar9] = '\0';
          uStack_14 = uVar9;
        }
        uStack_4 = 8;
        piVar5 = (int *)FUN_0044a700();
        (**(code **)(*piVar5 + 0xc))(&uStack_1c,0,1);
        uStack_10 = 0xffffffff;
        FUN_0040b4f0(1);
        uStack_28 = CONCAT31(uStack_28._1_3_,puStack_8._0_1_);
        FUN_0040b4f0(0);
        uVar9 = 0xffffffff;
        pcVar12 = (char *)&DAT_004eb518;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar3 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9 - 1;
        cVar3 = FUN_0040b600(uVar9,1);
        if (cVar3 != '\0') {
          pcVar12 = (char *)&DAT_004eb518;
          pcVar13 = pcStack_24;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
          pcStack_24[uVar9] = '\0';
          uStack_20 = uVar9;
        }
        uStack_10 = 9;
        piVar5 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar5 + 0xc))(&uStack_28,1,1);
        uStack_1c = 0xffffffff;
        FUN_0040b4f0(1);
        uStack_34 = CONCAT31(uStack_34._1_3_,(undefined1)uStack_14);
        FUN_0040b4f0(0);
        uVar9 = 0xffffffff;
        pcVar12 = s_BRAKE_IDLE_004eb520;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar3 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9 - 1;
        cVar3 = FUN_0040b600(uVar9,1);
        if (cVar3 != '\0') {
          pcVar12 = s_BRAKE_IDLE_004eb520;
          pcVar13 = pcStack_30;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + 4;
            pcVar13 = pcVar13 + 4;
          }
          for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pcVar13 = *pcVar12;
            pcVar12 = pcVar12 + 1;
            pcVar13 = pcVar13 + 1;
          }
          pcStack_30[uVar9] = '\0';
          uStack_2c = uVar9;
        }
        uStack_1c = 10;
        piVar5 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar5 + 0xc))(&uStack_34,5,0);
        uStack_4 = 0xffffffff;
        FUN_0040b4f0();
      }
      FUN_0044a6c0();
      bVar14 = *(int *)(*(int *)(DAT_0053be28 * 0xd0 + 0x24 + DAT_0067ee20) * 0x50 + 4 +
                       DAT_00680ae0) == 1;
      if (((DAT_0053bec4 != '\0') || (bVar14 == true)) || (bVar14)) {
        uStack_28 = 0;
        iVar11 = DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + DAT_0067ee20 + 0xc) * 0xa9;
        FUN_00495fe0(*(undefined4 *)(iVar11 + 0x50),*(undefined4 *)(iVar11 + 0x54),
                     *(undefined4 *)(iVar11 + 0x58),&uStack_28,&uStack_20,&pcStack_24);
        iVar11 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
        fVar2 = *(float *)(DAT_006a5c38 + iVar11 + 0x54 + iVar11 * 0xa8);
        iVar11 = DAT_006a5c38 + iVar11 + iVar11 * 0xa8;
        fVar15 = (float10)FUN_00496290(*(undefined4 *)(iVar11 + 0x50),*(undefined4 *)(iVar11 + 0x54)
                                       ,*(undefined4 *)(iVar11 + 0x58),uStack_20,pcStack_24);
        if (((float10)fVar2 - fVar15 < (float10)2.5) &&
           (4.0 < ABS(*(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)))) {
          if (bVar14 == true) {
            FUN_00481a70();
          }
          else {
            FUN_00481e60(DAT_0053be28,DAT_0053be28);
          }
        }
      }
      if (_DAT_00505a24 < *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)) {
        _DAT_00505a24 = *(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20);
      }
    }
  }
  else {
    FUN_00404f00();
    FUN_0041c0b0(DAT_0053be28);
    FUN_0044a6c0();
    *(undefined4 *)(DAT_0053be28 * 0xd0 + 0x9c + DAT_0067ee20) = 0;
    *(undefined4 *)(DAT_0053be28 * 0xd0 + 0xa0 + DAT_0067ee20) = 0;
    _DAT_00507290 = 0;
    DAT_0050728c = 0;
    *(undefined4 *)(DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + iVar11) * 0xa9 + 0x7c) = 0;
  }
  ExceptionList = pvStack_c;
  return 1;
}

