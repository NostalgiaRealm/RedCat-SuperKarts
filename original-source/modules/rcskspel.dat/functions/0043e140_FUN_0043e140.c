/*
 * FUN_0043e140 at 0043e140
 * undefined FUN_0043e140(void)
 * Address ranges: 0043e140-0043ef80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0043e140(uint param_1,char *param_2,undefined4 param_3,float param_4,float param_5,
                 float param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 int **param_10,undefined4 param_11,uint param_12)

{
  float fVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  int *piStack_74;
  int *piStack_70;
  int *piStack_6c;
  byte *pbStack_68;
  int local_54;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  uint local_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [4];
  char *pcStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  char *pcStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cd600;
  local_c = ExceptionList;
  pbStack_68 = (byte *)param_2;
  local_4c = 0;
  local_48 = (char *)0x0;
  local_44 = 0;
  piStack_6c = (int *)0x43e183;
  ExceptionList = &local_c;
  cVar2 = FUN_004a6340();
  if (param_1 == 3) {
    pbStack_68 = (byte *)0x43e19a;
    uVar4 = FUN_0042abc0();
    if (uVar4 != 1) {
      ExceptionList = local_c;
      return uVar4;
    }
  }
  else if (param_1 == 4) {
    pbStack_68 = (byte *)0x43e1b4;
    uVar4 = FUN_0042abc0();
    if (uVar4 != 2) {
      ExceptionList = local_c;
      return uVar4;
    }
  }
  uVar4 = param_12;
  if (param_12 == 0) {
    if (cVar2 != '\0') goto LAB_0043e283;
    pbStack_68 = (byte *)0x1;
    piStack_70 = &local_54;
    piStack_6c = (int *)0x0;
    piStack_74 = &local_50;
    FUN_0049b870(param_2,param_3);
LAB_0043e25f:
    if ((local_50 < 0) || (local_54 < 0)) {
      pbStack_68 = (byte *)param_2;
      piStack_6c = (int *)0x172;
      piStack_70 = (int *)s_D__work_rcsk_Code_game_tob_main__004ec974;
      piStack_74 = (int *)s___s___d__Anim__s_not_found_in_et_004ec998;
      FUN_004afee0();
    }
  }
  else {
    switch(param_1) {
    case 0xb:
    case 0xe:
      pbStack_68 = (byte *)0x13b;
      piStack_6c = (int *)s_D__work_rcsk_Code_game_tob_main__004ec684;
      piStack_70 = (int *)s__s__d____Cached_object_CACHE_PIP_004ec6a8;
      piStack_74 = (int *)0x43e1f5;
      FUN_004afce0();
      pbStack_68 = (byte *)0x0;
      piStack_6c = (int *)0x43e203;
      cVar3 = FUN_0049c880();
      if (cVar3 == '\0') {
        pbStack_68 = (byte *)0x13d;
        piStack_6c = (int *)s_D__work_rcsk_Code_game_tob_main__004ec6d8;
        piStack_70 = (int *)s__s__d____First_time__filling_the_004ec6fc;
        piStack_74 = (int *)0x43e21f;
        FUN_004afce0();
        piStack_74 = (int *)0x1;
        FUN_0049b870(param_2,param_3,&local_50,&local_54,uVar4);
        pbStack_68 = (byte *)local_54;
        piStack_6c = (int *)0x0;
        piStack_70 = (int *)0x43e24a;
        FUN_0049c800();
        pbStack_68 = (byte *)s_Texture_cache_CACHE_PIPELINE_1_f_004ec738;
      }
      else {
        pbStack_68 = (byte *)0x142;
        piStack_6c = (int *)s_D__work_rcsk_Code_game_tob_main__004ec760;
        piStack_70 = (int *)s__s__d____Cache_CACHE_PIPELINE_1_a_004ec784;
        piStack_74 = (int *)0x43e363;
        FUN_004afce0();
        piStack_74 = (int *)0x0;
        FUN_0049b870(param_2,param_3,&local_50,&local_54,uVar4);
        pbStack_68 = (byte *)local_54;
        piStack_6c = (int *)0x0;
        piStack_70 = (int *)0x43e38d;
        FUN_0049c850();
        pbStack_68 = (byte *)s_Added_texture_to_cache_CACHE_PIP_004ec7d0;
      }
      break;
    default:
      if (cVar2 == '\0') {
        pbStack_68 = (byte *)0x1;
        piStack_70 = &local_54;
        piStack_6c = (int *)param_12;
        piStack_74 = &local_50;
        FUN_0049b870(param_2,param_3);
        goto LAB_0043e25f;
      }
      goto LAB_0043e283;
    case 0x10:
    case 0x11:
      pbStack_68 = (byte *)0x14c;
      piStack_6c = (int *)s_D__work_rcsk_Code_game_tob_main__004ec7fc;
      piStack_70 = (int *)s__s__d____Cached_object_CACHE_PIP_004ec820;
      piStack_74 = (int *)0x43e3ab;
      FUN_004afce0();
      pbStack_68 = (byte *)0x1;
      piStack_6c = (int *)0x43e3ba;
      cVar3 = FUN_0049c880();
      if (cVar3 == '\0') {
        pbStack_68 = (byte *)0x14e;
        piStack_6c = (int *)s_D__work_rcsk_Code_game_tob_main__004ec850;
        piStack_70 = (int *)s__s__d____First_time__filling_the_004ec874;
        piStack_74 = (int *)0x43e3d2;
        FUN_004afce0();
        piStack_74 = (int *)0x1;
        FUN_0049b870(param_2,param_3,&local_50,&local_54,uVar4);
        pbStack_68 = (byte *)local_54;
        piStack_6c = (int *)0x1;
        piStack_70 = (int *)0x43e3fe;
        FUN_0049c800();
        pbStack_68 = (byte *)s_Texture_cache_CACHE_PIPELINE_2_f_004ec8b0;
      }
      else {
        pbStack_68 = (byte *)0x153;
        piStack_6c = (int *)s_D__work_rcsk_Code_game_tob_main__004ec8d8;
        piStack_70 = (int *)s__s__d____Cache_CACHE_PIPELINE_2_a_004ec8fc;
        piStack_74 = (int *)0x43e41c;
        FUN_004afce0();
        piStack_74 = (int *)0x0;
        FUN_0049b870(param_2,param_3,&local_50,&local_54,uVar4);
        pbStack_68 = (byte *)local_54;
        piStack_6c = (int *)0x1;
        piStack_70 = (int *)0x43e447;
        FUN_0049c850();
        pbStack_68 = (byte *)s_Added_texture_to_cache_CACHE_PIP_004ec948;
      }
    }
    piStack_6c = (int *)0x43e254;
    FUN_004afce0();
    if (cVar2 == '\0') goto LAB_0043e25f;
  }
LAB_0043e283:
  fVar1 = _DAT_004fc8f4 * 0.0027777778;
  pbStack_68 = (byte *)param_1;
  piStack_6c = (int *)0x43e2b9;
  piVar5 = (int *)FUN_00493210();
  piStack_6c = (int *)param_1;
  piStack_70 = (int *)0x43e2c1;
  uVar6 = FUN_00493250();
  piStack_70 = (int *)s_Creating_object_004ec9c8;
  piStack_74 = (int *)0x43e2cd;
  FUN_004afce0();
  if (cVar2 == '\0') {
    pbStack_68 = (byte *)s_based_on_mesh_texture_004ec9f0;
    piStack_6c = (int *)0x43e4af;
    FUN_004afce0();
    pbStack_68 = (byte *)param_10;
    piStack_6c = (int *)0x0;
    piStack_74 = piVar5;
    piStack_70 = (int *)uVar6;
    piVar5 = (int *)FUN_0048fc70(param_7,param_8,param_9,fVar1 * param_4,-(fVar1 * param_5),
                                 fVar1 * param_6,local_50,local_54);
  }
  else {
    pbStack_68 = (byte *)s_based_on_3D_anim_004ec9dc;
    piStack_6c = (int *)0x43e2e6;
    FUN_004afce0();
    pbStack_68 = (byte *)param_2;
    piStack_6c = (int *)0x43e2f4;
    uVar7 = FUN_004a6200();
    pbStack_68 = (byte *)param_10;
    piStack_6c = (int *)0x0;
    piStack_74 = piVar5;
    piStack_70 = (int *)uVar6;
    piVar5 = (int *)FUN_0048fb60(param_7,param_8,param_9,fVar1 * param_4,-(fVar1 * param_5),
                                 fVar1 * param_6,uVar7,0);
  }
  pbStack_68 = (byte *)s_Object_created_succesfully_004eca08;
  iVar13 = (int)piVar5 * 0xd0;
  *(undefined4 *)(DAT_0067ee20 + 0x1c + iVar13) = param_11;
  piStack_6c = (int *)0x43e53c;
  FUN_004afce0();
  param_3._0_1_ = SUB41(piVar5,0);
  uVar4 = param_1 - 1;
  switch(param_1) {
  case 1:
    pbStack_68 = (byte *)param_10;
    piStack_70 = (int *)0x43e76b;
    piStack_6c = piVar5;
    uVar4 = FUN_0043f020();
    ExceptionList = local_c;
    return uVar4;
  case 2:
    pbStack_68 = (byte *)s_PION_HIT_CAR_004eca24;
    piStack_70 = (int *)0x43e569;
    piStack_6c = piVar5;
    uVar4 = FUN_0043b760();
    ExceptionList = local_c;
    return uVar4;
  case 3:
  case 6:
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0x2e:
  case 0x2f:
    if (param_1 == 3) {
      pbStack_68 = (byte *)0x43e850;
      uVar4 = FUN_0042abc0();
      if (uVar4 != 1) {
        ExceptionList = local_c;
        return uVar4;
      }
    }
    pbStack_68 = (byte *)param_10;
    piStack_70 = (int *)0x43e86b;
    piStack_6c = piVar5;
    FUN_0043f020();
    local_4c = CONCAT31(local_4c._1_3_,(undefined1)param_3);
    uVar4 = 0xffffffff;
    pcVar15 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar15;
      pcVar15 = pcVar15 + 1;
    } while (cVar2 != '\0');
    pbStack_68 = (byte *)(~uVar4 - 1);
    local_48 = (char *)0x0;
    piStack_6c = (int *)param_2;
    local_44 = 0;
    uStack_40 = 0;
    piStack_70 = (int *)0x43e899;
    FUN_0040b540();
    uStack_4 = 0;
    param_10 = (int **)0x5;
    param_12 = local_44 - 5;
    if (local_44 < param_12) {
      pbStack_68 = (byte *)0x43e8bf;
      FUN_004bc243();
    }
    pcVar15 = local_48;
    if (((local_48 != (char *)0x0) && (local_48[-1] != '\0')) && (local_48[-1] != -1)) {
      pbStack_68 = (byte *)0x1;
      piStack_6c = (int *)0x43e8e3;
      FUN_0040b4f0();
      uVar4 = 0xffffffff;
      pcVar14 = pcVar15;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar2 = *pcVar14;
        pcVar14 = pcVar14 + 1;
      } while (cVar2 != '\0');
      pbStack_68 = (byte *)(~uVar4 - 1);
      piStack_6c = (int *)pcVar15;
      piStack_70 = (int *)0x43e8fc;
      FUN_0040b540();
    }
    uVar4 = local_44 - param_12;
    if ((4 < uVar4) || (param_10 = (int **)uVar4, uVar4 != 0)) {
      piStack_70 = (int *)(local_48 + param_12);
      pbStack_68 = (byte *)(uVar4 - (int)param_10);
      piStack_6c = (int *)((int)piStack_70 + (int)param_10);
      piStack_74 = (int *)0x43e936;
      FUN_004bef90();
      uVar4 = local_44 - (int)param_10;
      pbStack_68 = (byte *)0x0;
      piStack_70 = (int *)0x43e951;
      piStack_6c = (int *)uVar4;
      cVar2 = FUN_0040b600();
      if (cVar2 != '\0') {
        local_48[uVar4] = '\0';
        local_44 = uVar4;
      }
    }
    param_10 = &piStack_74;
    piStack_74._0_1_ = (undefined1)local_4c;
    piStack_70 = (int *)0x0;
    piStack_6c = (int *)0x0;
    pbStack_68 = (byte *)0x0;
    FUN_00412870(&local_4c,0,0xffffffff);
    piStack_6c = (int *)FUN_0044d4d0();
    piStack_70 = (int *)0x43e9a6;
    pbStack_68 = (byte *)piVar5;
    FUN_0044d4b0();
    piStack_6c = (int *)0x43e9ad;
    FUN_0044f9c0();
    param_10 = &piStack_74;
    piStack_74 = (int *)CONCAT31(piStack_74._1_3_,(undefined1)local_4c);
    piStack_70 = (int *)0x0;
    piStack_6c = (int *)0x0;
    pbStack_68 = (byte *)0x0;
    FUN_00412870(&local_4c,0,0xffffffff);
    pbStack_68 = (byte *)FUN_0044d4d0();
    piStack_70 = (int *)0x43e9f0;
    piStack_6c = piVar5;
    FUN_0044d710();
    param_10 = &piStack_74;
    FUN_0042eab0(&local_4c);
    pbStack_68 = (byte *)FUN_0044d4d0();
    piStack_6c = (int *)0x43ea1b;
    puVar10 = (undefined4 *)FUN_0044d4b0();
    pbStack_68 = (byte *)&local_4c;
    piStack_6c = (int *)0x43ea26;
    (**(code **)*puVar10)();
    pbStack_68 = (byte *)local_48;
    if (param_1 == 9) {
      iVar13 = *(int *)(DAT_0067ee20 + 0xc + iVar13);
      param_1 = iVar13 * 0x15;
      *(undefined4 *)(DAT_006a5c38 + iVar13 * 0xa9 + 0xa5) = 1;
    }
    else if (param_1 == 10) {
      iVar13 = *(int *)(DAT_0067ee20 + 0xc + iVar13);
      param_1 = iVar13 * 0x15;
      *(undefined4 *)(DAT_006a5c38 + iVar13 * 0xa9 + 0xa5) = 2;
    }
    else if (param_1 == 6) {
      uVar4 = 0xffffffff;
      pcVar15 = param_2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar2 = *pcVar15;
        pcVar15 = pcVar15 + 1;
      } while (cVar2 != '\0');
      uVar4 = ~uVar4 - 1;
      pbStack_68 = (byte *)0x1;
      auStack_1c[0] = (undefined1)param_3;
      pcStack_18 = (char *)0x0;
      uStack_14 = 0;
      uStack_10 = 0;
      piStack_70 = (int *)0x43eacf;
      piStack_6c = (int *)uVar4;
      cVar2 = FUN_0040b600();
      if (cVar2 != '\0') {
        pcVar15 = pcStack_18;
        for (uVar11 = uVar4 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)param_2;
          param_2 = param_2 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar11 = uVar4 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *pcVar15 = *param_2;
          param_2 = param_2 + 1;
          pcVar15 = pcVar15 + 1;
        }
        piStack_6c = (int *)0x43eaf1;
        pbStack_68 = (byte *)uVar4;
        FUN_0040b5e0();
      }
      pbStack_68 = auStack_1c;
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      piStack_70 = (int *)0x43eb05;
      piStack_6c = piVar5;
      FUN_0043d0f0();
      param_1 = 0;
      if (pcStack_18 != (char *)0x0) {
        pbStack_68 = (byte *)(pcStack_18 + -1);
        cVar2 = pcStack_18[-1];
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          piStack_6c = (int *)0x43eb2a;
          param_1 = FUN_004bc150();
        }
        else {
          param_1 = (uint)(byte)(cVar2 - 1U);
          *pbStack_68 = cVar2 - 1U;
        }
      }
      pcStack_18 = (char *)0x0;
      uStack_14 = 0;
      uStack_10 = 0;
      pbStack_68 = (byte *)local_48;
    }
    goto LAB_0043ecc3;
  case 5:
  case 0xe:
  case 0x11:
    piStack_70 = (int *)local_4c;
    piStack_6c = (int *)local_48;
    pbStack_68 = (byte *)local_44;
    piStack_74 = piVar5;
    uVar4 = FUN_0043f1b0();
    ExceptionList = local_c;
    return uVar4;
  case 7:
  case 0x2b:
    pbStack_68 = (byte *)s_RotObj_ini_004eca34;
    piStack_6c = (int *)0x43e589;
    FUN_004b1d60();
    piStack_6c = (int *)s_RotationX_004eca40;
    piStack_70 = (int *)param_2;
    iVar8 = DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + iVar13) * 0xa9;
    piStack_74 = (int *)0x43e5b3;
    uVar4 = FUN_004b1ed0();
    piStack_74 = (int *)s_RotationY_004eca4c;
    *(float *)(iVar8 + 0x68) = (float)uVar4 * 0.001;
    iVar8 = DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + iVar13) * 0xa9;
    uVar4 = FUN_004b1ed0(param_2);
    *(float *)(iVar8 + 0x6c) = (float)uVar4 * 0.001;
    iVar8 = DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + iVar13) * 0xa9;
    uVar4 = FUN_004b1ed0(param_2,s_RotationZ_004eca58);
    *(float *)(iVar8 + 0x70) = (float)uVar4 * 0.001;
    iVar8 = FUN_004b1ed0(param_2,s_StartRandomX_004eca64);
    if (iVar8 == 1) {
      iVar8 = DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + iVar13) * 0xa9;
      pbStack_68 = (byte *)0x43e69b;
      iVar9 = FUN_004be6c9();
      *(float *)(iVar8 + 0x74) = (float)(iVar9 % 2000);
    }
    pbStack_68 = (byte *)s_StartRandomY_004eca74;
    piStack_6c = (int *)param_2;
    piStack_70 = (int *)0x43e6b9;
    iVar8 = FUN_004b1ed0();
    if (iVar8 == 1) {
      iVar9 = DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + iVar13) * 0xa9;
      pbStack_68 = (byte *)0x43e6e7;
      iVar8 = FUN_004be6c9();
      *(float *)(iVar9 + 0x78) = (float)(iVar8 % 2000);
    }
    pbStack_68 = (byte *)s_StartRandomZ_004eca84;
    piStack_6c = (int *)param_2;
    piStack_70 = (int *)0x43e705;
    uVar4 = FUN_004b1ed0();
    if (uVar4 == 1) {
      iVar8 = DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + iVar13) * 0xa9;
      pbStack_68 = (byte *)0x43e737;
      iVar13 = FUN_004be6c9();
      *(float *)(iVar8 + 0x7c) = (float)(iVar13 % 2000);
      ExceptionList = local_c;
      return iVar13 / 2000;
    }
    break;
  case 8:
    piStack_70 = (int *)local_4c;
    piStack_6c = (int *)local_48;
    pbStack_68 = (byte *)local_44;
    piStack_74 = piVar5;
    uVar4 = FUN_0043f200();
    ExceptionList = local_c;
    return uVar4;
  case 0xf:
    piStack_70 = (int *)local_4c;
    piStack_6c = (int *)local_48;
    pbStack_68 = (byte *)local_44;
    piStack_74 = piVar5;
    FUN_0043f1b0();
    uVar4 = FUN_0043f400(piVar5);
    ExceptionList = local_c;
    return uVar4;
  case 0x12:
    pbStack_68 = (byte *)param_2;
    piStack_6c = (int *)s_Loading_start_anim____s__004eca94;
    piStack_70 = (int *)0x43e823;
    FUN_004afce0();
    piStack_74 = (int *)0x43e829;
    piStack_70 = piVar5;
    uVar4 = FUN_0043f430();
    ExceptionList = local_c;
    return uVar4;
  case 0x13:
    piStack_70 = (int *)local_4c;
    piStack_6c = (int *)local_48;
    pbStack_68 = (byte *)local_44;
    piStack_74 = piVar5;
    FUN_0043f1b0();
    FUN_0043f020(piVar5,param_10);
    auStack_3c[0] = (undefined1)param_3;
    uVar4 = 0xffffffff;
    pcVar15 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar15;
      pcVar15 = pcVar15 + 1;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4 - 1;
    pbStack_68 = (byte *)0x1;
    pcStack_38 = (char *)0x0;
    uStack_34 = 0;
    uStack_30 = 0;
    piStack_70 = (int *)0x43eba7;
    piStack_6c = (int *)uVar4;
    cVar2 = FUN_0040b600();
    if (cVar2 != '\0') {
      pcVar15 = pcStack_38;
      for (uVar11 = uVar4 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)param_2;
        param_2 = param_2 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar11 = uVar4 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *pcVar15 = *param_2;
        param_2 = param_2 + 1;
        pcVar15 = pcVar15 + 1;
      }
      pcStack_38[uVar4] = '\0';
      uStack_34 = uVar4;
    }
    uStack_4 = 2;
    uVar4 = uStack_34 - 5;
    if (uStack_34 < uVar4) {
      pbStack_68 = (byte *)0x43ebe7;
      FUN_004bc243();
    }
    pcVar15 = pcStack_38;
    if (((pcStack_38 != (char *)0x0) && (pcStack_38[-1] != '\0')) && (pcStack_38[-1] != -1)) {
      pbStack_68 = (byte *)0x1;
      param_10 = (int **)pcStack_38;
      piStack_6c = (int *)0x43ec11;
      FUN_0040b4f0();
      uVar11 = 0xffffffff;
      do {
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        cVar2 = *pcVar15;
        pcVar15 = pcVar15 + 1;
      } while (cVar2 != '\0');
      pbStack_68 = (byte *)(~uVar11 - 1);
      piStack_6c = (int *)param_10;
      piStack_70 = (int *)0x43ec2d;
      FUN_0040b540();
    }
    uVar12 = uStack_34 - uVar4;
    uVar11 = 5;
    if ((4 < uVar12) || (uVar11 = uVar12, uVar12 != 0)) {
      piStack_70 = (int *)(pcStack_38 + uVar4);
      pbStack_68 = (byte *)((uStack_34 - uVar4) - uVar11);
      piStack_6c = (int *)((int)piStack_70 + uVar11);
      piStack_74 = (int *)0x43ec56;
      FUN_004bef90();
      uVar11 = uStack_34 - uVar11;
      pbStack_68 = (byte *)0x0;
      piStack_70 = (int *)0x43ec6a;
      piStack_6c = (int *)uVar11;
      cVar2 = FUN_0040b600();
      if (cVar2 != '\0') {
        pcStack_38[uVar11] = '\0';
        uStack_34 = uVar11;
      }
    }
    param_10 = &piStack_74;
    piStack_74 = (int *)CONCAT31(piStack_74._1_3_,auStack_3c[0]);
    piStack_70 = (int *)0x0;
    piStack_6c = (int *)0x0;
    pbStack_68 = (byte *)0x0;
    FUN_00412870(auStack_3c,0,0xffffffff);
    pbStack_68 = (byte *)FUN_0044d4d0();
    piStack_70 = (int *)0x43ecbf;
    piStack_6c = piVar5;
    param_1 = FUN_0044d710();
    pbStack_68 = (byte *)pcStack_38;
LAB_0043ecc3:
    uVar4 = param_1;
    if (pbStack_68 != (byte *)0x0) {
      cVar2 = pbStack_68[-1];
      if ((cVar2 != '\0') && (cVar2 != -1)) {
        pbStack_68[-1] = cVar2 - 1U;
        ExceptionList = local_c;
        return (uint)(byte)(cVar2 - 1U);
      }
      pbStack_68 = pbStack_68 + -1;
LAB_0043ecef:
      piStack_6c = (int *)0x43ecf5;
      uVar4 = FUN_004bc150();
      ExceptionList = local_c;
      return uVar4;
    }
    break;
  case 0x14:
    pbStack_68 = (byte *)param_10;
    piStack_70 = (int *)0x43e7f9;
    piStack_6c = piVar5;
    FUN_0043f020();
  case 0x15:
    piStack_6c = (int *)0x43e802;
    pbStack_68 = (byte *)piVar5;
    uVar4 = FUN_0043f400();
    ExceptionList = local_c;
    return uVar4;
  case 0x16:
    pbStack_68 = (byte *)s_PAAL_HIT_GROUND_004ecab0;
    piStack_70 = (int *)0x43ed51;
    piStack_6c = piVar5;
    uVar4 = FUN_0043b760();
    ExceptionList = local_c;
    return uVar4;
  case 0x17:
    piStack_70 = (int *)local_4c;
    piStack_6c = (int *)local_48;
    pbStack_68 = (byte *)local_44;
    piStack_74 = piVar5;
    uVar4 = FUN_0043f3b0();
    ExceptionList = local_c;
    return uVar4;
  case 0x18:
    piStack_70 = (int *)local_4c;
    piStack_6c = (int *)local_48;
    pbStack_68 = (byte *)local_44;
    piStack_74 = piVar5;
    uVar4 = FUN_0043f360();
    ExceptionList = local_c;
    return uVar4;
  case 0x19:
    piStack_70 = (int *)local_4c;
    piStack_6c = (int *)local_48;
    pbStack_68 = (byte *)local_44;
    piStack_74 = piVar5;
    uVar4 = FUN_0043f2c0();
    ExceptionList = local_c;
    return uVar4;
  case 0x1a:
    pbStack_68 = (byte *)s_PION_HIT_CAR_004ecac0;
    piStack_70 = (int *)0x43ed72;
    piStack_6c = piVar5;
    FUN_0043b760();
    uVar4 = DAT_0067ee20;
    *(undefined4 *)(DAT_0067ee20 + 0x14 + iVar13) = 0;
    ExceptionList = local_c;
    return uVar4;
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    pbStack_68 = (byte *)0x43ef4e;
    FUN_004513c0();
    pbStack_68 = (byte *)param_1;
    piStack_6c = (int *)0x43ef5a;
    pbStack_68 = (byte *)FUN_00451f80();
    piStack_6c = &param_7;
    piStack_74 = (int *)0x43ef6e;
    piStack_70 = piVar5;
    uVar4 = FUN_004512b0();
    break;
  case 0x2c:
    piStack_6c = (int *)0x43ee36;
    pbStack_68 = (byte *)piVar5;
    uVar4 = FUN_0043f250();
    ExceptionList = local_c;
    return uVar4;
  case 0x2d:
    auStack_2c[0] = (undefined1)param_3;
    uVar4 = 0xffffffff;
    pcStack_28 = (char *)0x0;
    pcVar15 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar15;
      pcVar15 = pcVar15 + 1;
    } while (cVar2 != '\0');
    uVar11 = ~uVar4 - 1;
    uStack_24 = 0;
    uStack_20 = 0;
    pbStack_68 = (byte *)0x43ee77;
    uVar4 = FUN_00412a70();
    if (uVar4 < uVar11) {
      pbStack_68 = (byte *)0x43ee80;
      FUN_004bc15b();
    }
    if (((pcStack_28 == (char *)0x0) || (cVar2 = pcStack_28[-1], cVar2 == '\0')) || (cVar2 == -1)) {
      if (uVar11 != 0) {
        if ((0x1f < uStack_20) || (uStack_20 < uVar11)) {
          pbStack_68 = (byte *)0x1;
          piStack_6c = (int *)0x43eed1;
          FUN_0040b4f0();
          goto LAB_0043eed1;
        }
        goto LAB_0043eedf;
      }
      pbStack_68 = (byte *)0x1;
      piStack_6c = (int *)0x43eeb7;
      FUN_0040b4f0();
    }
    else if (uVar11 == 0) {
      pbStack_68 = (byte *)0x0;
      pcStack_28[-1] = cVar2 + -1;
      piStack_6c = (int *)0x43eea6;
      FUN_0040b4f0();
    }
    else {
LAB_0043eed1:
      piStack_6c = (int *)0x43eedb;
      pbStack_68 = (byte *)uVar11;
      FUN_0040b720();
LAB_0043eedf:
      pcVar15 = pcStack_28;
      for (uVar4 = uVar11 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)param_2;
        param_2 = param_2 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar4 = uVar11 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar15 = *param_2;
        param_2 = param_2 + 1;
        pcVar15 = pcVar15 + 1;
      }
      pcStack_28[uVar11] = '\0';
      uStack_24 = uVar11;
    }
    pbStack_68 = auStack_2c;
    uStack_4 = 3;
    piStack_70 = (int *)0x43ef11;
    piStack_6c = piVar5;
    FUN_0043d110();
    if (pcStack_28 == (char *)0x0) {
      ExceptionList = local_c;
      return 0;
    }
    pbStack_68 = (byte *)(pcStack_28 + -1);
    cVar2 = pcStack_28[-1];
    if ((cVar2 != '\0') && (cVar2 != -1)) {
      *pbStack_68 = cVar2 - 1U;
      ExceptionList = local_c;
      return (uint)(byte)(cVar2 - 1U);
    }
    goto LAB_0043ecef;
  }
  ExceptionList = local_c;
  return uVar4;
}

