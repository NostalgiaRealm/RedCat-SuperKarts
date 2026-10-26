/*
 * Catch@00453f2b at 00453f2b
 * undefined Catch@00453f2b(void)
 * Address ranges: 00453f2b-00453f48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_00453f2b(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined1 **)(*(int *)(unaff_EBP + 8) + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afee0(puVar1);
  return 0x453f18;
}

