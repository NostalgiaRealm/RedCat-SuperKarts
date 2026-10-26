/*
 * FUN_00479e10 at 00479e10
 * undefined FUN_00479e10(void)
 * Address ranges: 00479e10-00479e54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479e10(void)

{
  char cVar1;
  
  if (DAT_00544e8c != 0) {
    cVar1 = *(char *)(DAT_00544e8c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544e8c + -1);
    }
    else {
      *(char *)(DAT_00544e8c + -1) = cVar1 + -1;
    }
  }
  DAT_00544e8c = 0;
  _DAT_00544e90 = 0;
  DAT_00544e94 = 0;
  return;
}

