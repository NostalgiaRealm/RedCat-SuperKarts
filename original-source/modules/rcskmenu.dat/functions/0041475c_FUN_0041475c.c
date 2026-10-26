/*
 * FUN_0041475c at 0041475c
 * undefined __register FUN_0041475c(void)
 * Address ranges: 0041475c-00414777
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041475c(void)

{
  if (DAT_0047d64c != (HWND)0x0) {
    DestroyWindow(DAT_0047d64c);
    DAT_0047d64c = (HWND)0x0;
  }
  return;
}

