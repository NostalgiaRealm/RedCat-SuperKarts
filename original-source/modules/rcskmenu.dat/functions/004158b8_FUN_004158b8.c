/*
 * FUN_004158b8 at 004158b8
 * undefined __register FUN_004158b8(void)
 * Address ranges: 004158b8-004158ee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004158b8(void)

{
  if (DAT_0047d65c == (HMODULE)0x0) {
    DAT_0047d65c = GetModuleHandleA("comctl32.dll");
    if (DAT_0047d65c != (HMODULE)0x0) {
      DAT_0047d660 = GetProcAddress(DAT_0047d65c,"InitCommonControlsEx");
    }
  }
  return;
}

