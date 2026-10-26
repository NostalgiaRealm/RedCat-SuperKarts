/*
 * FUN_0045aab0 at 0045aab0
 * undefined FUN_0045aab0(void)
 * Address ranges: 0045aab0-0045aaff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_0045aab0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  uVar1 = *(uint *)(param_2 + 8);
  pbVar3 = *(byte **)(param_2 + 4);
  if (pbVar3 == (byte *)0x0) {
    pbVar3 = &DAT_004d2404;
  }
  uVar2 = *(uint *)(param_1 + 8);
  uVar5 = uVar2;
  if (uVar1 <= uVar2) {
    uVar5 = uVar1;
  }
  bVar7 = false;
  uVar4 = 0;
  bVar8 = true;
  pbVar6 = *(byte **)(param_1 + 4);
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    bVar7 = *pbVar6 < *pbVar3;
    bVar8 = *pbVar6 == *pbVar3;
    pbVar6 = pbVar6 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar8);
  if (!bVar8) {
    uVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
  }
  if (uVar4 == 0) {
    if (uVar2 < uVar1) {
      return 0xffffffff;
    }
    uVar4 = (uint)(uVar2 != uVar1);
  }
  return uVar4;
}

