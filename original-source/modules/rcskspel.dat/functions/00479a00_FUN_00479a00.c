/*
 * FUN_00479a00 at 00479a00
 * undefined FUN_00479a00(void)
 * Address ranges: 00479a00-00479b40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00479a00(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544ec8 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f7e8c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544ecc = (undefined4 *)0x0;
  _DAT_00544ed0 = 0;
  _DAT_00544ed4 = 0;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = &DAT_004f7e8c;
    puVar6 = DAT_00544ecc;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    _DAT_00544ed0 = uVar2;
    *(undefined1 *)((int)DAT_00544ecc + uVar2) = 0;
  }
  DAT_00544ed8 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_004f7e98;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544edc = (undefined4 *)0x0;
  _DAT_00544ee0 = 0;
  _DAT_00544ee4 = 0;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)&DAT_004f7e98;
    puVar6 = DAT_00544edc;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    _DAT_00544ee0 = uVar2;
    *(undefined1 *)((int)DAT_00544edc + uVar2) = 0;
  }
  DAT_00544ee8 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_004f7ea4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544eec = (undefined4 *)0x0;
  _DAT_00544ef0 = 0;
  _DAT_00544ef4 = 0;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)&DAT_004f7ea4;
    puVar6 = DAT_00544eec;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    _DAT_00544ef0 = uVar2;
    *(undefined1 *)((int)DAT_00544eec + uVar2) = 0;
  }
  return;
}

