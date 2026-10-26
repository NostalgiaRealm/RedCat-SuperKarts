/*
 * FUN_00463400 at 00463400
 * undefined FUN_00463400(void)
 * Address ranges: 00463400-004634d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463400(int param_1,float param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  uint uVar4;
  float10 fVar5;
  float10 fVar6;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 8);
  local_10 = 0.0;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    FUN_00463b80();
    if (*(int *)(param_1 + 4) == 0) {
      pbVar2 = &DAT_004d2404;
    }
    else {
      pbVar2 = (byte *)(*(int *)(param_1 + 4) + iVar1);
    }
    uVar4 = (uint)*pbVar2;
    FUN_00463b20(uVar4);
    uVar3 = FUN_0045ac50(uVar4);
    FUN_00459990(uVar3);
    if (*(int *)(param_1 + 4) == 0) {
      pbVar2 = &DAT_004d2404;
    }
    else {
      pbVar2 = (byte *)(*(int *)(param_1 + 4) + iVar1);
    }
    uVar4 = (uint)*pbVar2;
    FUN_00463b20(uVar4);
    fVar5 = (float10)FUN_0045ad40(uVar4);
    local_8 = 0;
    local_4 = 0;
    local_c = (float)((float10)local_10 - fVar5 * (float10)param_2 * (float10)0.5);
    FUN_00458400(&local_c);
    FUN_00463b20();
    fVar6 = (float10)FUN_0045ae50();
    local_10 = (float)((float10)local_10 -
                      (fVar6 * (float10)param_2 + (float10)(float)(fVar5 * (float10)param_2)));
  }
  return;
}

