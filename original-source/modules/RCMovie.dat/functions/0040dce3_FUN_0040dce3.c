/*
 * FUN_0040dce3 at 0040dce3
 * int __cdecl FUN_0040dce3(uint param_1)
 * Address ranges: 0040dce3-0040de92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040dce3(uint param_1)

{
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if (DAT_0043d720 == 0) {
    FUN_0040187a((byte *)s__s__d____error_please_use_get_xv_004325d4);
  }
  if (DAT_0042c358 == 8) {
    FUN_0040187a((byte *)s__s___d___Translation_from_24_bit_00432618);
  }
  else if ((DAT_0042c358 == 0x10) || (DAT_0042c358 == 0x18)) {
    if (param_1 == DAT_00438474) {
      local_10 = DAT_0043db60;
      local_14 = DAT_0043db64;
      local_c = DAT_0043db68;
    }
    else {
      local_10 = param_1 & 0xff;
      if (DAT_0043d758 != 0) {
        local_10 = (int)(local_10 * local_10) >> 8;
      }
      local_10 = (int)local_10 >> ((byte)DAT_0043d73c & 0x1f);
      local_14 = (int)(param_1 & 0xff00) >> 8;
      if (DAT_0043d758 != 0) {
        local_14 = local_14 * local_14 >> 8;
      }
      local_14 = local_14 >> ((byte)DAT_0043d740 & 0x1f);
      local_c = (int)(param_1 & 0xff0000) >> 0x10;
      if (DAT_0043d758 != 0) {
        local_c = local_c * local_c >> 8;
      }
      local_c = local_c >> ((byte)DAT_0043d744 & 0x1f);
    }
    if ((((local_10 == DAT_0043db60) && (local_14 == DAT_0043db64)) && (local_c == DAT_0043db68)) &&
       (param_1 != DAT_00438474)) {
      if (local_10 == 0) {
        local_10 = 1;
      }
      else {
        local_10 = local_10 + -1;
      }
    }
    local_8 = (local_10 << ((byte)DAT_0043d748 & 0x1f)) + (local_14 << ((byte)DAT_0043d74c & 0x1f))
              + (local_c << ((byte)DAT_0043d750 & 0x1f));
  }
  return local_8;
}

