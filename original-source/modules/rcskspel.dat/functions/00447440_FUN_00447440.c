/*
 * FUN_00447440 at 00447440
 * undefined FUN_00447440(void)
 * Address ranges: 00447440-0044744c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __fastcall FUN_00447440(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  return puVar1;
}

