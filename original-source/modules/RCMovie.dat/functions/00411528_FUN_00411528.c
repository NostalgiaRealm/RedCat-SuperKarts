/*
 * FUN_00411528 at 00411528
 * undefined __cdecl FUN_00411528(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
 * Address ranges: 00411528-004118dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00411528(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int local_3c;
  int local_38;
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
  local_1c = 0;
  if ((param_2 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_character_index_00433c98);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_2 * 0xc);
  if ((iVar1 != 0) && (iVar1 == 1)) {
    local_c = param_5;
    local_18 = param_6;
    local_14 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 4);
    local_10 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 8);
    if (DAT_004331f8 != 0) {
      param_3 = param_3 / 2 << 1;
    }
    local_2c = param_3;
    local_24 = param_3 + param_5;
    local_28 = param_4;
    local_20 = param_4 + param_6;
    local_3c = local_8;
    local_34 = local_8 + local_14;
    local_38 = local_1c;
    local_30 = local_1c + local_10;
    iVar1 = (**(code **)(*(int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) +
                        0x60))(**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
    if (iVar1 != 0) {
      FUN_004015a6((byte *)s__s__d____had_to_restore__d_00433ce4);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc) + 0x6c))
                (**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc));
    }
    if (param_1 == 0) {
      FUN_004028c2(DAT_00438434);
      iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                        (DAT_00438434,&local_2c,
                         **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),&local_3c,
                         0x1000000,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_s_00433d14);
      }
    }
    else if (param_1 == 1) {
      FUN_004028c2(DAT_00438438);
      iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                        (DAT_00438438,&local_2c,
                         **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),&local_3c,
                         0x1008000,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433d84);
      }
    }
    else if (param_1 == 2) {
      FUN_004028c2(DAT_00438418);
      iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                        (DAT_00438418,&local_2c,
                         **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_2 * 0xc),&local_3c,
                         0x1008000,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____set_mem_image___d__to_b_00433dfc);
      }
    }
  }
  return;
}

