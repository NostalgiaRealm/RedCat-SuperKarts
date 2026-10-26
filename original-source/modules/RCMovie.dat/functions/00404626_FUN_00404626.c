/*
 * FUN_00404626 at 00404626
 * undefined4 __cdecl FUN_00404626(int param_1)
 * Address ranges: 00404626-00404789
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00404626(int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (0x12 < param_1)) {
    FUN_0040187a((byte *)s__s__d____error_predefined_screen_0042de48);
  }
  iVar1 = FUN_0040f789(DAT_0042c34c);
  if (iVar1 == 0) {
    FUN_0040187a((byte *)s__s__d____mode_is_not_available_0042de98);
  }
  FUN_00403e9a();
  FUN_004015a6((byte *)s_Setting_display_mode_0042debc);
  DAT_0042c34c = param_1;
  DAT_0042c350 = *(int *)(&DAT_0042c368 + param_1 * 0x14);
  DAT_0042c354 = *(int *)(&DAT_0042c36c + param_1 * 0x14);
  DAT_0042c358 = *(undefined4 *)(&DAT_0042c370 + param_1 * 0x14);
  DAT_00438468 = *(undefined4 *)(&DAT_0042c374 + param_1 * 0x14);
  FUN_004015a6((byte *)s_Setting_display_mode___dx_dx_d_0042ded4);
  iVar1 = (**(code **)(*DAT_0043841c + 0x54))
                    (DAT_0043841c,DAT_0042c350,DAT_0042c354,DAT_0042c358,0,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_display_m_0042df00);
  }
  FUN_004015a6((byte *)s_Setting_display_mode_done_0042df2c);
  FUN_0040f7fd(0,0,DAT_0042c350,DAT_0042c354);
  FUN_004037f0();
  return 0;
}

