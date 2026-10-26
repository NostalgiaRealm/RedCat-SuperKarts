/*
 * FUN_00437260 at 00437260
 * undefined FUN_00437260(void)
 * Address ranges: 00437260-00437543
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00437260(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint local_a0;
  undefined1 local_98 [4];
  undefined1 *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  undefined1 local_84 [4];
  undefined1 *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74 [4];
  undefined1 *local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_20;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd3b3;
  local_c = ExceptionList;
  puVar2 = *(undefined1 **)(param_3 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  ExceptionList = &local_c;
  local_88 = param_1;
  uVar3 = FUN_004b1ed0(puVar2,s_COUNT_004ebff0);
  iVar4 = FUN_00436680(param_2);
  iVar7 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_4 = 0;
  FUN_00439490(iVar4 + 4);
  *(undefined4 *)(iVar7 + 0x34 + param_2 * 0x44) = *(undefined4 *)(iVar4 + 0x34);
  FUN_00438fb0(iVar4 + 0x38);
  *(undefined4 *)(iVar7 + 0x40 + param_2 * 0x44) = *(undefined4 *)(iVar4 + 0x40);
  local_4 = 1;
  FUN_00439230();
  local_4 = 0xffffffff;
  while (local_20 != 0) {
    FUN_00438b80();
  }
  local_a0 = 0;
  if (uVar3 != 0) {
    do {
      FUN_004314a0(local_84,local_a0);
      local_4 = 2;
      FUN_00431390(local_98,param_3,local_84);
      local_4._0_1_ = 3;
      FUN_00431390(local_74,param_3,local_98);
      local_4._0_1_ = 4;
      puVar2 = &DAT_004d2404;
      if (local_70 != (undefined1 *)0x0) {
        puVar2 = local_70;
      }
      puVar9 = local_94;
      if (local_94 == (undefined1 *)0x0) {
        puVar9 = &DAT_004d2404;
      }
      puVar8 = local_80;
      if (local_80 == (undefined1 *)0x0) {
        puVar8 = &DAT_004d2404;
      }
      puVar5 = *(undefined1 **)(param_3 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      FUN_004afce0(s_Voice__d___s___adding__s___s___s_004ebff8,param_2,puVar5,puVar8,puVar9,puVar2);
      puVar2 = local_70;
      if (local_70 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      uVar6 = FUN_0049de80(puVar2);
      uVar6 = FUN_00436470(local_98,uVar6);
      local_4 = CONCAT31(local_4._1_3_,5);
      iVar7 = FUN_00436730();
      FUN_00439c70(*(undefined4 *)(*(int *)(iVar7 + 4) + 8),1,uVar6);
      if (local_60 != 0) {
        cVar1 = *(char *)(local_60 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_60 + -1));
        }
        else {
          *(char *)(local_60 + -1) = cVar1 + -1;
        }
      }
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      if (local_70 != (undefined1 *)0x0) {
        cVar1 = local_70[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_70 + -1);
        }
        else {
          local_70[-1] = cVar1 + -1;
        }
      }
      local_70 = (undefined1 *)0x0;
      local_6c = 0;
      local_68 = 0;
      if (local_94 != (undefined1 *)0x0) {
        cVar1 = local_94[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_94 + -1);
        }
        else {
          local_94[-1] = cVar1 + -1;
        }
      }
      local_94 = (undefined1 *)0x0;
      local_90 = 0;
      local_8c = 0;
      local_4 = 0xffffffff;
      if (local_80 != (undefined1 *)0x0) {
        cVar1 = local_80[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_80 + -1);
        }
        else {
          local_80[-1] = cVar1 + -1;
        }
      }
      local_a0 = local_a0 + 1;
      local_80 = (undefined1 *)0x0;
      local_7c = 0;
      local_78 = 0;
    } while (local_a0 < uVar3);
  }
  ExceptionList = local_c;
  return;
}

