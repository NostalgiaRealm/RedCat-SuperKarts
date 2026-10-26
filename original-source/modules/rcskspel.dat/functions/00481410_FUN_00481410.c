/*
 * FUN_00481410 at 00481410
 * undefined FUN_00481410(void)
 * Address ranges: 00481410-00481454
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00481410(void)

{
  char cVar1;
  
  if (DAT_00545064 != 0) {
    cVar1 = *(char *)(DAT_00545064 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00545064 + -1);
    }
    else {
      *(char *)(DAT_00545064 + -1) = cVar1 + -1;
    }
  }
  DAT_00545064 = 0;
  _DAT_00545068 = 0;
  DAT_0054506c = 0;
  return;
}

