/*
 * FUN_004584c0 at 004584c0
 * undefined FUN_004584c0(void)
 * Address ranges: 004584c0-0045850d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004584c0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  uVar1 = *(uint *)(param_2 + 8);
  pbVar6 = &DAT_004d2404;
  if (*(byte **)(param_2 + 4) != (byte *)0x0) {
    pbVar6 = *(byte **)(param_2 + 4);
  }
  uVar2 = *(uint *)(param_1 + 0x3c);
  uVar3 = uVar2;
  if (uVar1 <= uVar2) {
    uVar3 = uVar1;
  }
  bVar7 = false;
  iVar4 = 0;
  bVar8 = true;
  pbVar5 = *(byte **)(param_1 + 0x38);
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    bVar7 = *pbVar5 < *pbVar6;
    bVar8 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar8);
  if (!bVar8) {
    iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
  }
  if (((iVar4 != 0) || (uVar2 < uVar1)) || (uVar2 != uVar1)) {
    param_1 = 0;
  }
  return param_1;
}

