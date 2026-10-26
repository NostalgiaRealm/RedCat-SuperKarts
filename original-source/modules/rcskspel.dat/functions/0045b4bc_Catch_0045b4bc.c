/*
 * Catch@0045b4bc at 0045b4bc
 * undefined Catch@0045b4bc(void)
 * Address ranges: 0045b4bc-0045b4de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 Catch_0045b4bc(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00459f40();
  puVar2 = *(undefined1 **)(iVar1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afee0(puVar2);
  return 0x45b4ab;
}

