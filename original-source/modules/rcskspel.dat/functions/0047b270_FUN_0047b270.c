/*
 * FUN_0047b270 at 0047b270
 * undefined FUN_0047b270(void)
 * Address ranges: 0047b270-0047b2b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047b270(void)

{
  char cVar1;
  
  if (DAT_00544fa4 != 0) {
    cVar1 = *(char *)(DAT_00544fa4 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544fa4 + -1);
    }
    else {
      *(char *)(DAT_00544fa4 + -1) = cVar1 + -1;
    }
  }
  DAT_00544fa4 = 0;
  _DAT_00544fa8 = 0;
  DAT_00544fac = 0;
  return;
}

