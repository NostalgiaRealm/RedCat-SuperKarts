/*
 * FUN_00497ca0 at 00497ca0
 * undefined FUN_00497ca0(void)
 * Address ranges: 00497ca0-00497de0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00497ca0(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = FUN_00490ce0();
  param_2 = param_2 * 0xd0;
  iVar6 = FUN_00490ce0();
  iVar7 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38;
  iVar1 = *(int *)(param_2 + 0xc + DAT_0067ee20);
  fVar2 = *(float *)(iVar7 + 0x50) -
          (*(float *)(param_2 + 0x9c + DAT_0067ee20) * 0.5 +
          *(float *)(DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8));
  fVar4 = *(float *)(iVar7 + 0x58) -
          (*(float *)(param_2 + 0xa4 + DAT_0067ee20) * 0.5 +
          *(float *)(DAT_006a5c38 + iVar1 + 0x58 + iVar1 * 0xa8));
  fVar3 = (*(float *)(param_2 + 0xa0 + DAT_0067ee20) + *(float *)(param_2 + 0x9c + DAT_0067ee20)) *
          0.5 + *(float *)(DAT_006a5ee0 + 0x74 + iVar6 * 0xbc) * 1.25 +
                *(float *)(DAT_006a5ee0 + 0x74 + iVar5 * 0xbc) * 1.25;
  if (fVar2 * fVar2 + fVar4 * fVar4 < fVar3 * fVar3) {
    return 1;
  }
  return 0;
}

