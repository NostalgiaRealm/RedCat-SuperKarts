/*
 * FUN_004130e0 at 004130e0
 * undefined FUN_004130e0(void)
 * Address ranges: 004130e0-004131ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004130e0(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  
  param_1 = param_1 * 0xd0;
  pfVar1 = (float *)(param_1 + 0xa8 + DAT_0067ee20);
  fVar2 = *pfVar1;
  fVar3 = *(float *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x74);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)(fVar5 * (float10)(fVar2 * -3.0 - fVar3 * 3.0) + (float10)*pfVar1);
  pfVar1 = (float *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x74);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)(fVar5 * (float10)*(float *)(param_1 + 0xa8 + DAT_0067ee20) + (float10)*pfVar1);
  iVar4 = FUN_004be6c9();
  if (iVar4 % 10 < 5) {
    pfVar1 = (float *)(param_1 + 0xa8 + DAT_0067ee20);
    fVar5 = (float10)FUN_0048f4e0();
    *pfVar1 = (float)(fVar5 * (float10)*(float *)(param_1 + 0xa4 + DAT_0067ee20) * (float10)4.0 +
                     (float10)*pfVar1);
    return;
  }
  pfVar1 = (float *)(param_1 + 0xa8 + DAT_0067ee20);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 -
                   fVar5 * (float10)*(float *)(param_1 + 0xa4 + DAT_0067ee20) * (float10)4.0);
  return;
}

