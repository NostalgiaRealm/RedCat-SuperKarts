/*
 * FUN_004140b0 at 004140b0
 * undefined FUN_004140b0(void)
 * Address ranges: 004140b0-00414150
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004140b0(int param_1)

{
  float *pfVar1;
  float fVar2;
  float10 fVar3;
  
  param_1 = param_1 * 0xd0;
  fVar2 = *(float *)(param_1 + 0x9c + DAT_0067ee20);
  pfVar1 = (float *)(param_1 + 0x9c + DAT_0067ee20);
  fVar3 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 - fVar3 * (float10)(fVar2 * 10.0));
  fVar2 = *(float *)(param_1 + 0xa4 + DAT_0067ee20);
  pfVar1 = (float *)(param_1 + 0xa4 + DAT_0067ee20);
  fVar3 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 - fVar3 * (float10)(fVar2 * 10.0));
  fVar2 = *(float *)(param_1 + 0xac + DAT_0067ee20);
  pfVar1 = (float *)(param_1 + 0xac + DAT_0067ee20);
  fVar3 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 - fVar3 * (float10)(fVar2 * 10.0));
  return;
}

