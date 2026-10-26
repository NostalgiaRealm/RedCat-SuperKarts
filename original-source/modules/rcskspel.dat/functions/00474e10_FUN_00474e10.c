/*
 * FUN_00474e10 at 00474e10
 * undefined FUN_00474e10(void)
 * Address ranges: 00474e10-00474e54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00474e10(void)

{
  char cVar1;
  
  if (DAT_00544de4 != 0) {
    cVar1 = *(char *)(DAT_00544de4 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544de4 + -1);
    }
    else {
      *(char *)(DAT_00544de4 + -1) = cVar1 + -1;
    }
  }
  DAT_00544de4 = 0;
  _DAT_00544de8 = 0;
  DAT_00544dec = 0;
  return;
}

