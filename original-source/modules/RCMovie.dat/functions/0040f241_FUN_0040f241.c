/*
 * FUN_0040f241 at 0040f241
 * int __stdcall FUN_0040f241(void)
 * Address ranges: 0040f241-0040f26b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040f241(void)

{
  int iVar1;
  
  if (DAT_0043d7f4 < DAT_0043d7f0) {
    iVar1 = DAT_0043d7f4;
    DAT_0043d7f4 = DAT_0043d7f4 + 1;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

