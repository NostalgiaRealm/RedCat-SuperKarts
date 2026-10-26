/*
 * FUN_004299d0 at 004299d0
 * undefined FUN_004299d0(void)
 * Address ranges: 004299d0-00429a56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004299d0(void)

{
  int iVar1;
  
  if (DAT_004e7bbc != 0) {
    FUN_004afce0(s_Stopping_all_sounds_004e8900);
  }
  FUN_004afce0(s_Clear_screen_on_exit_004e8918);
  iVar1 = (**(code **)(*DAT_006a64bc + 0x60))(DAT_006a64bc);
  if (iVar1 == 0) {
    FUN_004b0e90(DAT_004e7bec,0);
    FUN_004aff70();
    FUN_004b0e90(DAT_004e7bec,0);
    FUN_004aff70();
  }
  FUN_004afce0(s_Exit_fileio_004e8930);
  FUN_004b9970();
  FUN_0049e2d0();
  FUN_004afce0(s_Exit_xvga_lib_004e8940);
  FUN_004afdd0();
  return;
}

