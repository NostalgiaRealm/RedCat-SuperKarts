/*
 * FUN_00406320 at 00406320
 * undefined FUN_00406320(void)
 * Address ranges: 00406320-0040646b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00406320(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float local_18 [2];
  float local_10;
  
  iVar5 = *(int *)(param_1 * 0xd0 + 0x24 + DAT_0067ee20);
  iVar7 = DAT_00680ae0 + iVar5 * 0x50;
  iVar6 = *(int *)(iVar7 + 0x14);
  if ((((iVar6 < 0) && (iVar6 = *(int *)(iVar7 + 0x1c), iVar6 < 0)) &&
      (iVar6 = *(int *)(iVar7 + 0x18), iVar6 < 0)) && (iVar6 = *(int *)(iVar7 + 0x20), iVar6 < 0)) {
    iVar5 = FUN_00401320(param_1,local_18);
    if ((0x400 < iVar5) && (iVar5 < 0xc00)) {
      return 1;
    }
  }
  else {
    FUN_004113c0(iVar6,local_18);
    fVar2 = local_10;
    fVar1 = local_18[0];
    FUN_004113c0(iVar5,local_18);
    fVar1 = fVar1 - local_18[0];
    fVar2 = fVar2 - local_10;
    iVar5 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
    fVar3 = *param_2 - *(float *)(DAT_006a5c38 + iVar5 + 0x50 + iVar5 * 0xa8);
    fVar4 = param_2[2] - *(float *)(DAT_006a5c38 + iVar5 + 0x58 + iVar5 * 0xa8);
    if ((fVar3 * fVar1 + fVar4 * fVar2) /
        (SQRT(fVar1 * fVar1 + fVar2 * fVar2) + SQRT(fVar3 * fVar3 + fVar4 * fVar4)) < 0.0) {
      return 1;
    }
  }
  return 0;
}

