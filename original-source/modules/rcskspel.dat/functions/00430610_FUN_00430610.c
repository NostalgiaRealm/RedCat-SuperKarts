/*
 * FUN_00430610 at 00430610
 * undefined FUN_00430610(void)
 * Address ranges: 00430610-00430c40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430610(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined1 local_ac [4];
  char *local_a8;
  uint local_a4;
  undefined1 local_9c [4];
  char *local_98;
  uint local_94;
  undefined1 local_8c [4];
  char *local_88;
  undefined1 local_7c [4];
  char *local_78;
  undefined1 local_6c [4];
  char *local_68;
  undefined1 local_5c [4];
  char *local_58;
  undefined1 local_4c [4];
  char *local_48;
  undefined1 local_3c [4];
  char *local_38;
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd14e;
  local_c = ExceptionList;
  switch(param_1) {
  case 0:
    ExceptionList = &local_c;
    FUN_00469670();
    break;
  case 1:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(6);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)local_38 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        local_38 = local_38 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *local_38 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        local_38 = local_38 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    local_4 = 0;
    FUN_00469000(local_3c,0,0);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    break;
  case 2:
    ExceptionList = &local_c;
    FUN_004690e0();
    break;
  case 3:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(0x19);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)local_68 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        local_68 = local_68 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *local_68 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        local_68 = local_68 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    local_4 = 1;
    FUN_00468f10(local_6c,1,5);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    break;
  case 4:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(0x17);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)local_88 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        local_88 = local_88 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *local_88 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        local_88 = local_88 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    local_4 = 2;
    FUN_00468f10(local_8c,1,4);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    break;
  case 5:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(0x16);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)local_48 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        local_48 = local_48 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *local_48 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        local_48 = local_48 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    local_4 = 3;
    FUN_00468f10(local_4c,4,5);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    uVar2 = FUN_00438520(local_2c);
    uVar8 = 10;
    local_4 = 4;
    FUN_004371f0(10,uVar2);
    FUN_00437b10(uVar8,uVar2);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    break;
  case 6:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(0x11);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)local_78 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        local_78 = local_78 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *local_78 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        local_78 = local_78 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    local_4 = 5;
    FUN_00468f10(local_7c,5,5);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    uVar2 = FUN_00438480(local_1c);
    uVar8 = 10;
    local_4 = 6;
    FUN_004371f0(10,uVar2);
    FUN_00437b10(uVar8,uVar2);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    break;
  case 7:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(0x1c);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)local_58 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        local_58 = local_58 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *local_58 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        local_58 = local_58 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    local_4 = 7;
    FUN_00468f10(local_5c,3,0);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    break;
  case 8:
    ExceptionList = &local_c;
    FUN_00469650();
    break;
  case 9:
    ExceptionList = &local_c;
    FUN_00469660();
    break;
  case 10:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(0x1a);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      pcVar7 = local_a8;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      local_a8[uVar4] = '\0';
      local_a4 = uVar4;
    }
    local_4 = 8;
    FUN_00468f10(local_ac,1,5);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    break;
  case 0xb:
    ExceptionList = &local_c;
    iVar3 = FUN_00443b40(0x1f);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = &DAT_0053d4ec + iVar3 * 0x100;
      pcVar7 = local_98;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      local_98[uVar4] = '\0';
      local_94 = uVar4;
    }
    local_4 = 9;
    FUN_00468f10(local_9c,1,5);
    if (local_98 != (char *)0x0) {
      cVar1 = local_98[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_98 + -1);
      }
      else {
        local_98[-1] = cVar1 + -1;
      }
    }
    break;
  default:
    ExceptionList = &local_c;
    FUN_004afee0(s_Unknown_event__d___s__d__004eb0e4,param_1,
                 s_D__work_rcsk_Code_game_Gm_main_c_004eb0c0,0x4f3);
  }
  ExceptionList = local_c;
  return;
}

