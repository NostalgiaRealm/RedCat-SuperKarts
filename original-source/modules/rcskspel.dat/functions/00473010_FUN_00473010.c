/*
 * FUN_00473010 at 00473010
 * undefined FUN_00473010(void)
 * Address ranges: 00473010-00473054
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473010(void)

{
  char cVar1;
  
  if (DAT_00544dcc != 0) {
    cVar1 = *(char *)(DAT_00544dcc + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544dcc + -1);
    }
    else {
      *(char *)(DAT_00544dcc + -1) = cVar1 + -1;
    }
  }
  DAT_00544dcc = 0;
  _DAT_00544dd0 = 0;
  DAT_00544dd4 = 0;
  return;
}

