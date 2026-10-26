/*
 * FUN_00404863 at 00404863
 * undefined4 __stdcall FUN_00404863(void)
 * Address ranges: 00404863-004049ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00404863(void)

{
  int iVar1;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_0042c4d0;
  local_c = DAT_0042c4d0;
  if (DAT_0042dfa4 == 1) {
    DAT_004384a8 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    if (DAT_004384a8 == (HCURSOR)0x0) {
      FUN_0040187a((byte *)s__s__d_____init_mouse__Unable_to_l_0042e090);
    }
  }
  else if (DAT_0042dfa4 == 2) {
    if (DAT_0042df9c == -1) {
      FUN_0040187a((byte *)s__s__d_____init_mouse__No_mouse_a_0042e0dc);
    }
    DAT_004384ac = (int *)FUN_004028e3(0x40,0x40);
    if (DAT_0043d754 == 0) {
      local_8 = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_8 = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_8 = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_c = local_8;
    iVar1 = (**(code **)(*DAT_004384ac + 0x74))(DAT_004384ac,8,&local_c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042e11c);
    }
  }
  DAT_00438488 = 1;
  return 1;
}

