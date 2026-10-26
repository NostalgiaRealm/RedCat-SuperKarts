/*
 * FUN_0044da80 at 0044da80
 * undefined FUN_0044da80(void)
 * Address ranges: 0044da80-0044da8c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * __fastcall FUN_0044da80(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  return puVar1;
}

