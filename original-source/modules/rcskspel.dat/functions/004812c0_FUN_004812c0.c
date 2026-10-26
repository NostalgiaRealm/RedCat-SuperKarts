/*
 * FUN_004812c0 at 004812c0
 * undefined FUN_004812c0(void)
 * Address ranges: 004812c0-00481304
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004812c0(void)

{
  char cVar1;
  
  if (DAT_00545074 != 0) {
    cVar1 = *(char *)(DAT_00545074 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00545074 + -1);
    }
    else {
      *(char *)(DAT_00545074 + -1) = cVar1 + -1;
    }
  }
  DAT_00545074 = 0;
  _DAT_00545078 = 0;
  DAT_0054507c = 0;
  return;
}

