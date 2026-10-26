/*
 * Catch@00461649 at 00461649
 * undefined Catch@00461649(void)
 * Address ranges: 00461649-0046166b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_00461649(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00459f40();
  puVar2 = *(undefined1 **)(iVar1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afee0(puVar2);
  return 0x461638;
}

