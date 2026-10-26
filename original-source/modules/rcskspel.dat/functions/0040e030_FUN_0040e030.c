/*
 * FUN_0040e030 at 0040e030
 * undefined FUN_0040e030(void)
 * Address ranges: 0040e030-0040e06f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0040e030(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00410100();
  iVar1 = iVar1 + -1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  iVar2 = FUN_004be6c9();
  return iVar2 % 100 < iVar1;
}

