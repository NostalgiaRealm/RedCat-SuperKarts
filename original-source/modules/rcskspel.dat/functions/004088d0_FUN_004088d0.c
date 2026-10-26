/*
 * FUN_004088d0 at 004088d0
 * undefined FUN_004088d0(void)
 * Address ranges: 004088d0-00408903
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004088d0(int param_1)

{
  int iVar1;
  
  iVar1 = (&DAT_00505108)[param_1 * 9];
  *(undefined4 *)(iVar1 * 0xd0 + 0x48 + DAT_0067ee20) = 0;
  *(undefined4 *)(iVar1 * 0xd0 + 0x44 + DAT_0067ee20) = 1;
  return;
}

