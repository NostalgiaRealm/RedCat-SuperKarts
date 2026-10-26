/*
 * FUN_00426b90 at 00426b90
 * undefined FUN_00426b90(void)
 * Address ranges: 00426b90-00426bf3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426b90(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00426540(param_1);
  *(undefined4 *)(&DAT_0050dfb0 + iVar1 * 0x1910) = 0;
  iVar1 = FUN_00426540(param_1);
  *(undefined4 *)(&DAT_0050f8b4 + iVar1 * 0x1910) = 0;
  iVar1 = FUN_00426540(param_1);
  *(undefined4 *)(&DAT_0050f8bc + iVar1 * 0x1910) = 0;
  return;
}

