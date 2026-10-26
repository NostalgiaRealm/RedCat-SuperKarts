/*
 * FUN_00469b10 at 00469b10
 * undefined FUN_00469b10(void)
 * Address ranges: 00469b10-00469e94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00469b10(int *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_6d;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [12];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cfef2;
  pvStack_c = ExceptionList;
  local_6c = 0;
  ExceptionList = &pvStack_c;
  param_1[3] = 0;
  local_68 = 0x3f800000;
  piVar1 = param_1 + 0x10;
  param_1[4] = 0x3f800000;
  local_64 = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0x3f800000;
  param_1[2] = 2;
  param_1[8] = 0;
  uVar3 = FUN_00412710(&local_6c,s_Portr_004f526c,piVar1);
  local_4 = 0;
  iVar4 = FUN_00461470(uVar3);
  param_1[0xc] = iVar4;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  uVar3 = FUN_00412710(&local_6c,s_Frame_004f5274,piVar1);
  local_4 = 1;
  iVar4 = FUN_00461470(uVar3);
  param_1[0xd] = iVar4;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  uVar3 = FUN_00412710(&local_6c,&DAT_004f527c,piVar1);
  local_4 = 2;
  iVar4 = FUN_00461470(uVar3);
  param_1[0xe] = iVar4;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Portr_004f5284;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Portr_004f5284,~uVar5 - 1);
  local_4 = 3;
  uVar3 = FUN_00412710(local_3c,s_Element_Portr_004f52bc,piVar1);
  local_4._0_1_ = 4;
  uVar3 = FUN_0041b630(local_4c,uVar3,s_not_found_004f52b0);
  local_4._0_1_ = 5;
  FUN_00464530(param_1[0xc],uVar3,&local_6c,0x42);
  local_4._0_1_ = 4;
  FUN_0040b4f0(1);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  local_6c = CONCAT31(local_6c._1_3_,local_6d);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Portr_004f52cc;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Portr_004f52cc,~uVar5 - 1);
  local_4 = 6;
  uVar3 = FUN_00412710(local_4c,s_Element_Frame_004f5304,piVar1);
  local_4._0_1_ = 7;
  uVar3 = FUN_0041b630(local_3c,uVar3,s_not_found_004f52f8);
  local_4._0_1_ = 8;
  FUN_00464530(param_1[0xd],uVar3,&local_6c,0x43);
  local_4._0_1_ = 7;
  FUN_0040b4f0(1);
  local_4 = CONCAT31(local_4._1_3_,6);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Portr_004f5314;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Portr_004f5314,~uVar5 - 1);
  local_4 = 9;
  uVar3 = FUN_00412710(local_1c,s_Element_Back_004f534c,piVar1);
  local_4._0_1_ = 10;
  uVar3 = FUN_0041b630(local_2c,uVar3,s_not_found_004f5340);
  local_4._0_1_ = 0xb;
  FUN_00464530(param_1[0xe],uVar3,local_5c,0x44);
  local_4._0_1_ = 10;
  FUN_0040b4f0(1);
  local_4 = CONCAT31(local_4._1_3_,9);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  (**(code **)(*param_1 + 0x20))(param_1 + 3);
  ExceptionList = pvStack_10;
  return;
}

