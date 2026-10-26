/*
 * FUN_00408860 at 00408860
 * undefined FUN_00408860(void)
 * Address ranges: 00408860-004088cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408860(int param_1)

{
  float *pfVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = (&DAT_00505108)[param_1 * 9] * 0xd0;
  pfVar1 = (float *)(iVar2 + 0xa4 + DAT_0067ee20);
  fVar3 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 - fVar3 * (float10)*pfVar1 * (float10)3.0);
  pfVar1 = (float *)(iVar2 + 0xac + DAT_0067ee20);
  fVar3 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 -
                   fVar3 * (float10)*(float *)(iVar2 + 0xac + DAT_0067ee20) * (float10)3.0);
  return;
}

