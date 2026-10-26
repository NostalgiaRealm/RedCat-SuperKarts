/*
 * FUN_004816b0 at 004816b0
 * undefined FUN_004816b0(void)
 * Address ranges: 004816b0-004816f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004816b0(void)

{
  char cVar1;
  
  if (DAT_00545044 != 0) {
    cVar1 = *(char *)(DAT_00545044 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00545044 + -1);
    }
    else {
      *(char *)(DAT_00545044 + -1) = cVar1 + -1;
    }
  }
  DAT_00545044 = 0;
  _DAT_00545048 = 0;
  DAT_0054504c = 0;
  return;
}

