/*
 * FUN_0043df90 at 0043df90
 * undefined FUN_0043df90(void)
 * Address ranges: 0043df90-0043e04e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043df90(int param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  FUN_00490ce0();
  iVar5 = FUN_00490ce0();
  iVar2 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
  iVar1 = *(int *)(param_2 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38;
  fVar3 = *(float *)(DAT_006a5c38 + iVar2 + 0x50 + iVar2 * 0xa8) - *(float *)(iVar1 + 0x50);
  fVar4 = *(float *)(DAT_006a5c38 + iVar2 + 0x58 + iVar2 * 0xa8) - *(float *)(iVar1 + 0x58);
  param_3 = *(float *)(DAT_006a5ee0 + 0x74 + iVar5 * 0xbc) + param_3;
  if (fVar3 * fVar3 + fVar4 * fVar4 < param_3 * param_3) {
    return 1;
  }
  return 0;
}

