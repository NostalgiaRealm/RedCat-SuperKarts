/*
 * FUN_004273f0 at 004273f0
 * undefined FUN_004273f0(void)
 * Address ranges: 004273f0-00427454
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004273f0(void)

{
  int iVar1;
  
  iVar1 = DAT_0052d508;
  DAT_0052d4fc = __ftol();
  if (DAT_0052d4fc < 0) {
    DAT_0052d4fc = DAT_0052d4fc + iVar1;
    _DAT_0052d504 = (float)DAT_0052d4fc;
  }
  if (iVar1 <= DAT_0052d4fc) {
    DAT_0052d4fc = DAT_0052d4fc - iVar1;
    _DAT_0052d504 = (float)DAT_0052d4fc;
  }
  FUN_00427300();
  return;
}

