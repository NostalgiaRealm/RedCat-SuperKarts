/*
 * Catch@00467ccc at 00467ccc
 * undefined Catch@00467ccc(void)
 * Address ranges: 00467ccc-00467cee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_00467ccc(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00459f40();
  puVar2 = *(undefined1 **)(iVar1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afee0(puVar2);
  return 0x467cbb;
}

