/*
 * FUN_0047b490 at 0047b490
 * undefined FUN_0047b490(void)
 * Address ranges: 0047b490-0047b60b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047b490(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544f00 = local_1;
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_004f80a4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  DAT_00544f04 = 0;
  DAT_00544f08 = 0;
  _DAT_00544f0c = 0;
  FUN_0040b540(&DAT_004f80a4,~uVar2 - 1);
  DAT_00544f10 = local_1;
  uVar2 = 0xffffffff;
  DAT_00544f14 = 0;
  pcVar5 = &DAT_004f80ac;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  DAT_00544f18 = 0;
  _DAT_00544f1c = 0;
  FUN_0040b540(&DAT_004f80ac,~uVar2 - 1);
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_004f80b4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  DAT_00544f20 = local_1;
  _DAT_00544f24 = 0;
  _DAT_00544f28 = 0;
  _DAT_00544f2c = 0;
  FUN_0040b540(&DAT_004f80b4,~uVar2 - 1);
  DAT_00544f30 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f80bc;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = &DAT_004f80bc;
    puVar6 = DAT_00544f34;
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
    _DAT_00544f38 = uVar2;
    *(undefined1 *)((int)DAT_00544f34 + uVar2) = 0;
  }
  DAT_00544f40 = local_1;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_004f80c4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar4 = &DAT_004f80c4;
    puVar6 = DAT_00544f44;
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
    _DAT_00544f48 = uVar2;
    *(undefined1 *)((int)DAT_00544f44 + uVar2) = 0;
  }
  return;
}

