/*
 * FUN_00497bd0 at 00497bd0
 * undefined FUN_00497bd0(void)
 * Address ranges: 00497bd0-00497c9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00497bd0(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = FUN_00490ce0();
  iVar6 = FUN_00490ce0();
  iVar1 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
  iVar7 = DAT_006a5c38 + *(int *)(param_2 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  fVar2 = *(float *)(DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8) - *(float *)(iVar7 + 0x50);
  fVar4 = *(float *)(DAT_006a5c38 + iVar1 + 0x58 + iVar1 * 0xa8) - *(float *)(iVar7 + 0x58);
  fVar3 = *(float *)(DAT_006a5ee0 + 0x74 + iVar6 * 0xbc) +
          *(float *)(DAT_006a5ee0 + 0x74 + iVar5 * 0xbc);
  if (fVar2 * fVar2 + fVar4 * fVar4 < fVar3 * fVar3) {
    return 1;
  }
  return 0;
}

