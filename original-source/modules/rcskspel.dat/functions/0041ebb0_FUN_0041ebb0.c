/*
 * FUN_0041ebb0 at 0041ebb0
 * undefined FUN_0041ebb0(void)
 * Address ranges: 0041ebb0-0041ecc2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ebb0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_9c [12];
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_40 [16];
  
  iVar3 = (&DAT_00508620)[DAT_00508670] * 0x178;
  iVar2 = *(int *)(DAT_00680ba0 + 0xb8 + iVar3);
  puVar4 = (undefined4 *)(DAT_00680ba0 + 0x14 + iVar3);
  puVar5 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (0 < iVar2) {
    DAT_00508684 = iVar2;
  }
  DAT_0050867c = 0;
  DAT_00508678 = 0;
  iVar1 = DAT_0050863c * 0x178;
  DAT_00508680 = 0;
  local_60 = 0x41ec40;
  FUN_00498b20();
  local_60 = 0x41ec4e;
  FUN_00498bd0();
  puVar4 = local_40;
  puVar5 = auStack_9c;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_004988f0();
  iVar2 = DAT_00680ba0 + 8 + iVar3;
  local_68 = *(undefined4 *)(DAT_00680ba0 + 8 + iVar3);
  local_64 = *(undefined4 *)(iVar2 + 4);
  local_60 = *(undefined4 *)(iVar2 + 8);
  uStack_6c = 0x41ec93;
  FUN_004988a0();
  *(undefined4 *)(iVar1 + 0x80 + DAT_00680ba0) = 1;
  local_60 = 0x41ecb1;
  FUN_00498c00();
  local_60 = 7;
  local_64 = 0x41ecb8;
  FUN_0041d6c0();
  return;
}

