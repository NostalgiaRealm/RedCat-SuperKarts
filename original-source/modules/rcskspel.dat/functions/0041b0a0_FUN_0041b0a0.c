/*
 * FUN_0041b0a0 at 0041b0a0
 * undefined FUN_0041b0a0(void)
 * Address ranges: 0041b0a0-0041b0c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b0a0(void)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  
  pfVar3 = (float *)&DAT_00506918;
  do {
    iVar2 = 6;
    pfVar1 = pfVar3;
    do {
      iVar2 = iVar2 + -1;
      *pfVar1 = *pfVar1 * 0.95;
      pfVar1 = pfVar1 + 1;
    } while (iVar2 != 0);
    pfVar3 = pfVar3 + 0x1f;
  } while ((int)pfVar3 < 0x5072c8);
  return;
}

