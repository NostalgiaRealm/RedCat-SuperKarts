/*
 * FUN_0041b350 at 0041b350
 * undefined FUN_0041b350(void)
 * Address ranges: 0041b350-0041b5bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b350(void)

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
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccfaa;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  local_4 = 0;
  FUN_0041b240();
  do {
    do {
      iVar2 = FUN_004b3830(0x52);
    } while (iVar2 != 0);
    iVar2 = FUN_004b3830(0x11);
  } while ((iVar2 != 0) || (iVar2 = FUN_004b3830(0x20), iVar2 != 0));
  iVar2 = FUN_00419370(0xd);
  while (iVar2 < 0xd) {
    switch(iVar2) {
    case 0:
      FUN_0041a810();
      break;
    case 1:
      FUN_0041a8e0();
      break;
    case 2:
      FUN_0041a920();
      break;
    case 3:
      FUN_0041a960();
      break;
    case 4:
      FUN_0041a9a0();
      break;
    case 5:
      FUN_0041a9e0();
      break;
    case 6:
      FUN_0041ab40();
      break;
    case 7:
      FUN_0041aec0();
      break;
    case 8:
      FUN_0041b070();
      break;
    case 9:
      FUN_0041b0a0();
      break;
    case 10:
      FUN_0041b120();
      break;
    case 0xb:
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      ExceptionList = local_c;
      return;
    case 0xc:
      uVar3 = FUN_004314a0(local_3c,DAT_0053b9f4);
      local_4._0_1_ = 1;
      uVar3 = FUN_00412710(local_1c,&DAT_004e2688,uVar3);
      local_4._0_1_ = 2;
      uVar3 = FUN_0041b630(local_2c,uVar3,&DAT_004e2680);
      local_4._0_1_ = 3;
      FUN_00412870(uVar3,0,0xffffffff);
      local_4._0_1_ = 2;
      FUN_0040b4f0(1);
      local_4._0_1_ = 1;
      FUN_0040b4f0(1);
      local_4 = (uint)local_4._1_3_ << 8;
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
      puVar4 = local_48;
      if (local_48 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      iVar2 = FUN_004bf445(puVar4,&DAT_004e2690);
      if (iVar2 == 0) {
        puVar4 = local_48;
        if (local_48 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        FUN_004afee0(s___s___d_Could_not_save__s_file_004e26b8,
                     s_D__work_rcsk_Code_game_car_twk_c_004e2694,0x512,puVar4);
      }
      FUN_004bf31b(&DAT_005068d0,0x7c,0x14,iVar2);
      FUN_004bf2c5(iVar2);
      if (local_48 == (undefined1 *)0x0) {
        ExceptionList = local_c;
        return;
      }
      cVar1 = local_48[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) goto LAB_0041b5a4;
      goto LAB_0041b449;
    }
    FUN_0041b240();
    iVar2 = FUN_00419370(0xd);
  }
  if (local_48 != (undefined1 *)0x0) {
    cVar1 = local_48[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
LAB_0041b449:
      local_48[-1] = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
LAB_0041b5a4:
    FUN_004bc150(local_48 + -1);
  }
  ExceptionList = local_c;
  return;
}

