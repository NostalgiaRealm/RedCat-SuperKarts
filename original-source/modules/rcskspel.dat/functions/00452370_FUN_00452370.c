/*
 * FUN_00452370 at 00452370
 * undefined FUN_00452370(void)
 * Address ranges: 00452370-004523c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00452370(undefined4 param_1)

{
  int iVar1;
  
  FUN_004afce0(s_CBonusController__HasShooter_004f1c10);
  FUN_00452120(param_1);
  iVar1 = FUN_0044ff80();
  if (iVar1 != 2) {
    return 0;
  }
  iVar1 = FUN_004500b0();
  if ((iVar1 != 1) && (iVar1 = FUN_004500b0(), iVar1 != 2)) {
    return 0;
  }
  return 1;
}

