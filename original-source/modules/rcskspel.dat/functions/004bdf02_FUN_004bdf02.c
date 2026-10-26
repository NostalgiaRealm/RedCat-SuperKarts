/*
 * FUN_004bdf02 at 004bdf02
 * undefined FUN_004bdf02(void)
 * Address ranges: 004bdf02-004bdf0e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __fastcall FUN_004bdf02(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  return puVar1;
}

