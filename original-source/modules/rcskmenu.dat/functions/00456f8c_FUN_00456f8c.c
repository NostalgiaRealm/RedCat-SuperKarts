/*
 * FUN_00456f8c at 00456f8c
 * undefined __register FUN_00456f8c(void)
 * Address ranges: 00456f8c-00456fc7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00456f8c(void)

{
  double *pdVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = 0;
  pdVar1 = (double *)&DAT_0047d954;
  do {
    fVar3 = _DAT_00456fd0 * ((float10)iVar2 / (float10)256.0) * (float10)2.0;
    FUN_00402978();
    *pdVar1 = (double)fVar3;
    iVar2 = iVar2 + 1;
    pdVar1 = pdVar1 + 1;
  } while (iVar2 != 0x100);
  return;
}

