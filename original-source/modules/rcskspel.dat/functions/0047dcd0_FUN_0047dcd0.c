/*
 * FUN_0047dcd0 at 0047dcd0
 * undefined FUN_0047dcd0(void)
 * Address ranges: 0047dcd0-0047df19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047dcd0(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 local_2d;
  undefined1 local_2c [4];
  undefined4 *local_28;
  uint local_24;
  undefined1 local_1c [4];
  char *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1118;
  local_c = ExceptionList;
  local_1c[0] = local_2d;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = (char *)&DAT_004f87d8;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = (char *)&DAT_004f87d8;
    pcVar6 = local_18;
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
    FUN_0040b5e0(uVar2);
  }
  local_4 = 0;
  DAT_00544fd0 = local_1c[0];
  FUN_0040b4f0(0);
  FUN_00412870(local_1c,0,0xffffffff);
  DAT_00544fe0 = FUN_0047d600;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  local_1c[0] = local_2d;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = s_BUTTON_004f87e0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_BUTTON_004f87e0;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)local_18 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      local_18 = local_18 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *local_18 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      local_18 = local_18 + 1;
    }
    FUN_0040b5e0(uVar2);
  }
  local_4 = 1;
  DAT_00544fe4 = local_1c[0];
  FUN_0040b4f0(0);
  FUN_00412870(local_1c,0,0xffffffff);
  DAT_00544ff4 = FUN_0047d400;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  local_2c[0] = local_2d;
  FUN_0040b4f0(0);
  uVar2 = 0xffffffff;
  pcVar4 = (char *)&DAT_00545010;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    puVar5 = &DAT_00545010;
    puVar7 = local_28;
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
    *(undefined1 *)((int)local_28 + uVar2) = 0;
    local_24 = uVar2;
  }
  DAT_00544ff8 = local_2c[0];
  local_4 = 2;
  FUN_0040b4f0(0);
  FUN_00412870(local_2c,0,0xffffffff);
  _DAT_00545008 = FUN_0047d600;
  if (local_28 != (undefined4 *)0x0) {
    cVar1 = *(char *)((int)local_28 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)((int)local_28 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150((char *)((int)local_28 + -1));
  }
  ExceptionList = local_c;
  return;
}

