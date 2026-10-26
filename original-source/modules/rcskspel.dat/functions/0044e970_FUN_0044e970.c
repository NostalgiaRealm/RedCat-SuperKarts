/*
 * FUN_0044e970 at 0044e970
 * undefined FUN_0044e970(void)
 * Address ranges: 0044e970-0044eb39
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_0044e970(undefined4 *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 local_15;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cda9c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined1 *)(param_1 + 8) = local_15;
  FUN_0040b4f0(0);
  *(undefined1 *)(param_1 + 0xc) = local_15;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  *(undefined1 *)(param_1 + 0x10) = local_15;
  FUN_0040b4f0(0);
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x14) = local_15;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  uVar3 = 0xffffffff;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  pcVar6 = (char *)&DAT_00543d00;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  local_4 = CONCAT31(local_4._1_3_,3);
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    puVar5 = &DAT_00543d00;
    puVar7 = (undefined4 *)param_1[9];
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    param_1[10] = uVar3;
    *(undefined1 *)(uVar3 + param_1[9]) = 0;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &DAT_00543d04;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    puVar5 = (undefined4 *)&DAT_00543d04;
    puVar7 = (undefined4 *)param_1[0xd];
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    param_1[0xe] = uVar3;
    *(undefined1 *)(uVar3 + param_1[0xd]) = 0;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &DAT_00543d08;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  uVar4 = ~uVar3 - 1;
  uVar3 = FUN_00412a70();
  if (uVar3 < uVar4) {
    FUN_004bc15b();
  }
  iVar1 = param_1[0x11];
  if (((iVar1 == 0) || (cVar2 = *(char *)(iVar1 + -1), cVar2 == '\0')) || (cVar2 == -1)) {
    if (uVar4 == 0) {
      FUN_0040b4f0(1);
      ExceptionList = pvStack_c;
      return param_1;
    }
    if (((uint)param_1[0x13] < 0x20) && (uVar4 <= (uint)param_1[0x13])) goto LAB_0044eb03;
    FUN_0040b4f0(1);
  }
  else if (uVar4 == 0) {
    *(char *)(iVar1 + -1) = cVar2 + -1;
    FUN_0040b4f0(0);
    ExceptionList = pvStack_c;
    return param_1;
  }
  FUN_0040b720(uVar4);
LAB_0044eb03:
  puVar5 = (undefined4 *)&DAT_00543d08;
  puVar7 = (undefined4 *)param_1[0x11];
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  param_1[0x12] = uVar4;
  *(undefined1 *)(uVar4 + param_1[0x11]) = 0;
  ExceptionList = pvStack_c;
  return param_1;
}

