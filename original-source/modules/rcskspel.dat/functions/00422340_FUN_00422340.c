/*
 * FUN_00422340 at 00422340
 * undefined FUN_00422340(void)
 * Address ranges: 00422340-0042245f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00422340(int param_1)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  int iVar9;
  
  param_1 = param_1 * 0xa9;
  pfVar2 = (float *)(param_1 + 0x50 + DAT_006a5c38);
  iVar9 = *(int *)(param_1 + 0xc + DAT_006a5c38) * 0x44;
  fVar3 = *pfVar2;
  fVar4 = pfVar2[2];
  iVar5 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
  fVar6 = *(float *)(DAT_006a5c38 + iVar5 + 0x50 + iVar5 * 0xa8);
  iVar1 = iVar9 + DAT_005090d0;
  fVar7 = *(float *)(DAT_006a5c38 + iVar5 + iVar5 * 0xa8 + 0x58);
  FUN_0048f4e0();
  uVar8 = __ftol();
  *(undefined4 *)(iVar1 + 0x34) = uVar8;
  *(float *)(param_1 + 0x5c + DAT_006a5c38) =
       ((fVar3 - fVar6) * -0.9) / (float)*(int *)(iVar9 + 0x34 + DAT_005090d0);
  *(float *)(param_1 + 100 + DAT_006a5c38) =
       ((fVar4 - fVar7) * -0.9) / (float)*(int *)(iVar9 + 0x34 + DAT_005090d0);
  *(undefined4 *)(param_1 + 0x60 + DAT_006a5c38) = 0;
  *(float *)(param_1 + 0x68 + DAT_006a5c38) =
       (float)(int)(0x1000 / (longlong)*(int *)(iVar9 + 0x34 + DAT_005090d0));
  return;
}

