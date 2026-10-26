/*
 * FUN_00481170 at 00481170
 * undefined FUN_00481170(void)
 * Address ranges: 00481170-004811b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00481170(void)

{
  char cVar1;
  
  if (DAT_00545084 != 0) {
    cVar1 = *(char *)(DAT_00545084 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00545084 + -1);
    }
    else {
      *(char *)(DAT_00545084 + -1) = cVar1 + -1;
    }
  }
  DAT_00545084 = 0;
  _DAT_00545088 = 0;
  DAT_0054508c = 0;
  return;
}

