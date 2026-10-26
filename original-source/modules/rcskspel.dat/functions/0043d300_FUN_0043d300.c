/*
 * FUN_0043d300 at 0043d300
 * undefined FUN_0043d300(void)
 * Address ranges: 0043d300-0043d6e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043d300(int param_1,undefined4 *param_2)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined1 local_4c [4];
  char *local_48;
  undefined1 local_3c [4];
  undefined4 *local_38;
  undefined1 local_2c [4];
  char *local_28;
  undefined1 local_1c [4];
  char *local_18;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd590;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004b1d60(s_Rotobj_ini_004ec394);
  local_4c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_MASSA_004ec3a0;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_MASSA_004ec3a0,~uVar3 - 1);
  local_4 = 0;
  pcVar5 = *(char **)(param_1 + 4);
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  local_3c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar7 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(pcVar5,~uVar3 - 1);
  local_4._0_1_ = 1;
  cVar2 = FUN_00431210(local_3c,local_4c,param_2);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  if (cVar2 == '\0') {
    *param_2 = 0x43c80000;
  }
  local_4c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_SNELHEID_004ec3a8;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_SNELHEID_004ec3a8,~uVar3 - 1);
  local_4 = 2;
  pcVar5 = *(char **)(param_1 + 4);
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  local_3c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar7 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(pcVar5,~uVar3 - 1);
  local_4._0_1_ = 3;
  cVar2 = FUN_00431210(local_3c,local_4c,param_2 + 1);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  if (cVar2 == '\0') {
    param_2[1] = 0;
  }
  local_3c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = (char *)&DAT_004ec3b4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    puVar6 = &DAT_004ec3b4;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_38 = *puVar6;
      puVar6 = puVar6 + 1;
      local_38 = local_38 + 1;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)local_38 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      local_38 = (undefined4 *)((int)local_38 + 1);
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 4;
  pcVar5 = *(char **)(param_1 + 4);
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  local_4c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar7 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)local_48 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      local_48 = local_48 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_48 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      local_48 = local_48 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4._0_1_ = 5;
  cVar2 = FUN_00431210(local_4c,local_3c,param_2 + 2);
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  if (cVar2 == '\0') {
    param_2[2] = 0;
  }
  local_1c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_INERTIA_004ec3bc;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    pcVar5 = s_INERTIA_004ec3bc;
    pcVar7 = local_18;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 6;
  pcVar5 = *(char **)(param_1 + 4);
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  local_2c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar7 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)local_28 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      local_28 = local_28 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_28 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      local_28 = local_28 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4._0_1_ = 7;
  cVar2 = FUN_00431210(local_2c,local_1c,param_2 + 3);
  local_4 = CONCAT31(local_4._1_3_,6);
  FUN_0040b4f0(1);
  if (local_18 != (char *)0x0) {
    cVar1 = local_18[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_18 + -1);
    }
    else {
      local_18[-1] = cVar1 + -1;
    }
  }
  if (cVar2 == '\0') {
    param_2[3] = 0;
  }
  ExceptionList = local_c;
  return;
}

