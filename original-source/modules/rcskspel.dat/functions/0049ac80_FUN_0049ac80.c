/*
 * FUN_0049ac80 at 0049ac80
 * undefined FUN_0049ac80(void)
 * Address ranges: 0049ac80-0049ad74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049ac80(float *param_1,int param_2,int param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  
  iVar8 = param_2 + 1;
  if (3 < iVar8) {
    iVar8 = 0;
  }
  fVar5 = *(float *)(param_3 + iVar8 * 0xc) - *(float *)(param_3 + param_2 * 0xc);
  fVar6 = *(float *)(param_3 + iVar8 * 0xc + 8) - *(float *)(param_3 + param_2 * 0xc + 8);
  fVar7 = SQRT(fVar5 * fVar5 + fVar6 * fVar6);
  if (fVar7 == 0.0) {
    FUN_004afee0(s__s__d____Division_by_zero_004fb864,s_D__work_rcsk_Code_Engine_Prog_Bb_004fb7e4,
                 0x415);
  }
  iVar8 = (DAT_004fc8f8 & param_4) * 4;
  fVar1 = *(float *)(iVar8 + DAT_006a5cd0);
  fVar2 = *(float *)(iVar8 + DAT_006a5c88);
  fVar3 = *(float *)(iVar8 + DAT_006a5c88);
  fVar4 = *(float *)(iVar8 + DAT_006a5cd0);
  param_1[1] = 0.0;
  *param_1 = fVar4 * (fVar6 / fVar7) + fVar3 * (fVar5 / fVar7);
  param_1[2] = -(fVar1 * (fVar5 / fVar7) - fVar2 * (fVar6 / fVar7));
  return;
}

