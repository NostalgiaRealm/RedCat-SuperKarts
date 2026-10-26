/*
 * Catch@0046551a at 0046551a
 * undefined Catch@0046551a(void)
 * Address ranges: 0046551a-0046553c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_0046551a(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00459f40();
  puVar2 = *(undefined1 **)(iVar1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afee0(puVar2);
  return 0x465509;
}

