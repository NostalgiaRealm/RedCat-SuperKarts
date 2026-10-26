/*
 * Catch@00467d64 at 00467d64
 * undefined Catch@00467d64(void)
 * Address ranges: 00467d64-00467d86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * Catch_00467d64(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00459f40();
  puVar2 = *(undefined1 **)(iVar1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afee0(puVar2);
  return &DAT_00467dbf;
}

