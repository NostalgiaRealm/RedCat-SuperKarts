/*
 * FUN_0049f040 at 0049f040
 * undefined FUN_0049f040(void)
 * Address ranges: 0049f040-0049f19e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_0049f040(undefined4 *param_1)

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
  
  puStack_8 = &LAB_004d1716;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined1 *)(param_1 + 6) = local_15;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 10) = local_15;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  uVar3 = 0xffffffff;
  *param_1 = &PTR_FUN_004d3078;
  pcVar6 = &DAT_005437b0;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  local_4 = 1;
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    puVar5 = (undefined4 *)&DAT_005437b0;
    puVar7 = (undefined4 *)param_1[7];
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
    param_1[8] = uVar3;
    *(undefined1 *)(uVar3 + param_1[7]) = 0;
  }
  uVar3 = 0xffffffff;
  pcVar6 = &DAT_005437b0;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  if (0xfffffffd < uVar3) {
    FUN_004bc15b();
  }
  iVar1 = param_1[0xb];
  if (((iVar1 == 0) || (cVar2 = *(char *)(iVar1 + -1), cVar2 == '\0')) || (cVar2 == -1)) {
    if (uVar3 == 0) {
      FUN_0040b4f0(1);
      goto LAB_0049f177;
    }
    if ((0x1f < (uint)param_1[0xd]) || ((uint)param_1[0xd] < uVar3)) {
      FUN_0040b4f0(1);
      goto LAB_0049f147;
    }
  }
  else {
    if (uVar3 == 0) {
      *(char *)(iVar1 + -1) = cVar2 + -1;
      FUN_0040b4f0(0);
      goto LAB_0049f177;
    }
LAB_0049f147:
    FUN_0040b720(uVar3);
  }
  puVar5 = (undefined4 *)&DAT_005437b0;
  puVar7 = (undefined4 *)param_1[0xb];
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
  param_1[0xc] = uVar3;
  *(undefined1 *)(param_1[0xb] + uVar3) = 0;
LAB_0049f177:
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[3] = 0;
  param_1[4] = 100;
  ExceptionList = pvStack_c;
  return param_1;
}

