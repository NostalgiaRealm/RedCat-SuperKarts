/*
 * FUN_00481560 at 00481560
 * undefined FUN_00481560(void)
 * Address ranges: 00481560-004815a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00481560(void)

{
  char cVar1;
  
  if (DAT_00545054 != 0) {
    cVar1 = *(char *)(DAT_00545054 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00545054 + -1);
    }
    else {
      *(char *)(DAT_00545054 + -1) = cVar1 + -1;
    }
  }
  DAT_00545054 = 0;
  _DAT_00545058 = 0;
  DAT_0054505c = 0;
  return;
}

