/*
 * FUN_00492810 at 00492810
 * undefined FUN_00492810(void)
 * Address ranges: 00492810-004929a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00492810(int param_1,float *param_2,float *param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  
  fVar2 = param_2[0xc];
  pfVar1 = param_3 + 3;
  fVar3 = param_2[1];
  fVar4 = param_2[2];
  *param_3 = fVar2 * *param_2 * param_4;
  param_3[1] = fVar2 * fVar3 * param_4;
  param_3[2] = fVar2 * fVar4 * param_4;
  fVar2 = param_2[4];
  fVar3 = param_2[5];
  *pfVar1 = param_4 * param_2[3];
  param_3[4] = param_4 * fVar2;
  param_3[5] = param_4 * fVar3;
  param_3[6] = param_2[9] * param_2[0xd] * param_4;
  param_3[7] = param_2[10] * param_4;
  fVar2 = param_2[4];
  fVar3 = param_3[1];
  fVar4 = param_2[5];
  fVar5 = param_3[2];
  *(float *)(param_1 + 0xc) = param_2[3] + *param_3;
  *(float *)(param_1 + 0x10) = fVar2 + fVar3;
  *(float *)(param_1 + 0x14) = fVar4 + fVar5;
  *(float *)(param_1 + 0x28) = param_3[6] + param_2[10];
  uVar8 = __ftol();
  iVar9 = (uVar8 & DAT_004fc8f8) * 4;
  fVar2 = *(float *)(iVar9 + DAT_006a5c88);
  fVar3 = *pfVar1;
  fVar4 = *(float *)(iVar9 + DAT_006a5cd0);
  fVar5 = param_3[5];
  fVar6 = param_2[7];
  fVar7 = param_2[8];
  *(float *)(param_1 + 0x18) =
       (*(float *)(iVar9 + DAT_006a5cd0) * *pfVar1 - *(float *)(iVar9 + DAT_006a5c88) * param_3[5])
       * 10.0 + param_2[6];
  *(float *)(param_1 + 0x1c) = fVar6;
  *(float *)(param_1 + 0x20) = (fVar4 * fVar5 + fVar2 * fVar3) * 10.0 + fVar7;
  *(float *)(param_1 + 0x2c) = (_DAT_004fc8f4 * param_3[7]) / 6.2831855 + param_2[0xb];
  *(float *)(param_1 + 0x30) = param_2[0xc];
  *(float *)(param_1 + 0x34) = param_2[0xd];
  return;
}

