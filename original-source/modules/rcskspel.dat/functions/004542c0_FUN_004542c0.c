/*
 * FUN_004542c0 at 004542c0
 * undefined FUN_004542c0(void)
 * Address ranges: 004542c0-00454507
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_004542c0(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdd96;
  local_c = ExceptionList;
  local_1c[0] = (undefined1)param_2;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  local_4 = 0;
  switch(param_2) {
  case 1:
    uVar2 = 0xffffffff;
    pcVar4 = s_GOT_ROCKET_004f1e8c;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 == '\0') goto LAB_00454496;
    pcVar4 = s_GOT_ROCKET_004f1e8c;
    break;
  case 2:
    uVar2 = 0xffffffff;
    pcVar4 = s_GOT_SOAP_004f1e98;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 == '\0') goto LAB_00454496;
    pcVar4 = s_GOT_SOAP_004f1e98;
    break;
  case 3:
    uVar2 = 0xffffffff;
    pcVar4 = &DAT_004f1e7c;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 == '\0') goto LAB_00454496;
    pcVar4 = &DAT_004f1e7c;
    break;
  case 4:
    uVar2 = 0xffffffff;
    pcVar4 = s_GOT_GUM_004f1e84;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 == '\0') goto LAB_00454496;
    pcVar4 = s_GOT_GUM_004f1e84;
    break;
  case 5:
    uVar2 = 0xffffffff;
    pcVar4 = s_GOT_TURBO_004f1e70;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 == '\0') goto LAB_00454496;
    pcVar4 = s_GOT_TURBO_004f1e70;
    pcVar5 = local_18;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
    goto LAB_00454389;
  case 6:
    uVar2 = 0xffffffff;
    pcVar4 = (char *)&DAT_004f1e64;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 == '\0') goto LAB_00454496;
    pcVar4 = (char *)&DAT_004f1e64;
    pcVar5 = local_18;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
LAB_00454389:
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    FUN_0040b5e0(uVar2);
    goto LAB_00454496;
  default:
    uVar2 = 0xffffffff;
    pcVar4 = s_GOT_BONUS_004f1ea4;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 == '\0') goto LAB_00454496;
    pcVar4 = s_GOT_BONUS_004f1ea4;
  }
  pcVar5 = local_18;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  local_18[uVar2] = '\0';
  local_14 = uVar2;
LAB_00454496:
  *param_1 = local_1c[0];
  FUN_0040b4f0(0);
  FUN_00412870(local_1c,0,0xffffffff);
  if (local_18 != (char *)0x0) {
    cVar1 = local_18[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      local_18[-1] = cVar1 + -1;
      ExceptionList = local_c;
      return param_1;
    }
    FUN_004bc150(local_18 + -1);
  }
  ExceptionList = local_c;
  return param_1;
}

