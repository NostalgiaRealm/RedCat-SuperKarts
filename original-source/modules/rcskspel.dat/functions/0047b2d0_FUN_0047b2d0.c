/*
 * FUN_0047b2d0 at 0047b2d0
 * undefined FUN_0047b2d0(void)
 * Address ranges: 0047b2d0-0047b44b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047b2d0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544f50 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_004f807c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  DAT_00544f54 = 0;
  DAT_00544f58 = 0;
  _DAT_00544f5c = 0;
  FUN_0040b540(&DAT_004f807c,~uVar2 - 1);
  DAT_00544f60 = local_1;
  uVar2 = 0xffffffff;
  DAT_00544f64 = 0;
  pcVar5 = &DAT_004f8084;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  DAT_00544f68 = 0;
  _DAT_00544f6c = 0;
  FUN_0040b540(&DAT_004f8084,~uVar2 - 1);
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_004f808c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  DAT_00544f70 = local_1;
  _DAT_00544f74 = 0;
  _DAT_00544f78 = 0;
  _DAT_00544f7c = 0;
  FUN_0040b540(&DAT_004f808c,~uVar2 - 1);
  DAT_00544f80 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f8094;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = &DAT_004f8094;
    puVar6 = DAT_00544f84;
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
    _DAT_00544f88 = uVar2;
    *(undefined1 *)((int)DAT_00544f84 + uVar2) = 0;
  }
  DAT_00544f90 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f809c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = &DAT_004f809c;
    puVar6 = DAT_00544f94;
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
    _DAT_00544f98 = uVar2;
    *(undefined1 *)((int)DAT_00544f94 + uVar2) = 0;
  }
  return;
}

