/*
 * FUN_004631d0 at 004631d0
 * undefined FUN_004631d0(void)
 * Address ranges: 004631d0-004632b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004631d0(int param_1,float param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float local_14;
  float local_c [3];
  
  iVar5 = 0;
  iVar1 = *(int *)(param_1 + 8);
  local_14 = 0.0;
  if (0 < iVar1) {
    do {
      FUN_00463b80();
      if (*(int *)(param_1 + 4) == 0) {
        pbVar2 = &DAT_004d2404;
      }
      else {
        pbVar2 = (byte *)(*(int *)(param_1 + 4) + iVar5);
      }
      uVar4 = (uint)*pbVar2;
      FUN_00463b20(uVar4);
      uVar3 = FUN_0045ac50(uVar4);
      FUN_00459990(uVar3);
      if (*(int *)(param_1 + 4) == 0) {
        pbVar2 = &DAT_004d2404;
      }
      else {
        pbVar2 = (byte *)(*(int *)(param_1 + 4) + iVar5);
      }
      uVar4 = (uint)*pbVar2;
      FUN_00463b20(uVar4);
      fVar6 = (float10)FUN_0045ad40(uVar4);
      local_c[1] = 0.0;
      local_c[2] = 0.0;
      local_c[0] = (float)(fVar6 * (float10)param_2 * (float10)0.5 + (float10)local_14);
      FUN_00458400(local_c);
      FUN_00463b20();
      fVar7 = (float10)FUN_0045ae50();
      iVar5 = iVar5 + 1;
      local_14 = (float)(fVar7 * (float10)param_2 + (float10)(float)(fVar6 * (float10)param_2) +
                        (float10)local_14);
    } while (iVar5 < iVar1);
  }
  return;
}

