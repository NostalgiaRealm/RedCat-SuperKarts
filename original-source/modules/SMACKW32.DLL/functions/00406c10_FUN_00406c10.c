/*
 * FUN_00406c10 at 00406c10
 * undefined __stdcall FUN_00406c10(void)
 * Address ranges: 00406c10-00406c2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406c10(void)

{
  if ((HMODULE)0x1f < DAT_0040e888) {
    FreeLibrary(DAT_0040e888);
    DAT_0040e888 = (HMODULE)0x0;
  }
  return;
}

