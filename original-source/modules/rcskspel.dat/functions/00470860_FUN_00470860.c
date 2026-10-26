/*
 * FUN_00470860 at 00470860
 * undefined FUN_00470860(void)
 * Address ranges: 00470860-00470a60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00470860(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined1 local_a4 [4];
  undefined4 *local_a0;
  uint local_9c;
  undefined1 local_94 [4];
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 local_84 [4];
  undefined1 *local_80;
  undefined1 local_74 [52];
  undefined1 local_40 [52];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d082a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00470560();
  if (iVar2 != 2) {
    FUN_004b2400(param_1 + 0x1b0,0,0x100);
    FUN_00470610(local_84,0);
    local_4 = 0;
    FUN_004b1d60(s_SndGfx_ini_004f65d0);
    puVar3 = local_80;
    if (local_80 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004b1f10(s_STOPPEN_004f65dc,puVar3,local_74,0x31);
    FUN_004b1f60(local_74,&DAT_004f65e4);
    FUN_004b2110(0,local_40,0x31);
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar8 = (char *)&DAT_004f65e8;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5 - 1;
    cVar1 = FUN_0040b600(uVar5,1);
    if (cVar1 != '\0') {
      puVar7 = &DAT_004f65e8;
      puVar9 = local_a0;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      *(undefined1 *)((int)local_a0 + uVar5) = 0;
      local_9c = uVar5;
    }
    local_4._0_1_ = 1;
    uVar4 = FUN_00412710(local_94,local_40,local_a4);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_00412870(uVar4,0,0xffffffff);
    if (local_90 != 0) {
      cVar1 = *(char *)(local_90 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_90 + -1));
      }
      else {
        *(char *)(local_90 + -1) = cVar1 + -1;
      }
    }
    local_90 = 0;
    local_8c = 0;
    local_88 = 0;
    local_4 = local_4 & 0xffffff00;
    if (local_a0 != (undefined4 *)0x0) {
      cVar1 = *(char *)((int)local_a0 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)((int)local_a0 + -1));
      }
      else {
        *(char *)((int)local_a0 + -1) = cVar1 + -1;
      }
    }
    puVar3 = local_80;
    if (local_80 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004b2870(2,puVar3,7);
    if (local_80 != (undefined1 *)0x0) {
      cVar1 = local_80[-1];
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        local_80[-1] = cVar1 + -1;
        ExceptionList = local_c;
        return;
      }
      FUN_004bc150(local_80 + -1);
    }
  }
  ExceptionList = local_c;
  return;
}

