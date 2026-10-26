/*
 * FUN_00451370 at 00451370
 * undefined FUN_00451370(void)
 * Address ranges: 00451370-004513b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00451370(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004afce0(s_CBonusController__FindFreeShootB_004f1448);
  iVar1 = FUN_00452350();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004522e0(iVar3);
      iVar2 = FUN_0044fb40();
      if (iVar2 == 1) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return -1;
}

