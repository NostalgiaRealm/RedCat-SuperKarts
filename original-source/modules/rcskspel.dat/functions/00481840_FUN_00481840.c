/*
 * FUN_00481840 at 00481840
 * undefined FUN_00481840(void)
 * Address ranges: 00481840-00481866
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00481840(void)

{
  int iVar1;
  
  iVar1 = FUN_00428df0();
  if (iVar1 != 3) {
    iVar1 = FUN_00428df0();
    if (iVar1 != 4) {
      iVar1 = FUN_00428df0();
      if (iVar1 != 6) {
        return 0;
      }
    }
  }
  return 1;
}

