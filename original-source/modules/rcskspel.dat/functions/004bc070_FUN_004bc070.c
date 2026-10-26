/*
 * FUN_004bc070 at 004bc070
 * undefined FUN_004bc070(void)
 * Address ranges: 004bc070-004bc089
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bc070(void)

{
  if (DAT_006b5d3c != (int *)0x0) {
    (**(code **)(*DAT_006b5d3c + 8))(DAT_006b5d3c);
    DAT_006b5d3c = (int *)0x0;
  }
  return;
}

