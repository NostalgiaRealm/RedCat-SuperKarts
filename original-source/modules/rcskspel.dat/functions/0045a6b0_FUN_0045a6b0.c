/*
 * FUN_0045a6b0 at 0045a6b0
 * undefined FUN_0045a6b0(void)
 * Address ranges: 0045a6b0-0045aa7f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0045a6b0(int param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  float10 fVar8;
  float10 fVar9;
  float *pfVar10;
  int local_120;
  float local_11c [4];
  undefined4 local_10c;
  undefined4 local_108;
  float local_104 [3];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
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
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce23a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00463b20();
  fVar8 = (float10)FUN_0045ae40();
  fVar1 = *(float *)(param_1 + 0x94);
  FUN_00463b20();
  fVar9 = (float10)FUN_0045ae50();
  local_120 = 0;
  fVar1 = (float)(fVar9 * (float10)(float)((float10)fVar1 / fVar8));
  if (0 < *(int *)(param_1 + 0x98)) {
    do {
      iVar3 = FUN_00463b80();
      uVar4 = *(undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + 4) + local_120 * 4);
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2b34;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Fixed_004f2b34,~uVar6 - 1);
      local_4 = 0;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = s_Null_character_in_string_004f2b60;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      FUN_0040b540(s_Null_character_in_string_004f2b60,~uVar6 - 1);
      local_4._0_1_ = 1;
      FUN_00464530(uVar4,local_f8,local_e8,0x6f);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0040b4f0(1);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      iVar3 = FUN_00463b30();
      if (iVar3 == 0) {
        pfVar10 = local_11c + 3;
        local_10c = 0;
        local_108 = 0;
        local_11c[3] = ((float)local_120 + 0.5) * (fVar1 + *(float *)(param_1 + 0x94));
      }
      else if (iVar3 == 1) {
        pfVar10 = local_104;
        local_104[1] = 0.0;
        local_104[2] = 0.0;
        local_104[0] = (fVar1 + *(float *)(param_1 + 0x94)) *
                       ((1.0 - (float)*(int *)(param_1 + 0x98)) * 0.5 + (float)local_120);
      }
      else {
        if (iVar3 != 2) {
          FUN_0040b4f0(0);
          uVar6 = 0xffffffff;
          pcVar7 = &DAT_004f2ba0;
          goto code_r0x0045a8dd;
        }
        pfVar10 = local_11c;
        local_11c[1] = 0.0;
        local_11c[2] = 0.0;
        local_11c[0] = (fVar1 + *(float *)(param_1 + 0x94)) *
                       (((float)local_120 - (float)*(int *)(param_1 + 0x98)) + 0.5);
      }
      FUN_00458400(pfVar10);
      local_120 = local_120 + 1;
    } while (local_120 < *(int *)(param_1 + 0x98));
  }
  ExceptionList = local_c;
  return;
  while( true ) {
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    if (cVar2 == '\0') break;
code_r0x0045a8dd:
    if (uVar6 == 0) break;
  }
  FUN_0040b540(&DAT_004f2ba0,~uVar6 - 1);
  local_4 = 2;
  uVar4 = FUN_00463d20(local_2c,0x7d);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_D__work_rcsk_Code_game_Hud_Fixed_004f2ba8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Fixed_004f2ba8,~uVar6 - 1);
  local_4._0_1_ = 4;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_HeadUp_Display_exception_in__004f2bd4;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f2bd4,~uVar6 - 1);
  local_4._0_1_ = 5;
  uVar5 = FUN_00459040(local_1c,local_d8,local_b8);
  local_4._0_1_ = 6;
  uVar5 = FUN_0041b630(local_6c,uVar5,&DAT_004f2ba4);
  local_4._0_1_ = 7;
  uVar4 = FUN_00459040(local_8c,uVar5,uVar4);
  local_4._0_1_ = 8;
  uVar4 = FUN_00459040(local_4c,uVar4,local_c8);
  local_4._0_1_ = 9;
  uVar4 = FUN_0041b630(local_7c,uVar4,s_Invalid_alignment_in_string_004f2b80);
  local_4._0_1_ = 10;
  uVar5 = FUN_004583c0();
  uVar4 = FUN_00459040(local_5c,uVar4,uVar5);
  local_4._0_1_ = 0xb;
  uVar4 = FUN_0041b630(local_3c,uVar4,&DAT_004f2b7c);
  local_4 = CONCAT31(local_4._1_3_,0xc);
  FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

