/*
 * FUN_00405da0 at 00405da0
 * undefined __stdcall FUN_00405da0(void)
 * Address ranges: 00405da0-00405dbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405da0(void)

{
  if ((HMODULE)0x1f < DAT_0040e85c) {
    FreeLibrary(DAT_0040e85c);
    DAT_0040e85c = (HMODULE)0x0;
  }
  return;
}

