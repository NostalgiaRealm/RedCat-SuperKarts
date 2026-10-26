/*
 * FUN_004afdd0 at 004afdd0
 * undefined FUN_004afdd0(void)
 * Address ranges: 004afdd0-004afed4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004afdd0(void)

{
  int iVar1;
  
  FUN_004bc070();
  FUN_004b8380();
  if (DAT_006a64dc != 0) {
    FUN_004bbff0();
    if (DAT_006a64e0 != 0) {
      FUN_004afce0(s_Releasing_screen_004feb74);
      (**(code **)(*DAT_006a64bc + 8))(DAT_006a64bc);
      DAT_006a64bc = (int *)0x0;
      DAT_006a64e0 = 0;
    }
    if ((DAT_006a64e4 != 0) && (DAT_004fe940 == 0)) {
      FUN_004afce0(s_Releasing_buffer_screen_004feb58);
      (**(code **)(*DAT_006a64c0 + 8))(DAT_006a64c0);
      DAT_006a64c0 = (int *)0x0;
      DAT_006a64e4 = 0;
    }
    if (DAT_006a64e8 != 0) {
      FUN_004afce0(s_Releasing_buffer_screen_004feb58);
      (**(code **)(*DAT_006a64a0 + 8))(DAT_006a64a0);
      DAT_006a64a0 = (int *)0x0;
      DAT_006a64e8 = 0;
    }
    FUN_004afce0(s_Releasing_dd_object_004feb40);
    (**(code **)(*DAT_006a649c + 8))(DAT_006a649c);
    DAT_006a649c = (int *)0x0;
    DAT_006a64dc = 0;
  }
  FUN_004bbf30();
  FUN_004afce0(s_post_quit_004feb34);
  PostMessageA(DAT_006a64b4,0x10,0,0);
  iVar1 = FUN_004bb000();
  while (iVar1 != 0) {
    iVar1 = FUN_004bb000();
  }
  return;
}

