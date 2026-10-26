/*
 * FUN_0045a030 at 0045a030
 * undefined FUN_0045a030(void)
 * Address ranges: 0045a030-0045a6ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0045a030(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  int local_12c;
  undefined1 local_11c [4];
  char *local_118;
  undefined1 local_10c [4];
  char *local_108;
  undefined1 local_fc [4];
  char *local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  int local_ec;
  undefined1 local_e8 [4];
  char *local_e4;
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [28];
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
  puStack_8 = &LAB_004ce1b6;
  local_c = ExceptionList;
  local_ec = param_1 + 0x9c;
  ExceptionList = &local_c;
  iVar2 = FUN_0045aab0(param_2);
  if (iVar2 != 0) {
    uVar7 = *(uint *)(param_2 + 8);
    if (*(uint *)(param_1 + 0x98) < uVar7) {
      uVar7 = *(uint *)(param_1 + 0x98);
    }
    iVar2 = 0;
    iVar3 = FUN_00463b30();
    if (iVar3 == 0) {
      local_12c = 0;
    }
    else {
      if (iVar3 == 1) {
        local_12c = (int)(*(int *)(param_1 + 0x98) - uVar7) / 2;
      }
      else {
        if (iVar3 != 2) {
          FUN_0040b4f0(0);
          uVar7 = 0xffffffff;
          pcVar10 = &DAT_004f2a08;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          FUN_0040b540(&DAT_004f2a08,~uVar7 - 1);
          local_4 = 0;
          uVar4 = FUN_00463d20(local_2c,0x3d);
          local_4._0_1_ = 1;
          FUN_0040b4f0(0);
          uVar7 = 0xffffffff;
          pcVar10 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2a10;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Fixed_004f2a10,~uVar7 - 1);
          local_4._0_1_ = 2;
          FUN_0040b4f0(0);
          uVar7 = 0xffffffff;
          pcVar10 = s_HeadUp_Display_exception_in__004f2a3c;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          FUN_0040b540(s_HeadUp_Display_exception_in__004f2a3c,~uVar7 - 1);
          local_4._0_1_ = 3;
          uVar5 = FUN_00459040(local_1c,local_b8,local_d8);
          local_4._0_1_ = 4;
          uVar5 = FUN_0041b630(local_6c,uVar5,&DAT_004f2a0c);
          local_4._0_1_ = 5;
          uVar4 = FUN_00459040(local_8c,uVar5,uVar4);
          local_4._0_1_ = 6;
          uVar4 = FUN_00459040(local_4c,uVar4,local_c8);
          local_4._0_1_ = 7;
          uVar4 = FUN_0041b630(local_7c,uVar4,s_Unknown_alignment_in_string_004f29e8);
          local_4._0_1_ = 8;
          uVar5 = FUN_004583c0();
          uVar4 = FUN_00459040(local_5c,uVar4,uVar5);
          local_4._0_1_ = 9;
          uVar4 = FUN_0041b630(local_3c,uVar4,&DAT_004f29e4);
          local_4 = CONCAT31(local_4._1_3_,10);
          FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_a8,&DAT_004d6580);
        }
        local_12c = *(int *)(param_1 + 0x98) - uVar7;
      }
      if (0 < local_12c) {
        do {
          iVar3 = FUN_00463b80();
          uVar4 = *(undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + 4) + iVar2 * 4);
          FUN_0040b4f0(0);
          uVar8 = 0xffffffff;
          pcVar10 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2a5c;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Fixed_004f2a5c,~uVar8 - 1);
          local_4 = 0xb;
          FUN_0040b4f0(0);
          uVar8 = 0xffffffff;
          pcVar10 = s_Null_character_in_string_004f2a88;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          FUN_0040b540(s_Null_character_in_string_004f2a88,~uVar8 - 1);
          local_4._0_1_ = 0xc;
          FUN_00464530(uVar4,local_11c,local_10c,0x44);
          local_4 = CONCAT31(local_4._1_3_,0xb);
          FUN_0040b4f0(1);
          local_4 = 0xffffffff;
          FUN_0040b4f0(1);
          uVar4 = 0x20;
          FUN_00463b20(0x20);
          uVar4 = FUN_0045ac50(uVar4);
          FUN_00459990(uVar4);
          iVar2 = iVar2 + 1;
        } while (iVar2 < local_12c);
      }
    }
    for (; iVar2 < (int)(local_12c + uVar7); iVar2 = iVar2 + 1) {
      iVar3 = FUN_00463b80();
      uVar4 = *(undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + 4) + iVar2 * 4);
      FUN_0040b4f0(0);
      uVar8 = 0xffffffff;
      pcVar10 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2aa4;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8 - 1;
      cVar1 = FUN_0040b600(uVar8,1);
      if (cVar1 != '\0') {
        pcVar10 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2aa4;
        pcVar11 = local_118;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar11 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar11 = pcVar11 + 1;
        }
        FUN_0040b5e0(uVar8);
      }
      local_4 = 0xd;
      FUN_0040b4f0(0);
      uVar8 = 0xffffffff;
      pcVar10 = s_Null_character_in_string_004f2ad0;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8 - 1;
      cVar1 = FUN_0040b600(uVar8,1);
      if (cVar1 != '\0') {
        pcVar10 = s_Null_character_in_string_004f2ad0;
        pcVar11 = local_108;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar11 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar11 = pcVar11 + 1;
        }
        FUN_0040b5e0(uVar8);
      }
      local_4._0_1_ = 0xe;
      FUN_00464530(uVar4,local_10c,local_11c,0x4d);
      local_4 = CONCAT31(local_4._1_3_,0xd);
      FUN_0040b4f0(1);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      if (*(int *)(param_2 + 4) == 0) {
        pbVar6 = &DAT_004d2404;
      }
      else {
        pbVar6 = (byte *)((*(int *)(param_2 + 4) - local_12c) + iVar2);
      }
      uVar8 = (uint)*pbVar6;
      FUN_00463b20(uVar8);
      uVar4 = FUN_0045ac50(uVar8);
      FUN_00459990(uVar4);
    }
    if (iVar2 < *(int *)(param_1 + 0x98)) {
      do {
        iVar3 = FUN_00463b80();
        uVar4 = *(undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + 4) + iVar2 * 4);
        FUN_0040b4f0(0);
        uVar7 = 0xffffffff;
        pcVar10 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2aec;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        uVar7 = ~uVar7 - 1;
        cVar1 = FUN_0040b600(uVar7,1);
        if (cVar1 != '\0') {
          pcVar10 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2aec;
          pcVar11 = local_f8;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar11 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar11 = pcVar11 + 1;
          }
          FUN_0040b5e0(uVar7);
        }
        local_4 = 0xf;
        FUN_0040b4f0(0);
        uVar7 = 0xffffffff;
        pcVar10 = s_Null_character_in_string_004f2b18;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        uVar7 = ~uVar7 - 1;
        cVar1 = FUN_0040b600(uVar7,1);
        if (cVar1 != '\0') {
          pcVar10 = s_Null_character_in_string_004f2b18;
          pcVar11 = local_e4;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar11 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar11 = pcVar11 + 1;
          }
          FUN_0040b5e0(uVar7);
        }
        local_4._0_1_ = 0x10;
        FUN_00464530(uVar4,local_e8,local_fc,0x56);
        local_4 = CONCAT31(local_4._1_3_,0xf);
        FUN_0040b4f0(1);
        local_4 = 0xffffffff;
        if (local_f8 != (char *)0x0) {
          cVar1 = local_f8[-1];
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150(local_f8 + -1);
          }
          else {
            local_f8[-1] = cVar1 + -1;
          }
        }
        uVar4 = 0x20;
        local_f8 = (char *)0x0;
        local_f4 = 0;
        local_f0 = 0;
        FUN_00463b20(0x20);
        uVar4 = FUN_0045ac50(uVar4);
        FUN_00459990(uVar4);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x98));
    }
    FUN_00412870(param_2,0,0xffffffff);
  }
  ExceptionList = local_c;
  return;
}

