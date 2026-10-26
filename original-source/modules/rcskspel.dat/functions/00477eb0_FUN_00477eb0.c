/*
 * FUN_00477eb0 at 00477eb0
 * undefined FUN_00477eb0(void)
 * Address ranges: 00477eb0-00477ef4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477eb0(void)

{
  char cVar1;
  
  if (DAT_00544e0c != 0) {
    cVar1 = *(char *)(DAT_00544e0c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544e0c + -1);
    }
    else {
      *(char *)(DAT_00544e0c + -1) = cVar1 + -1;
    }
  }
  DAT_00544e0c = 0;
  _DAT_00544e10 = 0;
  DAT_00544e14 = 0;
  return;
}

