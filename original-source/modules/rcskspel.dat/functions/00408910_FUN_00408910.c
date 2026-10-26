/*
 * FUN_00408910 at 00408910
 * undefined FUN_00408910(void)
 * Address ranges: 00408910-004089a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408910(int param_1)

{
  float *pfVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_0048f4e0();
  *(float *)(&DAT_00505124 + param_1 * 0x24) =
       (float)((float10)*(float *)(&DAT_00505124 + param_1 * 0x24) - fVar2);
  FUN_00408780(param_1);
  pfVar1 = (float *)((&DAT_00505108)[param_1 * 9] * 0xd0 + 0xac + DAT_0067ee20);
  fVar2 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 -
                   fVar2 * (float10)*(float *)((&DAT_00505108)[param_1 * 9] * 0xd0 + 0xac +
                                              DAT_0067ee20) * (float10)3.0);
  *(undefined4 *)((&DAT_00505108)[param_1 * 9] * 0xd0 + 0x48 + DAT_0067ee20) = 0;
  return;
}

