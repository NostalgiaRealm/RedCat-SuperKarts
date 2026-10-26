/*
 * FUN_004282e0 at 004282e0
 * undefined FUN_004282e0(void)
 * Address ranges: 004282e0-00428454
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004282e0(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  FUN_00427f30(param_1);
  FUN_00427fe0(param_1);
  FUN_00428240(param_1);
  iVar7 = FUN_00427ed0(param_1);
  fVar4 = *(float *)(&DAT_00535120 + iVar7 * 300);
  fVar5 = *(float *)(&DAT_00535124 + iVar7 * 300);
  fVar6 = *(float *)(&DAT_00535128 + iVar7 * 300);
  iVar8 = FUN_00427ed0(param_1);
  iVar7 = iVar8 * 300;
  *(float *)(&DAT_00535120 + iVar7) = *(float *)(&DAT_00535120 + iVar8 * 300) * 0.9;
  *(float *)(&DAT_00535124 + iVar7) = *(float *)(&DAT_00535124 + iVar7) * 0.9;
  *(float *)(&DAT_00535128 + iVar7) = *(float *)(&DAT_00535128 + iVar7) * 0.9;
  iVar7 = FUN_00427ed0(param_1);
  fVar1 = *(float *)(&DAT_00535050 + iVar7 * 300);
  iVar7 = FUN_00427ed0(param_1);
  fVar2 = *(float *)(&DAT_00535054 + iVar7 * 300);
  iVar7 = FUN_00427ed0(param_1);
  iVar8 = (&DAT_00508620)[DAT_00508670];
  fVar3 = *(float *)(&DAT_00535058 + iVar7 * 300);
  iVar7 = DAT_00680ba0 + 0x14;
  iVar9 = FUN_00427ed0(param_1);
  puVar11 = (undefined4 *)(iVar7 + iVar8 * 0x178);
  puVar12 = (undefined4 *)(&DAT_00535020 + iVar9 * 300);
  for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  }
  iVar7 = FUN_00427ed0(param_1);
  *(float *)(&DAT_00535050 + iVar7 * 300) = fVar4 + fVar1;
  iVar7 = FUN_00427ed0(param_1);
  *(float *)(&DAT_00535054 + iVar7 * 300) = fVar5 + fVar2;
  iVar7 = FUN_00427ed0(param_1);
  *(float *)(&DAT_00535058 + iVar7 * 300) = fVar6 + fVar3;
  return;
}

