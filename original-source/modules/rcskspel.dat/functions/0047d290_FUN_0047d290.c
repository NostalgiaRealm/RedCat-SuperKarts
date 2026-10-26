/*
 * FUN_0047d290 at 0047d290
 * undefined FUN_0047d290(void)
 * Address ranges: 0047d290-0047d2d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047d290(void)

{
  char cVar1;
  
  if (DAT_00544fbc != 0) {
    cVar1 = *(char *)(DAT_00544fbc + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544fbc + -1);
    }
    else {
      *(char *)(DAT_00544fbc + -1) = cVar1 + -1;
    }
  }
  DAT_00544fbc = 0;
  _DAT_00544fc0 = 0;
  DAT_00544fc4 = 0;
  return;
}

