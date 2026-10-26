/*
 * FUN_0043f490 at 0043f490
 * undefined FUN_0043f490(void)
 * Address ranges: 0043f490-0043f625
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043f490(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  fVar4 = (float10)FUN_0048f4e0();
  param_1 = param_1 * 0xd0;
  iVar3 = DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9;
  fVar4 = (float10)60.0 / ((float10)1.0 / (fVar4 + (float10)0.01));
  *(float *)(iVar3 + 0x74) =
       (float)((float10)*(float *)(iVar3 + 0x68) * fVar4 + (float10)*(float *)(iVar3 + 0x74));
  iVar2 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  iVar3 = DAT_006a5c38 + iVar2 + iVar2 * 0xa8;
  *(float *)(iVar3 + 0x78) =
       (float)((float10)*(float *)(DAT_006a5c38 + iVar2 + 0x6c + iVar2 * 0xa8) * fVar4 +
              (float10)*(float *)(iVar3 + 0x78));
  iVar2 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  iVar3 = DAT_006a5c38 + iVar2 + iVar2 * 0xa8;
  *(float *)(iVar3 + 0x7c) =
       (float)((float10)*(float *)(DAT_006a5c38 + iVar2 + 0x70 + iVar2 * 0xa8) * fVar4 +
              (float10)*(float *)(iVar3 + 0x7c));
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8);
  if (4096.0 < *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8)) {
    *pfVar1 = *pfVar1 - 4096.0;
  }
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8);
  if (4096.0 < *(float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8)) {
    *pfVar1 = *pfVar1 - 4096.0;
  }
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar3 + 0x7c + iVar3 * 0xa8);
  if (4096.0 < *(float *)(DAT_006a5c38 + iVar3 + 0x7c + iVar3 * 0xa8)) {
    *pfVar1 = *pfVar1 - 4096.0;
  }
  FUN_004a09e0();
  return 1;
}

