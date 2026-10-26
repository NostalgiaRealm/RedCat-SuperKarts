/*
 * FUN_004076b0 at 004076b0
 * undefined FUN_004076b0(void)
 * Address ranges: 004076b0-004077d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004076b0(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  pcVar3 = s__TOO_SLOW_004de8cf;
  iVar1 = 9;
  bVar4 = true;
  pcVar2 = param_1;
  do {
    pcVar3 = pcVar3 + 1;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 4;
  }
  iVar1 = 9;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_TOO_FAST_004de8dc;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 8;
  }
  iVar1 = 0xc;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_SPEED_FREAK_004de8e8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x10;
  }
  iVar1 = 7;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_GRANNY_004de8f4;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x20;
  }
  iVar1 = 7;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_SLOPPY_004de8fc;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x40;
  }
  iVar1 = 6;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_BLIND_004de904;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x80;
  }
  iVar1 = 5;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = (char *)0x4de90c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x100;
  }
  iVar1 = 6;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_RIGHT_004de914;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x200;
  }
  iVar1 = 6;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_DRUNK_004de91c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x400;
  }
  iVar1 = 10;
  bVar4 = true;
  pcVar3 = param_1;
  pcVar2 = s_RED_LIGHT_004de924;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0x800;
  }
  iVar1 = 0xd;
  bVar4 = true;
  pcVar3 = s_VLUCHTSTROOK_004de930;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *param_1 == *pcVar3;
    param_1 = param_1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  return !bVar4 - 1 & 0x1000;
}

