/*
 * FUN_0040e321 at 0040e321
 * undefined __stdcall FUN_0040e321(void)
 * Address ranges: 0040e321-0040e543
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040e321(void)

{
  int iVar1;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004028c2(DAT_00438434);
  _memset(&DAT_0043d700,0,0x20);
  _DAT_0043d700 = 0x20;
  iVar1 = (**(code **)(*DAT_00438434 + 0x54))(DAT_00438434,&DAT_0043d700);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____unable_to_get_pixelform_0043278c);
  }
  if ((DAT_0043d704 & 0x20) == 0) {
    local_c = 0;
    for (local_14 = DAT_0043d710; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d748 = local_c;
    local_c = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_c = local_c + 1;
    }
    DAT_0043d724 = local_c;
    DAT_0043d73c = 8 - local_c;
    _DAT_0043d730 = DAT_0043d710;
    local_10 = 0;
    for (local_14 = DAT_0043d714; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d74c = local_10;
    local_10 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_10 = local_10 + 1;
    }
    DAT_0043d728 = local_10;
    DAT_0043d740 = 8 - local_10;
    _DAT_0043d734 = DAT_0043d714;
    local_8 = 0;
    for (local_14 = DAT_0043d718; (local_14 & 1) == 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d750 = local_8;
    local_8 = 0;
    for (; (local_14 & 1) != 0; local_14 = (int)local_14 >> 1) {
      local_8 = local_8 + 1;
    }
    DAT_0043d72c = local_8;
    DAT_0043d744 = 8 - local_8;
    _DAT_0043d738 = DAT_0043d718;
  }
  else {
    DAT_0043d754 = 0;
  }
  DAT_0043d720 = 1;
  return;
}

