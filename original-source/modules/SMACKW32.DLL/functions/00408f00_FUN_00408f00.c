/*
 * FUN_00408f00 at 00408f00
 * undefined __stdcall FUN_00408f00(void)
 * Address ranges: 00408f00-00408f49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408f00(void)

{
  char cVar1;
  
  if (DAT_0040f0c4 == '\0') {
    DAT_0040f0c5 = DAT_0040f0c4;
    cVar1 = FUN_00408ec5();
    if (DAT_0040f03c == '\0') {
      DAT_0040f0c4 = cVar1;
      DAT_0040f0c5 = cVar1;
    }
  }
  return;
}

