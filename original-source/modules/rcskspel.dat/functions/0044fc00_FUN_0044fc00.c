/*
 * FUN_0044fc00 at 0044fc00
 * undefined FUN_0044fc00(void)
 * Address ranges: 0044fc00-0044fc23
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044fc00(void)

{
  int iVar1;
  
  iVar1 = FUN_0044fb50();
  if (iVar1 != 1) {
    iVar1 = FUN_0044fb50();
    if (iVar1 != 2) {
      return 0;
    }
  }
  return 1;
}

