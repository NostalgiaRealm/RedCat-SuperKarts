/*
 * FUN_004802c0 at 004802c0
 * undefined FUN_004802c0(void)
 * Address ranges: 004802c0-00480342
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004802c0(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
  iVar3 = FUN_004809a0(param_3);
  if (iVar3 != *(int *)(param_1 + 4)) {
    uVar1 = *(uint *)(iVar3 + 0x14);
    pbVar4 = *(byte **)(iVar3 + 0x10);
    if (pbVar4 == (byte *)0x0) {
      pbVar4 = &DAT_004d2404;
    }
    uVar2 = *(uint *)(param_3 + 8);
    uVar6 = uVar2;
    if (uVar1 <= uVar2) {
      uVar6 = uVar1;
    }
    bVar8 = false;
    uVar5 = 0;
    bVar9 = true;
    pbVar7 = *(byte **)(param_3 + 4);
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar8 = *pbVar7 < *pbVar4;
      bVar9 = *pbVar7 == *pbVar4;
      pbVar7 = pbVar7 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar9);
    if (!bVar9) {
      uVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
    }
    if (uVar5 == 0) {
      if (uVar2 < uVar1) goto LAB_0048032b;
      uVar5 = (uint)(uVar2 != uVar1);
    }
    if (-1 < (int)uVar5) {
      *param_2 = iVar3;
      return;
    }
  }
LAB_0048032b:
  *param_2 = *(int *)(param_1 + 4);
  return;
}

