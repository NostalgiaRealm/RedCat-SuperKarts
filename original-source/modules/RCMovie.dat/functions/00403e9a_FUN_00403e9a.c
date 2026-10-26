/*
 * FUN_00403e9a at 00403e9a
 * undefined __stdcall FUN_00403e9a(void)
 * Address ranges: 00403e9a-00403f3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403e9a(void)

{
  if (DAT_00438460 != 0) {
    FUN_004015a6((byte *)s_release_buffer_screen_0042d9e8);
    (**(code **)(*DAT_00438418 + 8))(DAT_00438418);
    DAT_00438460 = 0;
  }
  if ((DAT_0043845c != 0) && (DAT_0042c360 == 0)) {
    FUN_004015a6((byte *)s_release_back_screen_0042da00);
    (**(code **)(*DAT_00438438 + 8))(DAT_00438438);
    DAT_0043845c = 0;
  }
  if (DAT_00438458 != 0) {
    FUN_004015a6((byte *)s_release_primary_surface_0042da18);
    (**(code **)(*DAT_00438434 + 8))(DAT_00438434);
    DAT_00438458 = 0;
  }
  FUN_0040e7e0();
  return;
}

