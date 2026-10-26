/*
 * FUN_00481020 at 00481020
 * undefined FUN_00481020(void)
 * Address ranges: 00481020-00481064
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00481020(void)

{
  char cVar1;
  
  if (DAT_00545094 != 0) {
    cVar1 = *(char *)(DAT_00545094 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00545094 + -1);
    }
    else {
      *(char *)(DAT_00545094 + -1) = cVar1 + -1;
    }
  }
  DAT_00545094 = 0;
  _DAT_00545098 = 0;
  DAT_0054509c = 0;
  return;
}

