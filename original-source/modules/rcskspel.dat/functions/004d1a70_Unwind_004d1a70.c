/*
 * Unwind@004d1a70 at 004d1a70
 * undefined Unwind@004d1a70(void)
 * Address ranges: 004d1a70-004d1a89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void Unwind_004d1a70(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_004bc69b();
    return;
  }
  return;
}

