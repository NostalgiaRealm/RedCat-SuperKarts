/*
 * FUN_0040f71c at 0040f71c
 * undefined4 __stdcall FUN_0040f71c(void)
 * Address ranges: 0040f71c-0040f788
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040f71c(void)

{
  int iVar1;
  
  FUN_004015a6((byte *)s_getting_screen_mode_info_0043313c);
  iVar1 = (**(code **)(*DAT_00438414 + 0x20))(DAT_00438414,0,0,0,FUN_0040f6a3);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_get_mode_info_00433164);
  }
  FUN_004015a6((byte *)s_done_getting_screen_mode_info_00433194);
  return 0;
}

