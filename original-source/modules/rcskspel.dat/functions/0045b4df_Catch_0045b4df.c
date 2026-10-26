/*
 * Catch@0045b4df at 0045b4df
 * undefined Catch@0045b4df(void)
 * Address ranges: 0045b4df-0045b4fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_0045b4df(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined1 **)(*(int *)(unaff_EBP + -0x18) + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afee0(puVar1);
  return 0x45b4ab;
}

