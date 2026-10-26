/*
 * FUN_0042d480 at 0042d480
 * undefined FUN_0042d480(void)
 * Address ranges: 0042d480-0042d7c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d480(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined1 local_110 [4];
  char *local_10c;
  undefined1 local_100 [4];
  undefined1 *local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined1 local_f0 [12];
  undefined1 local_e4 [16];
  char local_d4 [100];
  undefined1 local_70 [100];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd067;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  local_4 = 0;
  FUN_0040b4f0(0);
  local_4._0_1_ = 1;
  FUN_004b1d60(s_SndGfx_ini_004ea69c);
  FUN_004bea92(local_70,s_mesh_d_004ea6a8,DAT_0053b9b4);
  FUN_004afce0(local_70);
  FUN_004b1f10(&PTR_DAT_004ea6b0,local_70,local_d4,100);
  uVar5 = 0xffffffff;
  pcVar4 = local_d4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(local_d4,~uVar5 - 1);
  uVar2 = FUN_0041b630(local_e4,local_100,&DAT_004ea6b4);
  local_4._0_1_ = 2;
  FUN_00412870(uVar2,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0040b4f0(1);
  puVar3 = local_fc;
  if (local_fc == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  DAT_0050912c = FUN_004a7680(2,puVar3);
  if (DAT_0053b9f0 == 0) {
    FUN_004bea92(local_f0,&DAT_004ea6d0,DAT_0053b9b4);
    FUN_004b1f10(&PTR_DAT_004ea6d4,local_f0,local_d4,100);
    uVar5 = 0xffffffff;
    pcVar4 = local_d4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5 - 1;
    cVar1 = FUN_0040b600(uVar5,1);
    if (cVar1 != '\0') {
      pcVar4 = local_d4;
      pcVar7 = local_10c;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar7 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_0040b5e0(uVar5);
    }
    uVar2 = FUN_0041b630(local_e4,local_110,&DAT_004ea6d8);
    local_4._0_1_ = 4;
    FUN_00412870(uVar2,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_0040b4f0(1);
    pcVar4 = local_10c;
    if (local_10c == (char *)0x0) {
      pcVar4 = "";
    }
    uVar8 = 0;
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0042abc0();
    FUN_004bea92(local_f0,&DAT_004ea6bc,uVar2);
    FUN_004b1f10(&PTR_DAT_004ea6c4,local_f0,local_d4,100);
    uVar5 = 0xffffffff;
    pcVar4 = local_d4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5 - 1;
    cVar1 = FUN_0040b600(uVar5,1);
    if (cVar1 != '\0') {
      pcVar4 = local_d4;
      pcVar7 = local_10c;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar7 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_0040b5e0(uVar5);
    }
    uVar2 = FUN_0041b630(local_e4,local_110,&DAT_004ea6c8);
    local_4._0_1_ = 3;
    FUN_00412870(uVar2,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_0040b4f0(1);
    pcVar4 = local_10c;
    if (local_10c == (char *)0x0) {
      pcVar4 = "";
    }
    uVar8 = 1;
    uVar2 = 1;
  }
  DAT_00509128 = FUN_0049b300(pcVar4,uVar2,uVar8);
  if (local_fc != (undefined1 *)0x0) {
    cVar1 = local_fc[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_fc + -1);
    }
    else {
      local_fc[-1] = cVar1 + -1;
    }
  }
  local_fc = (undefined1 *)0x0;
  local_f8 = 0;
  local_f4 = 0;
  if (local_10c != (char *)0x0) {
    cVar1 = local_10c[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      local_10c[-1] = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150(local_10c + -1);
  }
  ExceptionList = local_c;
  return;
}

