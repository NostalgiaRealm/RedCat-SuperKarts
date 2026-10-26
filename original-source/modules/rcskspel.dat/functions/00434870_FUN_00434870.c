/*
 * FUN_00434870 at 00434870
 * undefined FUN_00434870(void)
 * Address ranges: 00434870-00434c3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434870(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  FUN_004afce0();
  puVar7 = param_2;
  puVar8 = param_1;
  for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  FUN_004afce0(s_Source__object1____d__object_2___004eb8e0,param_2[2],param_2[3]);
  param_1[2] = param_2[3];
  param_1[3] = param_2[2];
  FUN_00405f20();
  FUN_004afce0();
  FUN_004afce0();
  __ftol();
  pfVar5 = (float *)FUN_0049b950();
  fVar1 = *pfVar5;
  fVar2 = pfVar5[1];
  fVar3 = pfVar5[2];
  FUN_004afce0();
  iVar6 = *(int *)(param_2[2] * 0xd0 + 0xc + DAT_0067ee20);
  fVar1 = fVar1 + *(float *)(DAT_006a5c38 + iVar6 + 0x50 + iVar6 * 0xa8);
  iVar6 = DAT_006a5c38 + iVar6 + iVar6 * 0xa8;
  fVar2 = fVar2 + *(float *)(iVar6 + 0x54);
  fVar3 = fVar3 + *(float *)(iVar6 + 0x58);
  FUN_004afce0(s_Translating__position_____f___f__004eb964,(double)*(float *)(iVar6 + 0x50),
               (double)*(float *)(iVar6 + 0x54),(double)*(float *)(iVar6 + 0x58),(double)fVar1,
               (double)fVar2,(double)fVar3);
  iVar4 = *(int *)(param_2[3] * 0xd0 + 0xc + DAT_0067ee20);
  iVar6 = DAT_006a5c38 + iVar4 + iVar4 * 0xa8;
  FUN_004afce0(s_Translating__position2_____f___f_004eb9a4,(double)*(float *)(iVar6 + 0x50),
               (double)*(float *)(iVar6 + 0x54),(double)*(float *)(iVar6 + 0x58),
               (double)(fVar1 - *(float *)(DAT_006a5c38 + iVar4 + 0x50 + iVar4 * 0xa8)),
               (double)(fVar2 - *(float *)(iVar6 + 0x54)),(double)(fVar3 - *(float *)(iVar6 + 0x58))
              );
  __ftol();
  pfVar5 = (float *)FUN_0049b950();
  fVar1 = *pfVar5;
  fVar2 = pfVar5[1];
  fVar3 = pfVar5[2];
  FUN_004afce0();
  param_1[4] = fVar1 * 0.1;
  param_1[5] = fVar2 * 0.1;
  param_1[6] = fVar3 * 0.1;
  return;
}

