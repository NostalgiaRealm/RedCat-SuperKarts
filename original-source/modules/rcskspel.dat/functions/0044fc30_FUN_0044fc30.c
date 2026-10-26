/*
 * FUN_0044fc30 at 0044fc30
 * undefined FUN_0044fc30(void)
 * Address ranges: 0044fc30-0044fc53
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044fc30(void)

{
  int iVar1;
  
  iVar1 = FUN_0044fb50();
  if (iVar1 != 3) {
    iVar1 = FUN_0044fb50();
    if (iVar1 != 4) {
      return 0;
    }
  }
  return 1;
}

