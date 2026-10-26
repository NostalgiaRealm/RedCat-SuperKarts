/*
 * FUN_0040a616 at 0040a616
 * undefined4 __cdecl FUN_0040a616(undefined4 param_1, int param_2, int param_3, int param_4, int param_5, undefined4 param_6, int param_7)
 * Address ranges: 0040a616-0040a7d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_0040a616(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)

{
  if (DAT_0043d514 == 0) {
    FUN_0040187a((byte *)s__s__d_____playing_smacker__Smack_004314e0);
  }
  DAT_0043d510 = _SmackOpen_12(param_1,0xfe000,0xffffffff);
  if (DAT_0043d510 == 0) {
    FUN_004015a6((byte *)s_failed_to_open_smacker_file__s__00431518);
  }
  else {
    if (param_4 == -1) {
      param_4 = *(int *)(DAT_0043d510 + 4);
    }
    if (param_5 == -1) {
      param_5 = *(int *)(DAT_0043d510 + 8);
    }
    if (param_2 == -1) {
      param_2 = (DAT_0042c350 - param_4) / 2;
    }
    if (param_3 == -1) {
      param_3 = (DAT_0042c354 - param_5) / 2;
    }
    if ((((param_2 < 0) || (param_3 < 0)) || (param_4 < 1)) || (param_5 < 1)) {
      FUN_0040187a((byte *)s__s__d____x_or_y_is_not_on_the_sc_00431548);
    }
    if ((DAT_0042c350 < param_2 + param_4) || (DAT_0042c354 < param_3 + param_5)) {
      FUN_0040187a((byte *)s__s__d____the_smacker_is_bigger_t_0043159c);
    }
    DAT_0043d51c = 1;
    DAT_0043d518 = 0;
    if ((param_4 == *(int *)(DAT_0043d510 + 4)) && (param_5 == *(int *)(DAT_0043d510 + 8))) {
      FUN_0040a408(param_2,param_3,param_4,param_5,param_7);
    }
    else {
      FUN_0040a408(param_2,param_3,param_4,param_5,param_7);
    }
    FUN_004015a6((byte *)s_closing_smacker_004315e0);
    _SmackClose_4(DAT_0043d510);
    FUN_004015a6((byte *)s_closing_smacker_done_004315f4);
  }
  return 0;
}

