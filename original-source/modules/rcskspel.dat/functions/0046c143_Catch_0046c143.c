/*
 * Catch@0046c143 at 0046c143
 * undefined Catch@0046c143(void)
 * Address ranges: 0046c143-0046c160
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_0046c143(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined1 **)(*(int *)(unaff_EBP + -0x38) + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afee0(puVar1);
  return 0x46c11b;
}

