/*
 * FUN_004105ee at 004105ee
 * undefined __cdecl FUN_004105ee(int param_1, int param_2, int param_3, int param_4, uint param_5)
 * Address ranges: 004105ee-00410df1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004105ee(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x1008000;
  if ((param_2 < 0) || (DAT_00431b64 < param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_array_index__d_0043371c);
  }
  if (*(int *)(DAT_0043d6e8 + 0x1c + param_2 * 0x20) == 0) {
    FUN_0040187a((byte *)s__s__d____blt_with_unallocated_me_00433750);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_2 * 0x20) == 4) {
    if (param_1 == 0) {
      local_8 = FUN_0040235c(DAT_00438434);
      local_18 = DAT_004383b4;
    }
    else if (param_1 == 1) {
      local_8 = FUN_0040235c(DAT_00438438);
      local_18 = DAT_00438420;
    }
    else if (param_1 == 2) {
      local_8 = FUN_0040235c(DAT_00438418);
      local_18 = DAT_00438430;
    }
    else {
      FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00433790);
    }
    local_10 = *(int *)(DAT_0043d6e8 + 8 + param_2 * 0x20);
    local_1c = *(int *)(DAT_0043d6e8 + 0xc + param_2 * 0x20);
    if ((param_5 & 2) == 0) {
      param_3 = param_3 - *(int *)(DAT_0043d6e8 + 0x10 + param_2 * 0x20);
      param_4 = param_4 - *(int *)(DAT_0043d6e8 + 0x14 + param_2 * 0x20);
    }
    local_14 = *(int *)(DAT_0043d6e8 + param_2 * 0x20);
    if ((param_5 & 1) == 0) {
      FUN_004150a0();
    }
    else {
      local_20 = 0;
      if (DAT_0043d814 == 0) {
        FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_004337cc);
      }
      if (param_3 + local_10 < DAT_0043d808) {
        return;
      }
      if (DAT_0043d804 < param_3) {
        return;
      }
      if (param_4 + local_1c < DAT_0043d80c) {
        return;
      }
      if (DAT_0043d800 < param_4) {
        return;
      }
      if (param_4 < DAT_0043d80c) {
        local_24 = local_10 * (DAT_0043d80c - param_4);
        local_14 = local_14 + local_24;
        local_1c = local_1c - (DAT_0043d80c - param_4);
        param_4 = DAT_0043d80c;
        if (local_1c < 1) {
          return;
        }
      }
      if ((DAT_0043d800 < param_4 + local_1c) && (local_1c = DAT_0043d800 - param_4, local_1c < 1))
      {
        return;
      }
      if (param_3 < DAT_0043d808) {
        local_20 = DAT_0043d808 - param_3;
        local_14 = local_14 + local_20;
        local_10 = local_10 - local_20;
        param_3 = DAT_0043d808;
        if (local_10 < 1) {
          return;
        }
      }
      if (DAT_0043d804 < param_3 + local_10) {
        local_20 = local_10 - (DAT_0043d804 - param_3);
        local_10 = DAT_0043d804 - param_3;
        if (local_10 < 1) {
          return;
        }
      }
      FUN_004150a0();
    }
    if (param_1 == 0) {
      FUN_004027f9(DAT_00438434,local_8);
    }
    else if (param_1 == 1) {
      FUN_004027f9(DAT_00438438,local_8);
    }
    else if (param_1 == 2) {
      FUN_004027f9(DAT_00438418,local_8);
    }
    else {
      FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00433800);
    }
    return;
  }
  local_38 = 0;
  local_50 = 0;
  if ((param_5 & 4) != 0) {
    local_c = 0x1000000;
  }
  local_10 = *(int *)(DAT_0043d6e8 + 8 + param_2 * 0x20);
  local_1c = *(int *)(DAT_0043d6e8 + 0xc + param_2 * 0x20);
  if ((param_5 & 2) == 0) {
    param_3 = param_3 - *(int *)(DAT_0043d6e8 + 0x10 + param_2 * 0x20);
    param_4 = param_4 - *(int *)(DAT_0043d6e8 + 0x14 + param_2 * 0x20);
  }
  if (DAT_0043d814 == 0) {
    FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_0043383c);
  }
  if (param_3 + local_10 < DAT_0043d808) {
    return;
  }
  if (DAT_0043d804 < param_3) {
    return;
  }
  if (param_4 + local_1c < DAT_0043d80c) {
    return;
  }
  if (DAT_0043d800 < param_4) {
    return;
  }
  if (param_4 < DAT_0043d80c) {
    local_50 = DAT_0043d80c - param_4;
    local_1c = local_1c - local_50;
    param_4 = DAT_0043d80c;
    if (local_1c < 1) {
      return;
    }
  }
  if ((DAT_0043d800 < param_4 + local_1c) && (local_1c = DAT_0043d800 - param_4, local_1c < 1)) {
    return;
  }
  if (param_3 < DAT_0043d808) {
    local_38 = DAT_0043d808 - param_3;
    local_10 = local_10 - local_38;
    param_3 = DAT_0043d808;
    if (local_10 < 1) {
      return;
    }
  }
  if ((DAT_0043d804 < param_3 + local_10) && (local_10 = DAT_0043d804 - param_3, local_10 < 1)) {
    return;
  }
  local_34 = param_3;
  local_2c = param_3 + local_10;
  local_30 = param_4;
  local_28 = param_4 + local_1c;
  local_48 = local_38;
  local_40 = local_38 + local_10;
  local_44 = local_50;
  local_3c = local_50 + local_1c;
  iVar1 = (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_2 * 0x20) + 0x60))
                    (*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20));
  if (iVar1 != 0) {
    FUN_004015a6((byte *)s__s__d____had_to_restore__d_00433870);
    (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_2 * 0x20) + 0x6c))
              (*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20));
  }
  if (param_1 == 0) {
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                      (DAT_00438434,&local_34,*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20),
                       &local_48,local_c,0);
    if (iVar1 == 0) {
      return;
    }
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_s_004338a0);
    return;
  }
  if (param_1 == 1) {
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                      (DAT_00438438,&local_34,*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20),
                       &local_48,local_c,0);
    if (iVar1 == 0) {
      return;
    }
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433910);
    return;
  }
  if (param_1 != 2) {
    return;
  }
  FUN_004028c2(DAT_00438418);
  iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                    (DAT_00438418,&local_34,*(undefined4 *)(DAT_0043d6e8 + 4 + param_2 * 0x20),
                     &local_48,local_c,0);
  if (iVar1 == 0) {
    return;
  }
  FUN_00401f61(iVar1);
  FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433988);
  return;
}

