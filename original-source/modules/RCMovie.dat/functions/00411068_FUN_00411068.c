/*
 * FUN_00411068 at 00411068
 * undefined __cdecl FUN_00411068(int param_1, int param_2, int param_3, int param_4)
 * Address ranges: 00411068-00411527
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00411068(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_14 = 0;
  if ((param_2 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_character_index_00433a98);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_2 * 0xc);
  if ((iVar1 != 0) && (iVar1 == 1)) {
    local_c = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 4);
    local_10 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 8);
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_00433ae4);
    }
    if ((((DAT_0043d808 <= param_3 + local_c) && (param_3 <= DAT_0043d804)) &&
        (DAT_0043d80c <= param_4 + local_10)) && (param_4 <= DAT_0043d800)) {
      if (param_4 < DAT_0043d80c) {
        local_14 = DAT_0043d80c - param_4;
        local_10 = local_10 - local_14;
        param_4 = DAT_0043d80c;
        if (local_10 < 1) {
          return;
        }
      }
      if ((param_4 + local_10 <= DAT_0043d800) || (local_10 = DAT_0043d800 - param_4, 0 < local_10))
      {
        if (param_3 < DAT_0043d808) {
          local_8 = DAT_0043d808 - param_3;
          local_c = local_c - local_8;
          param_3 = DAT_0043d808;
          if (local_c < 1) {
            return;
          }
        }
        if ((param_3 + local_c <= DAT_0043d804) || (local_c = DAT_0043d804 - param_3, 0 < local_c))
        {
          if (DAT_004331f8 != 0) {
            param_3 = param_3 / 2 << 1;
          }
          local_24 = param_3;
          local_1c = param_3 + local_c;
          local_20 = param_4;
          local_18 = param_4 + local_10;
          local_34 = local_8;
          local_2c = local_8 + local_c;
          local_30 = local_14;
          local_28 = local_14 + local_10;
          iVar1 = (**(code **)(*(int *)**(undefined4 **)
                                         (*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 0x60))
                            (**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
          if (iVar1 != 0) {
            FUN_004015a6((byte *)s__s__d____had_to_restore__d_00433b18);
            (**(code **)(*(int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) +
                        0x6c))(**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
          }
          if (param_1 == 0) {
            FUN_004028c2(DAT_00438434);
            iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                              (DAT_00438434,&local_24,
                               **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),
                               &local_34,0x1008000,0);
            if (iVar1 != 0) {
              FUN_00401f61(iVar1);
              FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_s_00433b48);
            }
          }
          else if (param_1 == 1) {
            FUN_004028c2(DAT_00438438);
            iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                              (DAT_00438438,&local_24,
                               **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),
                               &local_34,0x1008000,0);
            if (iVar1 != 0) {
              FUN_00401f61(iVar1);
              FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433bb8);
            }
          }
          else if (param_1 == 2) {
            FUN_004028c2(DAT_00438418);
            iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                              (DAT_00438418,&local_24,
                               **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),
                               &local_34,0x1008000,0);
            if (iVar1 != 0) {
              FUN_00401f61(iVar1);
              FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433c30);
            }
          }
        }
      }
    }
  }
  return;
}

