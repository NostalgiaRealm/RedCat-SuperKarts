/*
 * Unwind@004d1be8 at 004d1be8
 * undefined Unwind@004d1be8(void)
 * Address ranges: 004d1be8-004d1c01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void Unwind_004d1be8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_004bd413();
    return;
  }
  return;
}

