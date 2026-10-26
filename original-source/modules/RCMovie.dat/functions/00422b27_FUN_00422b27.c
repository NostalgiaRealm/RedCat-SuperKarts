/*
 * FUN_00422b27 at 00422b27
 * undefined4 __stdcall FUN_00422b27(void)
 * Address ranges: 00422b27-00422b64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00422b27(void)

{
  DAT_0043f818 = HeapAlloc(DAT_0043f81c,0,0x140);
  if (DAT_0043f818 == (LPVOID)0x0) {
    return 0;
  }
  DAT_0043f810 = 0;
  DAT_0043f814 = 0;
  DAT_0043f80c = DAT_0043f818;
  DAT_0043f804 = 0x10;
  return 1;
}

