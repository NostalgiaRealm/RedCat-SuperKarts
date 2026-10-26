/*
 * FUN_00475390 at 00475390
 * undefined FUN_00475390(void)
 * Address ranges: 00475390-00475726
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00475390(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 local_290 [4];
  undefined1 *local_28c;
  int local_288;
  undefined4 local_284;
  undefined1 local_280 [4];
  char *local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined1 local_270 [4];
  char *local_26c;
  undefined1 local_260 [4];
  undefined1 *local_25c;
  char local_200 [100];
  char local_19c [200];
  undefined1 local_d4 [200];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0a8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar8 = s_colors_004f7a00;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_colors_004f7a00,~uVar6 - 1);
  local_4 = 0;
  FUN_00474410(&DAT_00544de0,local_260);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  local_4 = CONCAT31(local_4._1_3_,2);
  puVar2 = DAT_00544de4;
  if (DAT_00544de4 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar2);
  FUN_00474850(local_290);
  do {
    if (local_288 == 0) {
      FUN_004b1d60(s_Race_INI_004f7a2c);
      uVar5 = FUN_004b1ed0(s_PLAYER_004f7a3c,&DAT_004f7a38);
      *(undefined4 *)(param_1 + 0x20) = uVar5;
      FUN_004afce0(s__s__d____Redcat_s_car_is__d_004f7a6c,
                   s_D__work_rcsk_Code_game_ssr_m25_g_004f7a44,0x10b,uVar5);
      if (local_28c != (undefined1 *)0x0) {
        cVar1 = local_28c[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_28c + -1);
        }
        else {
          local_28c[-1] = cVar1 + -1;
        }
      }
      local_28c = (undefined1 *)0x0;
      local_288 = 0;
      local_284 = 0;
      local_4 = local_4 & 0xffffff00;
      FUN_004746d0();
      if (local_25c != (undefined1 *)0x0) {
        cVar1 = local_25c[-1];
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          local_25c[-1] = cVar1 + -1;
          ExceptionList = local_c;
          return;
        }
        FUN_004bc150(local_25c + -1);
      }
      ExceptionList = local_c;
      return;
    }
    puVar2 = local_28c;
    if (local_28c == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    puVar3 = local_25c;
    if (local_25c == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004b1f10(puVar3,puVar2,local_d4,200);
    iVar4 = FUN_004b1f60(local_d4,&DAT_004f7a08);
    if ((0 < iVar4) && (iVar4 < 3)) {
      FUN_004b2110(0,local_19c,200);
      FUN_004b2110(1,local_200,100);
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar8 = local_200;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6 - 1;
      cVar1 = FUN_0040b600(uVar6,1);
      if (cVar1 != '\0') {
        pcVar8 = local_200;
        pcVar9 = local_27c;
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
      local_4 = CONCAT31(local_4._1_3_,3);
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar8 = local_19c;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6 - 1;
      cVar1 = FUN_0040b600(uVar6,1);
      if (cVar1 != '\0') {
        pcVar8 = local_19c;
        pcVar9 = local_26c;
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
      local_4._0_1_ = 4;
      uVar5 = FUN_00474e60(local_270,local_280);
      local_4._0_1_ = 5;
      FUN_00476990(*(undefined4 *)(param_1 + 8),1,uVar5);
      local_4._0_1_ = 6;
      FUN_0040b4f0(1);
      local_4._0_1_ = 4;
      FUN_0040b4f0(1);
      local_4._0_1_ = 3;
      FUN_0040b4f0(1);
      local_4 = CONCAT31(local_4._1_3_,2);
      if (local_27c != (char *)0x0) {
        cVar1 = local_27c[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_27c + -1);
        }
        else {
          local_27c[-1] = cVar1 + -1;
        }
      }
      local_27c = (char *)0x0;
      local_278 = 0;
      local_274 = 0;
      FUN_004afce0(s_____adding_color_glue__s__s_004f7a0c,local_19c,local_200);
    }
    FUN_004749a0(local_290);
  } while( true );
}

