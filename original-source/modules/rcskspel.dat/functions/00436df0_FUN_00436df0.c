/*
 * FUN_00436df0 at 00436df0
 * undefined FUN_00436df0(void)
 * Address ranges: 00436df0-00436ff6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00436df0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_0053bf10 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = &DAT_004ebe44;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  _DAT_0053bf14 = 0;
  _DAT_0053bf18 = 0;
  _DAT_0053bf1c = 0;
  FUN_0040b540(&DAT_004ebe44,~uVar2 - 1);
  DAT_0053bf20 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_STRAND2_004ebe4c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_STRAND2_004ebe4c;
    pcVar6 = DAT_0053bf24;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    _DAT_0053bf28 = uVar2;
    DAT_0053bf24[uVar2] = '\0';
  }
  DAT_0053bf30 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_STRAND1_004ebe54;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_STRAND1_004ebe54;
    pcVar6 = DAT_0053bf34;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    _DAT_0053bf38 = uVar2;
    DAT_0053bf34[uVar2] = '\0';
  }
  DAT_0053bf40 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_BOSBEAT2_004ebe5c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_BOSBEAT2_004ebe5c;
    pcVar6 = DAT_0053bf44;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    _DAT_0053bf48 = uVar2;
    DAT_0053bf44[uVar2] = '\0';
  }
  DAT_0053bf50 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = (char *)&DAT_004ebe68;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar5 = &DAT_004ebe68;
    puVar7 = DAT_0053bf54;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    FUN_0040b5e0(uVar2);
  }
  DAT_0053bf60 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = &DAT_004ebe70;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004ebe70,~uVar2 - 1);
  return;
}

