/*
 * FUN_0040e544 at 0040e544
 * undefined __cdecl FUN_0040e544(undefined4 param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint param_5, uint param_6, uint param_7)
 * Address ranges: 0040e544-0040e6ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0040e544(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            uint param_6,uint param_7)

{
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_2 & 0x20) == 0) {
    local_c = 0;
    for (local_14 = param_5; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d748 = local_c;
    local_c = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d724 = local_c;
    DAT_0043d73c = 8 - local_c;
    _DAT_0043d730 = param_5;
    local_10 = 0;
    for (local_14 = param_6; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d74c = local_10;
    local_10 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d728 = local_10;
    DAT_0043d740 = 8 - local_10;
    _DAT_0043d734 = param_6;
    local_8 = 0;
    for (local_14 = param_7; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d750 = local_8;
    local_8 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d72c = local_8;
    DAT_0043d744 = 8 - local_8;
    _DAT_0043d738 = param_7;
    FUN_004015a6((byte *)s_RGB___d__d__d_004327b8);
  }
  return;
}

