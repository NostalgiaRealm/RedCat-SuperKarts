/*
 * FUN_0040d1b9 at 0040d1b9
 * undefined __stdcall FUN_0040d1b9(void)
 * Address ranges: 0040d1b9-0040d38c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d1b9(void)

{
  uint uVar1;
  int local_28;
  int local_24;
  undefined2 *local_20;
  undefined2 *local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  undefined2 *local_8;
  
  DAT_0043d6fc = (int *)FUN_004028e3(8,8);
  if (DAT_0043d754 == 0) {
    local_c = DAT_0042c4d0;
    local_10 = DAT_0042c4d0;
  }
  else {
    if (DAT_0043d754 != 1) {
      if (DAT_0043d754 != 4) goto LAB_0040d230;
      local_10 = FUN_0040de93(DAT_00438474,0x18);
      local_c = local_10;
    }
    local_10 = FUN_0040de93(DAT_0042c4d0,8);
    local_c = local_10;
  }
LAB_0040d230:
  local_24 = (**(code **)(*DAT_0043d6fc + 0x74))(DAT_0043d6fc,8,&local_10);
  if (local_24 != 0) {
    FUN_00401f61(local_24);
    FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_00432330);
  }
  local_8 = (undefined2 *)FUN_00402631(DAT_0043d6fc,&local_28);
  for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
    local_20 = local_8;
    local_1c = local_8;
    for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
      if (DAT_0043d754 == 0) {
        *(undefined *)local_1c = (&DAT_004322a8)[local_18 * 8 + local_14];
        local_1c = (undefined2 *)((int)local_1c + 1);
      }
      else if (DAT_0043d754 == 1) {
        uVar1 = FUN_0040de93((uint)(byte)(&DAT_004322a8)[local_18 * 8 + local_14],8);
        *local_20 = (short)uVar1;
        local_20 = local_20 + 1;
      }
      else if (DAT_0043d754 == 4) {
        uVar1 = FUN_0040de93(-(uint)((&DAT_004322a8)[local_18 * 8 + local_14] != '\0') &
                             DAT_00438474,0x18);
        *local_20 = (short)uVar1;
        local_20 = local_20 + 1;
      }
    }
    local_8 = (undefined2 *)((int)local_8 + local_28);
  }
  FUN_004027f9(DAT_0043d6fc,local_8);
  return;
}

