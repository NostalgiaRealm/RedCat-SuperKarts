/*
 * FUN_0048b1d0 at 0048b1d0
 * undefined FUN_0048b1d0(void)
 * Address ranges: 0048b1d0-0048b215
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_0048b1d0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar2 = param_2;
  puVar3 = param_2;
  while (puVar3 = puVar3 + 8, puVar3 != puVar1) {
    puVar5 = puVar2 + 8;
    puVar6 = puVar3;
    puVar7 = puVar2;
    for (iVar4 = 8; puVar2 = puVar5, iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
  return param_2;
}

