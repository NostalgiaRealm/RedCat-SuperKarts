/*
 * FUN_0041a5d0 at 0041a5d0
 * undefined FUN_0041a5d0(void)
 * Address ranges: 0041a5d0-0041a7ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a5d0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *local_48;
  undefined1 local_3c [4];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c [16];
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccf80;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  local_4 = 0;
  FUN_0041a520();
  do {
    do {
      iVar2 = FUN_004b3830(0x43);
    } while (iVar2 != 0);
    iVar2 = FUN_004b3830(0x11);
  } while ((iVar2 != 0) || (iVar2 = FUN_004b3830(0x20), iVar2 != 0));
  iVar2 = FUN_00419370(8);
  while (1 < iVar2) {
    switch(iVar2) {
    case 2:
      FUN_0041a200();
      break;
    case 3:
      FUN_00419550();
      break;
    case 4:
      FUN_00419c00();
      break;
    case 5:
      FUN_00419e30();
      break;
    case 6:
      FUN_00419f80();
    }
    FUN_0041a520();
    iVar2 = FUN_00419370(8);
  }
  if (iVar2 == 0) {
    uVar3 = FUN_004314a0(local_1c,DAT_0053b9f4);
    local_4._0_1_ = 1;
    uVar3 = FUN_00412710(local_3c,&DAT_004e21f4,uVar3);
    local_4._0_1_ = 2;
    uVar3 = FUN_0041b630(local_2c,uVar3,&DAT_004e21ec);
    local_4._0_1_ = 3;
    FUN_00412870(uVar3,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_0040b4f0(1);
    if (local_38 != 0) {
      cVar1 = *(char *)(local_38 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_38 + -1));
      }
      else {
        *(char *)(local_38 + -1) = cVar1 + -1;
      }
    }
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_4 = local_4 & 0xffffff00;
    if (local_18 != 0) {
      cVar1 = *(char *)(local_18 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_18 + -1));
      }
      else {
        *(char *)(local_18 + -1) = cVar1 + -1;
      }
    }
    puVar4 = local_48;
    if (local_48 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    iVar2 = FUN_004bf445(puVar4,&DAT_004e21fc);
    if (iVar2 == 0) {
      puVar4 = local_48;
      if (local_48 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      FUN_004afee0(s___s___d_Could_not_save__s_file_004e2224,
                   s_D__work_rcsk_Code_game_car_twk_c_004e2200,0x300,puVar4);
    }
    FUN_004bf31b(&DAT_00505b60,0xac,0x14,iVar2);
    FUN_004bf2c5(iVar2);
  }
  if (local_48 != (undefined1 *)0x0) {
    cVar1 = local_48[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      local_48[-1] = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150(local_48 + -1);
  }
  ExceptionList = local_c;
  return;
}

