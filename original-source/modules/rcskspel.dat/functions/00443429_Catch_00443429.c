/*
 * Catch@00443429 at 00443429
 * undefined Catch@00443429(void)
 * Address ranges: 00443429-00443446
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_00443429(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined1 **)(*(int *)(unaff_EBP + -0x18) + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afee0(puVar1);
  return 0x4433dc;
}

