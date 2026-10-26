/*
 * FUN_0040173e at 0040173e
 * undefined __stdcall FUN_0040173e(void)
 * Address ranges: 0040173e-00401879
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040173e(void)

{
  int iVar1;
  
  FUN_0040d190();
  FUN_0040cb40();
  if (DAT_00438454 != 0) {
    FUN_0040b918();
    if (DAT_00438458 != 0) {
      FUN_004015a6((byte *)s_Releasing_screen_0042c518);
      (**(code **)(*DAT_00438434 + 8))(DAT_00438434);
      DAT_00438434 = (int *)0x0;
      DAT_00438458 = 0;
    }
    if ((DAT_0043845c != 0) && (DAT_0042c360 == 0)) {
      FUN_004015a6((byte *)s_Releasing_buffer_screen_0042c52c);
      (**(code **)(*DAT_00438438 + 8))(DAT_00438438);
      DAT_00438438 = (int *)0x0;
      DAT_0043845c = 0;
    }
    if (DAT_00438460 != 0) {
      FUN_004015a6((byte *)s_Releasing_buffer_screen_0042c548);
      (**(code **)(*DAT_00438418 + 8))(DAT_00438418);
      DAT_00438418 = (int *)0x0;
      DAT_00438460 = 0;
    }
    FUN_004015a6((byte *)s_Releasing_dd_object_0042c564);
    (**(code **)(*DAT_00438414 + 8))(DAT_00438414);
    DAT_00438414 = (int *)0x0;
    DAT_00438454 = 0;
  }
  FUN_0040b542();
  FUN_004015a6((byte *)s_post_quit_0042c57c);
  PostMessageA(DAT_0043842c,0x10,0,0);
  do {
    iVar1 = FUN_0040a9d3();
  } while (iVar1 != 0);
  return;
}

