/*
 * FUN_00445120 at 00445120
 * undefined FUN_00445120(void)
 * Address ranges: 00445120-00445525
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445120(float *param_1,undefined4 param_2,int param_3,int param_4,float param_5,
                 char param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  int iStack_364;
  int iStack_360;
  float fStack_350;
  float fStack_34c;
  float fStack_348;
  float fStack_344;
  undefined4 local_340 [7];
  float afStack_324 [201];
  
  iVar1 = FUN_00444ba0(param_2);
  puVar5 = &DAT_0053f660 + iVar1 * 0xd0;
  puVar6 = local_340;
  for (iVar3 = 0xd0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar1 = FUN_00444ba0(param_2);
  if (*(int *)(&DAT_0053f674 + iVar1 * 0x340) < 1) {
    FUN_004afee0(s__s___d__Path_contains_no_points__004ef368,
                 s_D__work_rcsk_Code_game_pth_main__004ef344,0x14e,param_2);
  }
  iVar1 = FUN_00444ba0(param_2);
  if (*(int *)(&DAT_0053f674 + iVar1 * 0x340) == 1) {
    *param_1 = afStack_324[0];
    param_1[1] = afStack_324[1];
    param_1[2] = afStack_324[2];
    return;
  }
  if (param_6 == '\0') {
    iVar1 = FUN_00444ba0(param_2);
    iStack_360 = *(int *)(&DAT_0053f674 + iVar1 * 0x340) + -1;
  }
  else {
    iVar1 = FUN_00444ba0(param_2);
    iStack_360 = *(int *)(&DAT_0053f674 + iVar1 * 0x340);
  }
  iStack_360 = param_3 / iStack_360;
  iVar1 = param_4 / iStack_360;
  if (param_6 == '\0') {
    iVar3 = FUN_00444ba0(param_2);
    if (*(int *)(&DAT_0053f674 + iVar3 * 0x340) + -2 < iVar1) {
      iVar1 = FUN_00444ba0(param_2);
      iVar1 = *(int *)(&DAT_0053f674 + iVar1 * 0x340) + -2;
    }
  }
  else {
    iVar3 = FUN_00444ba0(param_2);
    if (*(int *)(&DAT_0053f674 + iVar3 * 0x340) + -1 < iVar1) {
      iVar1 = FUN_00444ba0(param_2);
      iVar1 = *(int *)(&DAT_0053f674 + iVar1 * 0x340) + -1;
    }
  }
  iStack_364 = param_4 - iVar1 * iStack_360;
  if (iStack_364 < 0) {
    iStack_364 = 0;
  }
  if (iStack_360 <= iStack_364) {
    iStack_360 = iStack_364 + 1;
  }
  iVar3 = iVar1 + -1;
  iVar4 = iVar1 + 1;
  iVar7 = iVar1 + 2;
  if (param_6 == '\0') {
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar2 = FUN_00444ba0(param_2);
    if (*(int *)(&DAT_0053f674 + iVar2 * 0x340) + -1 < iVar4) {
      iVar4 = FUN_00444ba0(param_2);
      iVar4 = *(int *)(&DAT_0053f674 + iVar4 * 0x340) + -1;
    }
    iVar2 = FUN_00444ba0(param_2);
    if (*(int *)(&DAT_0053f674 + iVar2 * 0x340) + -1 < iVar7) {
      iVar7 = FUN_00444ba0(param_2);
      iVar7 = *(int *)(&DAT_0053f674 + iVar7 * 0x340) + -1;
    }
  }
  else {
    if (iVar3 < 0) {
      iVar3 = FUN_00444ba0(param_2);
      iVar3 = *(int *)(&DAT_0053f674 + iVar3 * 0x340) + -1;
    }
    iVar2 = FUN_00444ba0(param_2);
    if (*(int *)(&DAT_0053f674 + iVar2 * 0x340) + -1 < iVar4) {
      iVar4 = 0;
      iVar7 = 1;
    }
    else {
      iVar2 = FUN_00444ba0(param_2);
      if (*(int *)(&DAT_0053f674 + iVar2 * 0x340) + -1 < iVar7) {
        iVar7 = 0;
      }
    }
  }
  fStack_348 = (afStack_324[iVar4 * 4] - afStack_324[iVar3 * 4]) * param_5;
  fStack_350 = afStack_324[iVar1 * 4];
  fStack_34c = afStack_324[iVar4 * 4];
  fStack_344 = (afStack_324[iVar7 * 4] - afStack_324[iVar1 * 4]) * param_5;
  fVar8 = (float10)FUN_00445530(&fStack_350,iStack_364,iStack_360);
  fStack_350 = afStack_324[iVar1 * 4 + 1];
  fStack_34c = afStack_324[iVar4 * 4 + 1];
  fStack_348 = (afStack_324[iVar4 * 4 + 1] - afStack_324[iVar3 * 4 + 1]) * param_5;
  fStack_344 = (afStack_324[iVar7 * 4 + 1] - afStack_324[iVar1 * 4 + 1]) * param_5;
  fVar9 = (float10)FUN_00445530(&fStack_350,iStack_364,iStack_360);
  fStack_350 = afStack_324[iVar1 * 4 + 2];
  fStack_348 = (afStack_324[iVar4 * 4 + 2] - afStack_324[iVar3 * 4 + 2]) * param_5;
  fStack_34c = afStack_324[iVar4 * 4 + 2];
  fStack_344 = (afStack_324[iVar7 * 4 + 2] - afStack_324[iVar1 * 4 + 2]) * param_5;
  fVar10 = (float10)FUN_00445530(&fStack_350,iStack_364,iStack_360);
  *param_1 = (float)fVar8;
  param_1[1] = (float)fVar9;
  param_1[2] = (float)fVar10;
  return;
}

