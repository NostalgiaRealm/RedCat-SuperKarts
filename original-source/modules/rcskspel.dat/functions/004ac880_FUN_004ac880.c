/*
 * FUN_004ac880 at 004ac880
 * undefined FUN_004ac880(void)
 * Address ranges: 004ac880-004ac8a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ac880(void)

{
  int iVar1;
  
  if (DAT_006a62e0 != 0) {
    iVar1 = (**(code **)(*DAT_006a62d8 + 0x60))(DAT_006a62d8);
    if (iVar1 != 0) {
      (**(code **)(*DAT_006a62d8 + 0x6c))(DAT_006a62d8);
    }
  }
  return;
}

