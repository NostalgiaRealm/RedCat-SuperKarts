/*
 * FUN_00404e20 at 00404e20
 * undefined FUN_00404e20(void)
 * Address ranges: 00404e20-00404ea2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00404e20(int param_1,int param_2)

{
  int iVar1;
  float *pfVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  iVar1 = param_2 * 0x50 + 8 + DAT_00680ae0;
  pfVar2 = (float *)(param_1 * 0x50 + 8 + DAT_00680ae0);
  fVar3 = (float10)*pfVar2 - (float10)*(float *)(param_2 * 0x50 + 8 + DAT_00680ae0);
  fVar4 = (float10)pfVar2[1] - (float10)*(float *)(iVar1 + 4);
  fVar5 = (float10)pfVar2[2] - (float10)*(float *)(iVar1 + 8);
  return SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);
}

