/*
 * FUN_004632c0 at 004632c0
 * undefined FUN_004632c0(void)
 * Address ranges: 004632c0-004633ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004632c0(float param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = (int)param_1;
  iVar1 = *(int *)((int)param_1 + 8);
  iVar8 = iVar1 + -1;
  FUN_00463b20();
  fVar9 = (float10)FUN_0045ae50();
  fVar9 = fVar9 * (float10)iVar8 * (float10)param_2;
  for (; -1 < iVar8; iVar8 = iVar8 + -1) {
    if (*(int *)((int)param_1 + 4) == 0) {
      puVar4 = &DAT_004d2404;
    }
    else {
      puVar4 = (undefined1 *)(*(int *)((int)param_1 + 4) + iVar8);
    }
    uVar6 = CONCAT31((int3)((uint)puVar4 >> 8),*puVar4);
    FUN_00463b20(uVar6);
    fVar10 = (float10)FUN_0045ad40(uVar6);
    fVar9 = fVar10 * (float10)param_2 + (float10)(float)fVar9;
  }
  param_1 = (float)fVar9 * -0.5;
  iVar8 = 0;
  if (0 < iVar1) {
    do {
      FUN_00463b80();
      iVar2 = *(int *)(iVar3 + 4);
      if (iVar2 == 0) {
        pbVar5 = &DAT_004d2404;
      }
      else {
        pbVar5 = (byte *)(iVar2 + iVar8);
      }
      uVar7 = (uint)*pbVar5;
      FUN_00463b20(uVar7);
      uVar6 = FUN_0045ac50(uVar7);
      FUN_00459990(uVar6);
      iVar2 = *(int *)(iVar3 + 4);
      if (iVar2 == 0) {
        puVar4 = &DAT_004d2404;
      }
      else {
        puVar4 = (undefined1 *)(iVar2 + iVar8);
      }
      uVar6 = CONCAT31((int3)((uint)puVar4 >> 8),*puVar4);
      FUN_00463b20(uVar6);
      fVar9 = (float10)FUN_0045ad40(uVar6);
      local_8 = 0;
      local_4 = 0;
      local_c = (float)(fVar9 * (float10)param_2 * (float10)0.5 + (float10)param_1);
      FUN_00458400(&local_c);
      FUN_00463b20();
      fVar10 = (float10)FUN_0045ae50();
      iVar8 = iVar8 + 1;
      param_1 = (float)(fVar10 * (float10)param_2 + (float10)(float)(fVar9 * (float10)param_2) +
                       (float10)param_1);
    } while (iVar8 < iVar1);
  }
  return;
}

