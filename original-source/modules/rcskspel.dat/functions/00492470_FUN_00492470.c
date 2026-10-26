/*
 * FUN_00492470 at 00492470
 * undefined FUN_00492470(void)
 * Address ranges: 00492470-0049261d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_00492470(int param_1,undefined4 param_2,float *param_3,float param_4,undefined4 *param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float10 fVar11;
  undefined4 local_28 [10];
  
  if ((param_4 != 0.0) && (iVar8 = FUN_0049c6e0(), iVar8 != 0)) {
    puVar9 = &DAT_006a5b58;
    puVar10 = local_28;
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    iVar8 = param_1 * 0xd0;
    pfVar1 = (float *)(iVar8 + 0x9c + DAT_0067ee20);
    fVar4 = *pfVar1;
    fVar5 = pfVar1[1];
    fVar6 = pfVar1[2];
    fVar2 = DAT_006a5b74 * fVar4 + fVar6 * DAT_006a5b7c + DAT_006a5b78 * fVar5;
    if (fVar2 <= 0.0) {
      fVar2 = fVar2 - 10.0;
      if ((*(byte *)(iVar8 + 4 + DAT_0067ee20) & 0x10) == 0) {
        fVar2 = -fVar2;
        fVar3 = DAT_006a5b78 * fVar2;
        fVar7 = fVar2 * DAT_006a5b7c;
        *pfVar1 = DAT_006a5b74 * fVar2 + *pfVar1;
        pfVar1[1] = fVar3 + pfVar1[1];
        pfVar1[2] = fVar7 + pfVar1[2];
      }
      else {
        pfVar1 = (float *)(iVar8 + 0xa4 + DAT_0067ee20);
        *pfVar1 = -(DAT_006a5b7c * fVar2) + *pfVar1;
      }
      fVar11 = (float10)FUN_00499c30(param_1,&param_4,param_2);
      if (param_4 == 1.4013e-45) {
        *param_5 = 1;
      }
      fVar2 = *(float *)(iVar8 + 0xa0 + DAT_0067ee20);
      fVar3 = *(float *)(iVar8 + 0xa4 + DAT_0067ee20);
      *param_3 = (float)(fVar11 * (float10)*(float *)(iVar8 + 0x9c + DAT_0067ee20));
      param_3[1] = (float)(fVar11 * (float10)fVar2);
      param_3[2] = (float)(fVar11 * (float10)fVar3);
      pfVar1 = (float *)(iVar8 + 0x9c + DAT_0067ee20);
      *pfVar1 = fVar4;
      pfVar1[1] = fVar5;
      pfVar1[2] = fVar6;
      puVar9 = local_28;
      puVar10 = &DAT_006a5b58;
      for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      return 1;
    }
  }
  return 0;
}

