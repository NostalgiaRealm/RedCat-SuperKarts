/*
 * FUN_0040de93 at 0040de93
 * uint __cdecl FUN_0040de93(uint param_1, int param_2)
 * Address ranges: 0040de93-0040e0c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_0040de93(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (DAT_0043d720 == 0) {
    FUN_0040187a((byte *)s__s__d____error_please_use_get_xv_0043266c);
  }
  if (param_2 == 8) {
    if (DAT_0042c358 == 8) {
      return param_1;
    }
    if (DAT_0042c358 == 0x10) {
      local_c = (uint)*(byte *)(DAT_0043d760 + param_1 * 4);
      if (DAT_0043d758 != 0) {
        local_c = (int)(local_c * local_c) >> 8;
      }
      local_10 = (uint)*(byte *)(DAT_0043d760 + 1 + param_1 * 4);
      if (DAT_0043d758 != 0) {
        local_10 = (int)(local_10 * local_10) >> 8;
      }
      local_8 = (uint)*(byte *)(DAT_0043d760 + 2 + param_1 * 4);
      if (DAT_0043d758 != 0) {
        local_8 = (int)(local_8 * local_8) >> 8;
      }
      local_c = (int)local_c >> ((byte)DAT_0043d73c & 0x1f);
      iVar1 = (int)local_10 >> ((byte)DAT_0043d740 & 0x1f);
      iVar2 = (int)local_8 >> ((byte)DAT_0043d744 & 0x1f);
      if ((((param_1 != DAT_00434c50) && (local_c == DAT_0043db60)) && (iVar1 == DAT_0043db64)) &&
         (iVar2 == DAT_0043db68)) {
        local_c = DAT_0043db60 + 1;
      }
      return (local_c << ((byte)DAT_0043d748 & 0x1f)) + (iVar1 << ((byte)DAT_0043d74c & 0x1f)) +
             (iVar2 << ((byte)DAT_0043d750 & 0x1f));
    }
    if (DAT_0042c358 == 0x18) {
      return (uint)*(byte *)(DAT_0043d760 + param_1 * 4) << 0x10 |
             (uint)*(byte *)(DAT_0043d760 + 1 + param_1 * 4) << 8 |
             (uint)*(byte *)(DAT_0043d760 + 2 + param_1 * 4);
    }
  }
  else if (param_2 == 0x10) {
    if (DAT_0042c358 == 8) {
      FUN_0040187a((byte *)s_not_yet_supported_004326a4);
      return param_1;
    }
    if (DAT_0042c358 == 0x10) {
      return param_1;
    }
    if (DAT_0042c358 == 0x18) {
      return param_1;
    }
  }
  else if (param_2 == 0x18) {
    iVar1 = FUN_0040dce3(param_1);
    return (int)(short)iVar1;
  }
  return 0;
}

