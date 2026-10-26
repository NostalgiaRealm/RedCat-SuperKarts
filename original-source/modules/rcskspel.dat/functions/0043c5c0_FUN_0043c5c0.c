/*
 * FUN_0043c5c0 at 0043c5c0
 * undefined FUN_0043c5c0(void)
 * Address ranges: 0043c5c0-0043c86c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043c5c0(int param_1,float param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float10 extraout_ST0;
  float10 extraout_ST1;
  int aiStack_10 [3];
  float fStack_4;
  
  aiStack_10[0] = DAT_0053be28;
  if (param_2 == 0.0) {
    FUN_004afee0(s__object_flyup_check_collision__m_004ec364);
  }
  if (param_3 == 0.0) {
    iVar2 = FUN_0043df60(param_1,aiStack_10);
  }
  else {
    iVar2 = FUN_0043df90(param_1,aiStack_10[0],param_3);
  }
  iVar4 = DAT_0067ee20;
  if (iVar2 != 0) {
    fStack_4 = *(float *)(aiStack_10[0] * 0xd0 + 0xa4 + DAT_0067ee20) * 3.0;
    uVar3 = __ftol();
    iVar2 = (DAT_004fc8f8 & uVar3) * 4;
    param_1 = param_1 * 0xd0;
    *(float *)(param_1 + 0x9c + iVar4) =
         (float)((float10)*(float *)(iVar2 + DAT_006a5cd0) * extraout_ST1 -
                (float10)*(float *)(iVar2 + DAT_006a5c88) * extraout_ST0);
    iVar2 = (DAT_004fc8f8 & uVar3) * 4;
    *(float *)(param_1 + 0xa4 + DAT_0067ee20) =
         (float)((float10)*(float *)(iVar2 + DAT_006a5c88) * extraout_ST1 +
                (float10)*(float *)(iVar2 + DAT_006a5cd0) * extraout_ST0);
    *(float *)(param_1 + 0xa0 + DAT_0067ee20) =
         (float)((extraout_ST0 + extraout_ST1) * (float10)0.25);
    pfVar1 = (float *)(param_1 + 0x9c + DAT_0067ee20);
    uVar3 = FUN_004be6c9();
    uVar3 = uVar3 & 0x800000ff;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
    }
    *pfVar1 = ((float)(int)uVar3 * 0.001953125 + 0.75) * *pfVar1;
    pfVar1 = (float *)(param_1 + 0xa0 + DAT_0067ee20);
    uVar3 = FUN_004be6c9();
    uVar3 = uVar3 & 0x800000ff;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
    }
    *pfVar1 = ((float)(int)uVar3 * 0.001953125 + 0.75) * *pfVar1;
    pfVar1 = (float *)(param_1 + 0xa4 + DAT_0067ee20);
    uVar3 = FUN_004be6c9();
    uVar3 = uVar3 & 0x800000ff;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
    }
    *pfVar1 = ((float)(int)uVar3 * 0.001953125 + 0.75) * *pfVar1;
    iVar2 = DAT_0067ee20;
    iVar4 = __ftol();
    iVar5 = (DAT_004fc8f8 & -iVar4) * 4;
    *(float *)(param_1 + 0xa8 + iVar2) =
         *(float *)(iVar5 + DAT_006a5cd0) * *(float *)(param_1 + 0x9c + iVar2) -
         *(float *)(iVar5 + DAT_006a5c88) * *(float *)(param_1 + 0xa4 + iVar2);
    iVar2 = (DAT_004fc8f8 & -iVar4) * 4;
    *(float *)(param_1 + 0xb0 + DAT_0067ee20) =
         *(float *)(iVar2 + DAT_006a5cd0) * *(float *)(param_1 + 0xa4 + DAT_0067ee20) +
         *(float *)(iVar2 + DAT_006a5c88) * *(float *)(param_1 + 0x9c + DAT_0067ee20);
    *(undefined4 *)(param_1 + 0x40 + DAT_0067ee20) = 0xc2340000;
    *(undefined4 *)(param_1 + 0x14 + DAT_0067ee20) = 1;
    return 1;
  }
  return 0;
}

