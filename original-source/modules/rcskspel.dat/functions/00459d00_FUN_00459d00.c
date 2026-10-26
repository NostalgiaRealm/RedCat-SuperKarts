/*
 * FUN_00459d00 at 00459d00
 * undefined FUN_00459d00(void)
 * Address ranges: 00459d00-00459d1a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00459d00(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0x38);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afce0(s_Name____s__Element__004f29cc,puVar1);
  return;
}

