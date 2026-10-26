/*
 * FUN_004603e0 at 004603e0
 * undefined FUN_004603e0(void)
 * Address ranges: 004603e0-00460432
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_004603e0(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  uVar4 = 0xffffffff;
  uVar2 = *(uint *)(param_1 + 8);
  pbVar6 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  } while (bVar1 != 0);
  uVar5 = ~uVar4 - 1;
  uVar4 = uVar2;
  if (uVar5 <= uVar2) {
    uVar4 = uVar5;
  }
  bVar7 = false;
  uVar3 = 0;
  bVar8 = true;
  pbVar6 = *(byte **)(param_1 + 4);
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar7 = *pbVar6 < *param_2;
    bVar8 = *pbVar6 == *param_2;
    pbVar6 = pbVar6 + 1;
    param_2 = param_2 + 1;
  } while (bVar8);
  if (!bVar8) {
    uVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
  }
  if (uVar3 == 0) {
    if (uVar2 < uVar5) {
      return 0xffffffff;
    }
    uVar3 = (uint)(uVar2 != uVar5);
  }
  return uVar3;
}

