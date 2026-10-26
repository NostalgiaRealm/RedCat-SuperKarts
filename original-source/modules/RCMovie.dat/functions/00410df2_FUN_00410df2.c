/*
 * FUN_00410df2 at 00410df2
 * undefined __cdecl FUN_00410df2(undefined4 param_1, int param_2, int param_3, int param_4, undefined4 param_5, uint param_6)
 * Address ranges: 00410df2-00411067
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_00410df2(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,uint param_6)

{
  int local_10;
  int local_8;
  
  if ((param_2 < 0) || (DAT_00431b64 < param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_array_index__d_00433a00);
  }
  if (*(int *)(DAT_0043d6e8 + 0x1c + param_2 * 0x20) == 0) {
    FUN_0040187a((byte *)s__s__d____blt_with_unallocated_me_00433a34);
  }
  local_8 = *(int *)(DAT_0043d6e8 + 8 + param_2 * 0x20);
  local_10 = *(int *)(DAT_0043d6e8 + 0xc + param_2 * 0x20);
  if ((param_6 & 2) == 0) {
    param_3 = param_3 - *(int *)(DAT_0043d6e8 + 0x10 + param_2 * 0x20);
    param_4 = param_4 - *(int *)(DAT_0043d6e8 + 0x14 + param_2 * 0x20);
  }
  if ((param_6 & 1) == 0) {
    FUN_004150a0();
  }
  else {
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_00433a74);
    }
    if ((((DAT_0043d808 <= param_3 + local_8) && (param_3 <= DAT_0043d804)) &&
        (DAT_0043d80c <= param_4 + local_10)) && (param_4 <= DAT_0043d800)) {
      if (param_4 < DAT_0043d80c) {
        local_10 = local_10 - (DAT_0043d80c - param_4);
        param_4 = DAT_0043d80c;
        if (local_10 < 1) {
          return;
        }
      }
      if ((param_4 + local_10 <= DAT_0043d800) || (0 < DAT_0043d800 - param_4)) {
        if (param_3 < DAT_0043d808) {
          local_8 = local_8 - (DAT_0043d808 - param_3);
          param_3 = DAT_0043d808;
          if (local_8 < 1) {
            return;
          }
        }
        if ((param_3 + local_8 <= DAT_0043d804) || (0 < DAT_0043d804 - param_3)) {
          FUN_004150a0();
        }
      }
    }
  }
  return;
}

