/*
 * FUN_004319f0 at 004319f0
 * undefined FUN_004319f0(void)
 * Address ranges: 004319f0-00431f7e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004319f0(void)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined1 auStack_80 [3];
  undefined1 local_7d;
  int local_7c;
  undefined4 *local_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [4];
  undefined1 *puStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [4];
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 *local_4c;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [4];
  int iStack_1c;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd1a0;
  pvStack_c = ExceptionList;
  local_4c = (undefined1 *)CONCAT31(local_4c._1_3_,local_7d);
  ExceptionList = &pvStack_c;
  FUN_0040b4f0(0);
  local_4 = 0;
  if (DAT_0053ba08 == 0) {
    if (DAT_0053ba70 == 1) {
      uVar10 = 0;
      iVar3 = DAT_0053b9cc - DAT_0053be60;
      goto LAB_00431aad;
    }
  }
  else if (DAT_0053ba70 != 1) {
    uVar10 = 0;
    iVar3 = DAT_0053b9cc - DAT_0053be60;
    goto LAB_00431aad;
  }
  uVar10 = 1;
  iVar3 = DAT_0053b9cc - DAT_0053be60;
LAB_00431aad:
  DAT_0053be28 = FUN_00415f90(DAT_0053be2c,iVar3,4,uVar10,1,FUN_004325b0,FUN_00434c40,1,0xffffffff);
  puVar1 = (uint *)(DAT_0053be28 * 0xd0 + 4 + DAT_0067ee20);
  *puVar1 = *puVar1 | 3;
  *(code **)(DAT_0053be28 * 0xd0 + 0x58 + DAT_0067ee20) = FUN_00416650;
  uVar10 = DAT_0053be2c;
  if (DAT_0053be08 != 0) {
    uVar10 = 0;
  }
  FUN_0041b760(uVar10,DAT_0053be28);
  iVar3 = FUN_004906b0(4);
  local_7c = CONCAT31(local_7c._1_3_,local_7d);
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar9 = (char *)&DAT_004eb2d4;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  uVar7 = ~uVar7 - 1;
  cVar2 = FUN_0040b600(uVar7,1);
  if (cVar2 != '\0') {
    puVar4 = &DAT_004eb2d4;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *local_78 = *puVar4;
      puVar4 = puVar4 + 1;
      local_78 = local_78 + 1;
    }
    for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)local_78 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      local_78 = (undefined4 *)((int)local_78 + 1);
    }
    FUN_0040b5e0(uVar7);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar4 = (undefined4 *)FUN_0044a700(DAT_00508610);
  (**(code **)*puVar4)(&local_7c);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  FUN_0040b4f0(1);
  FUN_0044a6e0(DAT_00508610,DAT_0053be28);
  FUN_004a09e0();
  iVar5 = FUN_004b3830(0x47);
  if (iVar5 != 0) {
    *(undefined4 *)(DAT_006a5c38 + 0xa5 + iVar3 * 0xa9) = 2;
  }
  *(undefined4 *)(DAT_0053be28 * 0xd0 + 0x50 + DAT_0067ee20) = 1;
  iVar3 = *(int *)(DAT_0053be28 * 0xd0 + 0x24 + DAT_0067ee20);
  FUN_004afce0(s_cur___d__next___d_004eb2dc,iVar3,
               *(undefined4 *)(iVar3 * 0x50 + 0x14 + DAT_00680ae0));
  FUN_00493110(DAT_0053be28);
  _DAT_0053bd70 = 0x41f00000;
  DAT_0053bd74 = 0x41a00000;
  _DAT_0053be6c = 0;
  FUN_00436420();
  uVar10 = FUN_004314a0(auStack_30,DAT_0053b9f4);
  puStack_8._0_1_ = 2;
  uVar10 = FUN_00412710(auStack_40,&DAT_004eb2f8,uVar10);
  puStack_8._0_1_ = 3;
  FUN_0041b630(auStack_70,uVar10,&DAT_004eb2f0);
  puStack_8._0_1_ = 6;
  FUN_0040b4f0(1);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,5);
  FUN_0040b4f0(1);
  puVar6 = puStack_6c;
  if (puStack_6c == (undefined1 *)0x0) {
    puVar6 = &DAT_004d2404;
  }
  iVar3 = FUN_004bf445(puVar6,&DAT_004eb300);
  if (iVar3 == 0) {
    puVar6 = puStack_6c;
    if (puStack_6c == (undefined1 *)0x0) {
      puVar6 = &DAT_004d2404;
    }
    FUN_004afee0(s___s___d_Could_not_save__s_file_004eb328,
                 s_D__work_rcsk_Code_game_plr_car_c_004eb304,0xe8,puVar6);
    FUN_004afee0(s__init_player_car___s__d____Could_004eb36c,
                 s_D__work_rcsk_Code_game_plr_car_c_004eb348,0xf2);
  }
  else {
    FUN_004bf930(&DAT_005068d0,0x7c,0x14,iVar3);
    FUN_004bf2c5(iVar3);
  }
  iVar3 = FUN_0042abc0();
  if (iVar3 == 3) {
    FUN_004350d0();
  }
  uVar10 = FUN_004314a0(auStack_20,DAT_0053b9f4);
  puStack_8._0_1_ = 7;
  uVar10 = FUN_00412710(auStack_60,&DAT_004eb3ac,uVar10);
  puStack_8._0_1_ = 8;
  uVar10 = FUN_0041b630(auStack_80,uVar10,&DAT_004eb3a4);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,9);
  FUN_00412870(uVar10,0,0xffffffff);
  if (local_7c != 0) {
    cVar2 = *(char *)(local_7c + -1);
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_004bc150((char *)(local_7c + -1));
    }
    else {
      *(char *)(local_7c + -1) = cVar2 + -1;
    }
  }
  local_7c = 0;
  local_78 = (undefined4 *)0x0;
  uStack_74 = 0;
  if (iStack_5c != 0) {
    cVar2 = *(char *)(iStack_5c + -1);
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_004bc150((char *)(iStack_5c + -1));
    }
    else {
      *(char *)(iStack_5c + -1) = cVar2 + -1;
    }
  }
  iStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,5);
  if (iStack_1c != 0) {
    cVar2 = *(char *)(iStack_1c + -1);
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_004bc150((char *)(iStack_1c + -1));
    }
    else {
      *(char *)(iStack_1c + -1) = cVar2 + -1;
    }
  }
  puVar6 = local_4c;
  if (local_4c == (undefined1 *)0x0) {
    puVar6 = &DAT_004d2404;
  }
  iVar3 = FUN_004bf445(puVar6,&DAT_004eb3b4);
  if (iVar3 == 0) {
    FUN_004afee0(s___s___d_Could_not_open_file_PHYS_004eb3dc,
                 s_D__work_rcsk_Code_game_plr_car_c_004eb3b8,0x108);
  }
  else {
    FUN_004bf930(&DAT_00505b60,0xac,0x14,iVar3);
    FUN_004bf2c5(iVar3);
  }
  DAT_0053bef0 = 0;
  DAT_0053bef4 = 0;
  DAT_0053bef8 = 0;
  _DAT_0053befc = 0;
  DAT_0053bf00 = 0;
  _DAT_0053bf04 = 0;
  FUN_00434360();
  FUN_004343a0();
  FUN_00431f80();
  FUN_004319e0();
  if (puStack_6c != (undefined1 *)0x0) {
    cVar2 = puStack_6c[-1];
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_004bc150(puStack_6c + -1);
    }
    else {
      puStack_6c[-1] = cVar2 + -1;
    }
  }
  puStack_6c = (undefined1 *)0x0;
  uStack_68 = 0;
  uStack_64 = 0;
  if (local_4c != (undefined1 *)0x0) {
    cVar2 = local_4c[-1];
    if ((cVar2 != '\0') && (cVar2 != -1)) {
      local_4c[-1] = cVar2 + -1;
      ExceptionList = pvStack_10;
      return;
    }
    FUN_004bc150(local_4c + -1);
  }
  ExceptionList = pvStack_10;
  return;
}

