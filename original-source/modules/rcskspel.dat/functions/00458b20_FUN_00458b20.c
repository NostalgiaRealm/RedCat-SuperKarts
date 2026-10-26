/*
 * FUN_00458b20 at 00458b20
 * undefined FUN_00458b20(void)
 * Address ranges: 00458b20-00458b9f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00458b20(int param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  
  pbVar2 = *(byte **)(param_1 + 0x38);
  if (pbVar2 == (byte *)0x0) {
    pbVar2 = &DAT_004d2404;
  }
  uVar1 = *(uint *)(param_2 + 8);
  uVar5 = *(uint *)(param_1 + 0x3c);
  if (uVar1 < *(uint *)(param_1 + 0x3c)) {
    uVar5 = uVar1;
  }
  bVar8 = false;
  iVar3 = 0;
  bVar9 = true;
  pbVar6 = *(byte **)(param_2 + 4);
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    bVar8 = *pbVar6 < *pbVar2;
    bVar9 = *pbVar6 == *pbVar2;
    pbVar6 = pbVar6 + 1;
    pbVar2 = pbVar2 + 1;
  } while (bVar9);
  if (!bVar9) {
    iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
  }
  if (((iVar3 == 0) && (*(uint *)(param_1 + 0x3c) <= uVar1)) && (uVar1 == *(uint *)(param_1 + 0x3c))
     ) {
    return param_1;
  }
  iVar3 = (*(code *)**(undefined4 **)(param_1 + 0x74))();
  iVar7 = 0;
  if (0 < iVar3) {
    do {
      iVar4 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0x78) + 4) + iVar7 * 4) + 0xc))
                        (param_2);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar3);
  }
  return 0;
}

