/*
 * FUN_00479b90 at 00479b90
 * undefined FUN_00479b90(void)
 * Address ranges: 00479b90-00479cd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00479b90(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_1;
  
  local_1 = (undefined1)((uint)param_1 >> 0x18);
  DAT_00544e98 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = s_key_back_pcl_004f7eb0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544e9c = (char *)0x0;
  _DAT_00544ea0 = 0;
  _DAT_00544ea4 = 0;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_key_back_pcl_004f7eb0;
    pcVar5 = DAT_00544e9c;
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
    _DAT_00544ea0 = uVar2;
    DAT_00544e9c[uVar2] = '\0';
  }
  DAT_00544ea8 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = s_joy_back_pcl_004f7ec0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544eac = (char *)0x0;
  _DAT_00544eb0 = 0;
  _DAT_00544eb4 = 0;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_joy_back_pcl_004f7ec0;
    pcVar5 = DAT_00544eac;
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
    _DAT_00544eb0 = uVar2;
    DAT_00544eac[uVar2] = '\0';
  }
  DAT_00544eb8 = local_1;
  uVar2 = 0xffffffff;
  pcVar4 = s_pad_back_pcl_004f7ed0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  DAT_00544ebc = (char *)0x0;
  _DAT_00544ec0 = 0;
  _DAT_00544ec4 = 0;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_pad_back_pcl_004f7ed0;
    pcVar5 = DAT_00544ebc;
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
    _DAT_00544ec0 = uVar2;
    DAT_00544ebc[uVar2] = '\0';
  }
  return;
}

