/*
 * Catch@00465f0c at 00465f0c
 * undefined Catch@00465f0c(void)
 * Address ranges: 00465f0c-00465f2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_00465f0c(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00459f40();
  puVar2 = *(undefined1 **)(iVar1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afee0(puVar2);
  return 0x465efb;
}

