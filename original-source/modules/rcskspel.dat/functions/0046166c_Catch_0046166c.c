/*
 * Catch@0046166c at 0046166c
 * undefined Catch@0046166c(void)
 * Address ranges: 0046166c-00461689
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_0046166c(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined1 **)(*(int *)(unaff_EBP + -0x48) + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afee0(puVar1);
  return 0x461638;
}

