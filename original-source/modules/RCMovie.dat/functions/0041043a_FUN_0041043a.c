/*
 * FUN_0041043a at 0041043a
 * undefined __cdecl FUN_0041043a(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
 * Address ranges: 0041043a-004105ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_0041043a(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  if (param_7 == 0) {
    FUN_004150a0();
  }
  else {
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_004336e8);
    }
    if ((((DAT_0043d808 <= param_3 + param_5) && (param_3 <= DAT_0043d804)) &&
        (DAT_0043d80c <= param_4 + param_6)) && (param_4 <= DAT_0043d800)) {
      if (param_4 < DAT_0043d80c) {
        param_6 = param_6 - (DAT_0043d80c - param_4);
        param_4 = DAT_0043d80c;
        if (param_6 < 1) {
          return;
        }
      }
      if ((param_4 + param_6 <= DAT_0043d800) || (0 < DAT_0043d800 - param_4)) {
        if (param_3 < DAT_0043d808) {
          param_5 = param_5 - (DAT_0043d808 - param_3);
          param_3 = DAT_0043d808;
          if (param_5 < 1) {
            return;
          }
        }
        if ((param_3 + param_5 <= DAT_0043d804) || (0 < DAT_0043d804 - param_3)) {
          FUN_004150a0();
        }
      }
    }
  }
  return;
}

