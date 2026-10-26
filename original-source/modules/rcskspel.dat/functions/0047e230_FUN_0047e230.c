/*
 * FUN_0047e230 at 0047e230
 * undefined FUN_0047e230(void)
 * Address ranges: 0047e230-0047e274
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047e230(void)

{
  char cVar1;
  
  if (DAT_0054502c != 0) {
    cVar1 = *(char *)(DAT_0054502c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_0054502c + -1);
    }
    else {
      *(char *)(DAT_0054502c + -1) = cVar1 + -1;
    }
  }
  DAT_0054502c = 0;
  _DAT_00545030 = 0;
  DAT_00545034 = 0;
  return;
}

