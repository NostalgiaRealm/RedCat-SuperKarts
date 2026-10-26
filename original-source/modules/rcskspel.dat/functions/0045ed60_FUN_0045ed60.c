/*
 * FUN_0045ed60 at 0045ed60
 * undefined FUN_0045ed60(void)
 * Address ranges: 0045ed60-0045f35b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045ed60(float param_1,float param_2,float param_3,float param_4,int param_5)

{
  int iVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  undefined2 local_254;
  undefined2 local_252;
  undefined2 local_250;
  undefined2 local_24e;
  undefined2 local_24c;
  undefined2 local_24a;
  float local_248;
  undefined1 local_244 [16];
  undefined1 local_234 [16];
  undefined1 local_224 [16];
  undefined1 local_214 [16];
  undefined1 local_204 [16];
  undefined1 local_1f4 [16];
  float local_1e4;
  float local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d4;
  undefined4 local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  float local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b4;
  undefined4 local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  undefined4 local_19c;
  undefined4 local_194;
  undefined4 local_190;
  float local_18c;
  float local_188;
  float local_184;
  float local_180;
  undefined4 local_17c;
  undefined4 local_174;
  undefined4 local_170;
  float local_16c;
  float local_168;
  undefined1 local_164 [28];
  undefined1 local_148 [28];
  undefined1 local_12c [16];
  undefined1 local_11c [16];
  undefined1 local_10c [16];
  undefined1 local_fc [16];
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
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
  puStack_8 = &LAB_004cece0;
  local_c = ExceptionList;
  puVar3 = *(undefined1 **)(param_5 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  ExceptionList = &local_c;
  iVar4 = FUN_004a6060(puVar3);
  if (iVar4 != -1) {
    iVar1 = DAT_006a5e80 + iVar4 * 0x48;
    if ((*(int *)(DAT_006a5e80 + 0x24 + iVar4 * 0x48) != 0) && (*(int *)(iVar1 + 0x28) != 0)) {
      local_1e4 = param_3 * -0.5;
      local_1dc = 0;
      local_1e0 = param_4 * 0.5;
      local_1cc = param_1 / (float)*(int *)(iVar1 + 0x24);
      local_1d0 = 0;
      local_1d4 = 0xffffffff;
      local_1bc = 0;
      local_1c8 = param_2 / (float)*(int *)(iVar1 + 0x28);
      local_1c4 = param_3 * 0.5;
      local_1ac = (param_1 + param_3) / (float)*(int *)(iVar1 + 0x24);
      local_1b0 = 0;
      local_1b4 = 0xffffffff;
      local_19c = 0;
      local_1a8 = param_2 / (float)*(int *)(iVar1 + 0x28);
      local_248 = param_4 * -0.5;
      local_18c = (param_1 + param_3) / (float)*(int *)(iVar1 + 0x24);
      local_190 = 0;
      local_194 = 0xffffffff;
      local_17c = 0;
      local_188 = (param_2 + param_4) / (float)*(int *)(iVar1 + 0x28);
      local_16c = param_1 / (float)*(int *)(iVar1 + 0x24);
      local_174 = 0xffffffff;
      local_250 = 2;
      local_24c = 2;
      local_168 = (param_2 + param_4) / (float)*(int *)(iVar1 + 0x28);
      local_170 = 0;
      local_254 = 0;
      local_252 = 1;
      local_24e = 0;
      local_24a = 3;
      local_1c0 = local_1e0;
      local_1a4 = local_1c4;
      local_1a0 = local_248;
      local_184 = local_1e4;
      local_180 = local_248;
      uVar5 = FUN_004a7a40(&local_1e4,4,&local_254,6);
      iVar4 = FUN_0049f8d0(uVar5,iVar4,FUN_004a0610);
      *(undefined4 *)(iVar4 * 0xa9 + 0xa5 + DAT_006a5c38) = 1;
      *(undefined1 *)(iVar4 * 0xa9 + 0x90 + DAT_006a5c38) = 1;
      ExceptionList = local_c;
      return;
    }
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar8 = &DAT_004f3610;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    FUN_0040b540(&DAT_004f3610,~uVar7 - 1);
    local_4 = 0xc;
    uVar5 = FUN_00463d20(local_6c,0x389);
    local_4._0_1_ = 0xd;
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar8 = s_D__work_rcsk_Code_game_Hud_IniFi_004f3618;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f3618,~uVar7 - 1);
    local_4._0_1_ = 0xe;
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar8 = s_HeadUp_Display_exception_in__004f3644;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    FUN_0040b540(s_HeadUp_Display_exception_in__004f3644,~uVar7 - 1);
    local_4._0_1_ = 0xf;
    uVar6 = FUN_00459040(local_ac,local_234,local_1f4);
    local_4._0_1_ = 0x10;
    uVar6 = FUN_0041b630(local_2c,uVar6,&DAT_004f3614);
    local_4._0_1_ = 0x11;
    uVar5 = FUN_00459040(local_11c,uVar6,uVar5);
    local_4._0_1_ = 0x12;
    uVar5 = FUN_00459040(local_fc,uVar5,local_224);
    local_4._0_1_ = 0x13;
    uVar5 = FUN_0041b630(local_dc,uVar5,s_Texture_004f3604);
    local_4._0_1_ = 0x14;
    uVar5 = FUN_00459040(local_bc,uVar5,param_5);
    local_4._0_1_ = 0x15;
    uVar5 = FUN_0041b630(local_9c,uVar5,s_width___height_is_0_004f35ec);
    local_4._0_1_ = 0x16;
    uVar5 = FUN_0041b630(local_7c,uVar5,&DAT_004f35e8);
    local_4 = CONCAT31(local_4._1_3_,0x17);
    FUN_00459dc0(uVar5);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_148,&DAT_004d6580);
  }
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = &DAT_004f3594;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(&DAT_004f3594,~uVar7 - 1);
  local_4 = 0;
  uVar5 = FUN_00463d20(local_8c,900);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Hud_IniFi_004f359c;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f359c,~uVar7 - 1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f35c8;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f35c8,~uVar7 - 1);
  local_4._0_1_ = 3;
  uVar6 = FUN_00459040(local_5c,local_214,local_204);
  local_4._0_1_ = 4;
  uVar6 = FUN_0041b630(local_3c,uVar6,&DAT_004f3598);
  local_4._0_1_ = 5;
  uVar5 = FUN_00459040(local_1c,uVar6,uVar5);
  local_4._0_1_ = 6;
  uVar5 = FUN_00459040(local_10c,uVar5,local_244);
  local_4._0_1_ = 7;
  uVar5 = FUN_0041b630(local_12c,uVar5,s_Invalid_texture_name_004f357c);
  local_4._0_1_ = 8;
  uVar5 = FUN_00459040(local_ec,uVar5,param_5);
  local_4._0_1_ = 9;
  uVar5 = FUN_0041b630(local_4c,uVar5,s_in_ini_file_004f356c);
  local_4._0_1_ = 10;
  uVar5 = FUN_0041b630(local_cc,uVar5,&DAT_004f3568);
  local_4 = CONCAT31(local_4._1_3_,0xb);
  FUN_00459dc0(uVar5);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_164,&DAT_004d6580);
}

