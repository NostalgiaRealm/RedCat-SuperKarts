/*
 * FUN_004165f0 at 004165f0
 * undefined FUN_004165f0(void)
 * Address ranges: 004165f0-00416619
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004165f0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004165a0();
  (&DAT_00507388)[iVar1 * 3] = 1;
  (&DAT_0050738c)[iVar1 * 3] = param_1;
  (&DAT_00507390)[iVar1 * 3] = param_2;
  return;
}

