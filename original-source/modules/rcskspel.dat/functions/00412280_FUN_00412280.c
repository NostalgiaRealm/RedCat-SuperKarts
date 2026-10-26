/*
 * FUN_00412280 at 00412280
 * undefined FUN_00412280(void)
 * Address ranges: 00412280-00412329
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00412280(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 extraout_ST0;
  
  uVar1 = FUN_0040c8f0();
  uVar2 = FUN_0040c900();
  if (0.0 < (float)param_2[0x26]) {
    fVar5 = (float10)FUN_00456a10(uVar1,uVar2);
    iVar4 = *param_2 * 0xd0 + DAT_0067ee20;
    iVar3 = FUN_0040c980();
    *(float *)(iVar4 + 0xa4) = (float)fVar5 * *(float *)(iVar3 + 8);
    FUN_0048f4e0();
    param_2[0x26] = (int)(float)((float10)(float)param_2[0x26] - extraout_ST0);
    return 1;
  }
  iVar4 = *param_2 * 0xd0 + DAT_0067ee20;
  iVar3 = FUN_0040c9a0();
  *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(iVar3 + 8);
  return 0;
}

