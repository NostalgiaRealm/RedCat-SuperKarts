/*
 * FUN_004523d0 at 004523d0
 * undefined FUN_004523d0(void)
 * Address ranges: 004523d0-00452420
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004523d0(undefined4 param_1)

{
  int iVar1;
  
  FUN_004afce0(s_CBonusController__HasDropper_004f1c30);
  FUN_00452120(param_1);
  iVar1 = FUN_0044ff80();
  if (iVar1 != 2) {
    return 0;
  }
  iVar1 = FUN_004500b0();
  if ((iVar1 != 3) && (iVar1 = FUN_004500b0(), iVar1 != 4)) {
    return 0;
  }
  return 1;
}

