/*
 * FUN_00460440 at 00460440
 * undefined FUN_00460440(void)
 * Address ranges: 00460440-004604a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_00460440(int param_1,uint param_2,uint param_3,byte *param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  
  if (*(uint *)(param_1 + 8) < param_2) {
    FUN_004bc243();
  }
  uVar1 = *(int *)(param_1 + 8) - param_2;
  if (uVar1 < param_3) {
    param_3 = uVar1;
  }
  uVar1 = param_3;
  if (param_5 <= param_3) {
    uVar1 = param_5;
  }
  if (*(int *)(param_1 + 4) == 0) {
    pbVar3 = (byte *)0x0;
  }
  else {
    pbVar3 = (byte *)(*(int *)(param_1 + 4) + param_2);
  }
  bVar4 = false;
  uVar2 = 0;
  bVar5 = true;
  do {
    if (uVar1 == 0) break;
    uVar1 = uVar1 - 1;
    bVar4 = *pbVar3 < *param_4;
    bVar5 = *pbVar3 == *param_4;
    pbVar3 = pbVar3 + 1;
    param_4 = param_4 + 1;
  } while (bVar5);
  if (!bVar5) {
    uVar2 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
  }
  if (uVar2 == 0) {
    if (param_3 < param_5) {
      return 0xffffffff;
    }
    uVar2 = (uint)(param_3 != param_5);
  }
  return uVar2;
}

