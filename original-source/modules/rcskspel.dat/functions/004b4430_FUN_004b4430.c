/*
 * FUN_004b4430 at 004b4430
 * undefined FUN_004b4430(void)
 * Address ranges: 004b4430-004b44ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b4430(void)

{
  FUN_004afce0(s_Exiting_Sound_Lib_00500614);
  if (DAT_006ab7b4 != 0) {
    FUN_004afce0(s_Deleting_all_sound_buffers_005005f8);
    FUN_004b4130();
    FUN_004afce0(s_release_sound_buffers_005005e0);
    (**(code **)(*DAT_006ab788 + 8))(DAT_006ab788);
    FUN_004afce0(s_Discard_xvga_sound_buffer_005005c4);
    LocalReAlloc(DAT_006ab798,0,2);
    DAT_006ab7b4 = 0;
    DAT_006ab7b8 = 0;
    DAT_006ab7bc = 0;
    DAT_006ab7c0 = 0;
    DAT_006ab7c4 = 0;
  }
  return;
}

