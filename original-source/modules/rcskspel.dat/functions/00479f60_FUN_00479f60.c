/*
 * FUN_00479f60 at 00479f60
 * undefined FUN_00479f60(void)
 * Address ranges: 00479f60-00479fa4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479f60(void)

{
  char cVar1;
  
  if (DAT_00544e7c != 0) {
    cVar1 = *(char *)(DAT_00544e7c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544e7c + -1);
    }
    else {
      *(char *)(DAT_00544e7c + -1) = cVar1 + -1;
    }
  }
  DAT_00544e7c = 0;
  _DAT_00544e80 = 0;
  DAT_00544e84 = 0;
  return;
}

