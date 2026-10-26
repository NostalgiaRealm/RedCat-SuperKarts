/*
 * FUN_00475730 at 00475730
 * undefined FUN_00475730(void)
 * Address ranges: 00475730-00475db3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475730(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  float local_3a4 [2];
  undefined1 *local_39c;
  int local_398;
  undefined4 local_394;
  undefined1 local_390 [4];
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  int local_380;
  undefined1 local_37c [4];
  char *local_378;
  undefined1 local_36c [4];
  char *local_368;
  undefined1 local_35c [4];
  char *local_358;
  undefined1 local_34c [4];
  undefined1 *local_348;
  undefined1 local_33c [16];
  undefined1 local_32c [16];
  undefined1 local_31c [80];
  char local_2cc [196];
  char local_208 [100];
  char local_1a4 [100];
  char local_140 [100];
  undefined1 local_dc [100];
  char local_78 [100];
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_004d0b3a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_0040b4f0();
  uVar5 = 0xffffffff;
  pcVar8 = &DAT_004f7a8c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f7a8c,~uVar5 - 1);
  local_c = 0;
  FUN_00474410(&DAT_00544de0,local_34c);
  local_c._0_1_ = 1;
  FUN_004b1d60();
  FUN_0040b4f0();
  local_c = CONCAT31(local_c._1_3_,2);
  FUN_00474850();
  do {
    if (local_398 == 0) {
      if (local_39c != (undefined1 *)0x0) {
        cVar1 = local_39c[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150();
        }
        else {
          local_39c[-1] = cVar1 + -1;
        }
      }
      local_39c = (undefined1 *)0x0;
      local_398 = 0;
      local_394 = 0;
      local_c = local_c & 0xffffff00;
      FUN_004746d0();
      if (local_348 != (undefined1 *)0x0) {
        cVar1 = local_348[-1];
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          local_348[-1] = cVar1 + -1;
          ExceptionList = local_14;
          return;
        }
        FUN_004bc150();
      }
      ExceptionList = local_14;
      return;
    }
    local_38c = 0;
    local_388 = 0;
    local_384 = 0;
    local_c._1_3_ = (undefined3)(local_c >> 8);
    local_c = CONCAT31(local_c._1_3_,3);
    puVar6 = local_39c;
    if (local_39c == (undefined1 *)0x0) {
      puVar6 = &DAT_004d2404;
    }
    puVar2 = local_348;
    if (local_348 == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    FUN_004b1f10(puVar2,puVar6,local_31c,0x1e);
    puVar6 = local_39c;
    if (local_39c == (undefined1 *)0x0) {
      puVar6 = &DAT_004d2404;
    }
    FUN_004afce0(s_1__car__s_settings_line___s__004f7a94,puVar6);
    iVar3 = FUN_004b1f60(local_31c,&DAT_004f7ab4);
    puVar6 = local_39c;
    if (local_39c == (undefined1 *)0x0) {
      puVar6 = &DAT_004d2404;
    }
    FUN_004afce0(s_2__car__s_settings_line___s__004f7ab8,puVar6);
    if (0 < iVar3) {
      FUN_004b2110(0,local_2cc);
      FUN_004b2110(1,local_78,100);
      FUN_004b1f10(local_2cc,&DAT_004f7ad8,local_140,100);
      FUN_004b1f10(local_2cc,s_fwheels_004f7ae0,local_1a4,100);
      FUN_004b1f10(local_2cc,s_bwheels_004f7ae8,local_208,100);
      FUN_004b1f10(local_2cc,s_wheelpos_004f7af0,local_dc,100);
      iVar3 = FUN_004b1f60(local_dc,&DAT_004f7afc);
      FUN_004afce0(s___There_are__d_wheel_settings_004f7b00,iVar3);
      if (5 < iVar3) {
        iVar3 = 0;
        do {
          local_3a4[0] = 0.0;
          FUN_004b2110(iVar3,local_dc,100);
          FUN_004bf458(local_dc,&DAT_004f7b20,local_3a4);
          FUN_004afce0(s___wheel_pos__d___f_004f7b24,iVar3,(double)local_3a4[0]);
          FUN_00459170(local_388,1,local_3a4);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 6);
        FUN_0040b4f0();
        uVar5 = 0xffffffff;
        pcVar8 = local_208;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5 - 1;
        cVar1 = FUN_0040b600(uVar5,1);
        if (cVar1 != '\0') {
          pcVar8 = local_208;
          pcVar9 = local_368;
          for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            pcVar9 = pcVar9 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar9 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar9 = pcVar9 + 1;
          }
          FUN_0040b5e0();
        }
        local_c = CONCAT31(local_c._1_3_,4);
        FUN_0040b4f0();
        uVar5 = 0xffffffff;
        pcVar8 = local_1a4;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5 - 1;
        cVar1 = FUN_0040b600(uVar5,1);
        if (cVar1 != '\0') {
          pcVar8 = local_1a4;
          pcVar9 = local_378;
          for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            pcVar9 = pcVar9 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar9 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar9 = pcVar9 + 1;
          }
          FUN_0040b5e0();
        }
        local_c = CONCAT31(local_c._1_3_,5);
        FUN_0040b4f0();
        uVar5 = 0xffffffff;
        pcVar8 = local_140;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5 - 1;
        cVar1 = FUN_0040b600(uVar5,1);
        if (cVar1 != '\0') {
          pcVar8 = local_140;
          pcVar9 = local_358;
          for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            pcVar9 = pcVar9 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar9 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar9 = pcVar9 + 1;
          }
          FUN_0040b5e0();
        }
        local_c._0_1_ = 6;
        FUN_0040b4f0();
        uVar5 = 0xffffffff;
        pcVar8 = local_78;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(local_78,~uVar5 - 1);
        local_c._0_1_ = 7;
        FUN_0040b4f0();
        uVar5 = 0xffffffff;
        pcVar8 = local_2cc;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(local_2cc,~uVar5 - 1);
        local_c._0_1_ = 8;
        uVar4 = FUN_00474fa0(local_33c,local_32c,local_35c,local_37c,local_36c,local_390);
        local_c._0_1_ = 9;
        FUN_00476ca0(*(undefined4 *)(local_380 + 0x18),1,uVar4);
        local_c._0_1_ = 0xe;
        FUN_00418ec0();
        local_c._0_1_ = 0xd;
        FUN_0040b4f0();
        local_c._0_1_ = 0xc;
        FUN_0040b4f0();
        local_c._0_1_ = 0xb;
        FUN_0040b4f0();
        local_c._0_1_ = 10;
        FUN_0040b4f0();
        local_c._0_1_ = 8;
        FUN_0040b4f0();
        local_c._0_1_ = 7;
        FUN_0040b4f0();
        local_c._0_1_ = 6;
        FUN_0040b4f0();
        local_c._0_1_ = 5;
        FUN_0040b4f0();
        local_c._0_1_ = 4;
        FUN_0040b4f0();
        local_c = CONCAT31(local_c._1_3_,3);
        FUN_0040b4f0();
        FUN_004afce0(s___added_car__s__file_pf__s__mesh_004f7b38,local_2cc,local_78,local_140,
                     local_1a4);
      }
    }
    FUN_004749a0();
    FUN_004bc150();
    local_38c = 0;
    local_388 = 0;
    local_384 = 0;
  } while( true );
}

