/*
 * FUN_004091b0 at 004091b0
 * undefined FUN_004091b0(void)
 * Address ranges: 004091b0-0040920d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004091b0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + param_1 * 0x24));
  if (*(int *)(&DAT_00505118 + param_1 * 0x24) == *(int *)(&DAT_0053f674 + iVar1 * 0x340)) {
    *(undefined4 *)((&DAT_00505108)[param_1 * 9] * 0xd0 + 0x44 + DAT_0067ee20) = 0;
    FUN_00407c60((&DAT_00505108)[param_1 * 9]);
  }
  return;
}

