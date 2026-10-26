/*
 * FUN_00427fe0 at 00427fe0
 * undefined FUN_00427fe0(void)
 * Address ranges: 00427fe0-00428235
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00427fe0(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  iVar5 = FUN_00427ed0(param_1);
  fVar1 = *(float *)(&DAT_00535140 + iVar5 * 300);
  iVar5 = FUN_00427ed0(param_1);
  fVar2 = *(float *)(&DAT_00535144 + iVar5 * 300);
  iVar5 = FUN_00427ed0(param_1);
  fVar1 = 29.0 / (float)*(int *)(&DAT_00535138 + iVar5 * 300) + fVar1;
  iVar5 = FUN_00427ed0(param_1);
  fVar2 = 29.0 / (float)*(int *)(&DAT_00535138 + iVar5 * 300) + fVar2;
  fVar3 = fVar1 * 0.5;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(1);
  *(float *)(&DAT_00535060 + iVar5 * 300 + iVar6 * 0x20) = -fVar3;
  fVar4 = fVar2 * 0.5;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(1);
  *(float *)(&DAT_00535064 + iVar5 * 300 + iVar6 * 0x20) = -fVar4;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(2);
  *(float *)(&DAT_00535060 + iVar5 * 300 + iVar6 * 0x20) = -fVar3;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(2);
  *(float *)(&DAT_00535064 + iVar5 * 300 + iVar6 * 0x20) = fVar4;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(3);
  *(float *)(&DAT_00535060 + iVar5 * 300 + iVar6 * 0x20) = fVar3;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(3);
  *(float *)(&DAT_00535064 + iVar5 * 300 + iVar6 * 0x20) = fVar4;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(4);
  *(float *)(&DAT_00535060 + iVar5 * 300 + iVar6 * 0x20) = fVar3;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(4);
  *(float *)(&DAT_00535064 + iVar5 * 300 + iVar6 * 0x20) = -fVar4;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(1);
  iVar7 = FUN_00427ed0(param_1);
  iVar8 = FUN_00427f00(5);
  puVar10 = (undefined4 *)(&DAT_00535060 + iVar5 * 300 + iVar6 * 0x20);
  puVar11 = (undefined4 *)(&DAT_00535060 + iVar7 * 300 + iVar8 * 0x20);
  for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
  iVar5 = FUN_00427ed0(param_1);
  *(float *)(&DAT_00535140 + iVar5 * 300) = fVar1;
  iVar5 = FUN_00427ed0(param_1);
  *(float *)(&DAT_00535144 + iVar5 * 300) = fVar2;
  return;
}

