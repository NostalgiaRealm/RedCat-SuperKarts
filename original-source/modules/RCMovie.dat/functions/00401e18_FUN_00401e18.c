/*
 * FUN_00401e18 at 00401e18
 * undefined4 __cdecl FUN_00401e18(int param_1, uint param_2, int param_3)
 * Address ranges: 00401e18-00401f0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00401e18(int param_1,uint param_2,int param_3)

{
  if (param_1 == 0) {
    if (((int)param_2 < 0) || (0x12 < (int)param_2)) {
      FUN_0040187a((byte *)s__s__d____error_predefined_screen_0042c680);
    }
    DAT_0042c34c = param_2;
    DAT_0042c350 = *(undefined4 *)(&DAT_0042c368 + param_2 * 0x14);
    DAT_0042c354 = *(undefined4 *)(&DAT_0042c36c + param_2 * 0x14);
    DAT_0042c358 = *(undefined4 *)(&DAT_0042c370 + param_2 * 0x14);
    DAT_00438468 = *(undefined4 *)(&DAT_0042c374 + param_2 * 0x14);
  }
  else if (param_1 == 1) {
    if (param_3 == 1) {
      DAT_0042c35c = DAT_0042c35c | param_2;
    }
    else {
      DAT_0042c35c = param_2;
    }
  }
  else if (param_1 == 2) {
    DAT_0042c364 = param_2;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unknown_variable___d__r_0042c6d0);
  }
  return 0;
}

