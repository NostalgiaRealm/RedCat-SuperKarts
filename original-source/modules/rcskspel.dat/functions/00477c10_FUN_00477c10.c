/*
 * FUN_00477c10 at 00477c10
 * undefined FUN_00477c10(void)
 * Address ranges: 00477c10-00477c54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477c10(void)

{
  char cVar1;
  
  if (DAT_00544e2c != 0) {
    cVar1 = *(char *)(DAT_00544e2c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544e2c + -1);
    }
    else {
      *(char *)(DAT_00544e2c + -1) = cVar1 + -1;
    }
  }
  DAT_00544e2c = 0;
  _DAT_00544e30 = 0;
  DAT_00544e34 = 0;
  return;
}

