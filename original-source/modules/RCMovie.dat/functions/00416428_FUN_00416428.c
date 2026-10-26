/*
 * FUN_00416428 at 00416428
 * undefined4 __cdecl FUN_00416428(LPCSTR param_1)
 * Address ranges: 00416428-00416d2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00416428(LPCSTR param_1)

{
  undefined4 uVar1;
  HLOCAL pvVar2;
  uint uVar3;
  int iVar4;
  int local_878;
  uint local_874;
  short *local_870;
  int local_86c;
  int local_868;
  uint local_864;
  short *local_860;
  int local_85c;
  int local_858;
  short *local_854;
  int local_850;
  int local_84c;
  uint local_848;
  uint local_844;
  uint local_840;
  int *local_83c;
  int local_838;
  int local_834;
  short local_830 [2];
  short local_82c [2];
  int aiStack_828 [511];
  short local_2c [2];
  int local_28;
  short local_24 [2];
  short *local_20;
  int local_1c;
  int local_18;
  int local_14;
  short local_10 [2];
  uint local_c;
  uint local_8;
  
  local_1c = 0xffffffff;
  local_28 = 0xffffffff;
  local_18 = FUN_004152a3();
  FUN_004015a6((byte *)s_Load_new_ascii_set__s__004356bc);
  local_83c = FUN_00409d69(param_1);
  if (local_83c == (int *)0x0) {
    uVar1 = 1000;
  }
  else {
    _memset(local_82c,0,0x800);
    FUN_0041f3be((char *)local_82c,8,0x100,local_83c);
    local_1c = -1;
    local_28 = -1;
    for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
      if (((0 < local_82c[local_14 * 4]) && (0 < *(short *)((int)aiStack_828 + local_14 * 8 + -2)))
         && (iVar4 = (int)local_82c[local_14 * 4] *
                     (int)*(short *)((int)aiStack_828 + local_14 * 8 + -2),
            iVar4 - local_1c != 0 && local_1c <= iVar4)) {
        local_1c = (int)local_82c[local_14 * 4] *
                   (int)*(short *)((int)aiStack_828 + local_14 * 8 + -2);
        local_28 = local_14;
      }
    }
    if ((local_1c < 0) || (local_28 < 0)) {
      uVar1 = 1000;
    }
    else {
      FUN_004015a6((byte *)s_Largest_buffer_size_of_character_004356d8);
      FUN_0041f3be((char *)local_2c,1,2,local_83c);
      FUN_0041f3be((char *)local_830,1,2,local_83c);
      FUN_0041f3be((char *)local_10,1,2,local_83c);
      FUN_0041f3be((char *)local_24,1,2,local_83c);
      param_1[0x6c] = '\x03';
      param_1[0x6d] = '\0';
      param_1[0x6e] = '\0';
      param_1[0x6f] = '\0';
      param_1[100] = '\0';
      param_1[0x65] = '\x01';
      param_1[0x66] = '\0';
      param_1[0x67] = '\0';
      *(int *)(param_1 + 0x70) = (int)local_2c[0];
      *(int *)(param_1 + 0x74) = (int)local_830[0];
      *(int *)(param_1 + 0x78) = (int)local_10[0];
      *(int *)(param_1 + 0x7c) = (int)local_24[0];
      *(int *)(param_1 + 0x80) = (int)local_82c[local_28 * 4];
      *(int *)(param_1 + 0x84) = (int)*(short *)((int)aiStack_828 + local_28 * 8 + -2);
      param_1[0x88] = '\0';
      param_1[0x89] = '\0';
      param_1[0x8a] = '\0';
      param_1[0x8b] = '\0';
      param_1[0x8c] = '\0';
      param_1[0x8d] = '\0';
      param_1[0x8e] = '\0';
      param_1[0x8f] = '\0';
      pvVar2 = LocalAlloc(0x40,0xc00);
      *(HLOCAL *)(param_1 + 0x68) = pvVar2;
      if (*(int *)(param_1 + 0x68) == 0) {
        uVar1 = 2000;
      }
      else {
        for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
          pvVar2 = LocalAlloc(0x40,0xc);
          *(HLOCAL *)(*(int *)(param_1 + 0x68) + local_14 * 0xc) = pvVar2;
          if (*(int *)(*(int *)(param_1 + 0x68) + local_14 * 0xc) == 0) {
            return 2000;
          }
        }
        FUN_004152ad((int)param_1);
        FUN_004015a6((byte *)s_Importing_char_data_00435718);
        for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
          if ((local_82c[local_14 * 4] < 1) ||
             (*(short *)((int)aiStack_828 + local_14 * 8 + -2) < 1)) {
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_14 * 0xc) = 0;
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4) = 0;
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8) = 0;
          }
          else {
            *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4) =
                 (int)local_82c[local_14 * 4];
            *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8) =
                 (int)*(short *)((int)aiStack_828 + local_14 * 8 + -2);
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_14 * 0xc) = 1;
            FUN_00409b18(local_83c,aiStack_828[local_14 * 2],0);
            uVar1 = FUN_004028e3(*(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4),
                                 *(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8));
            **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) = uVar1;
            if (**(int **)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) == 0) {
              return 2000;
            }
            if (DAT_0043d754 == 0) {
              local_8 = DAT_0042c4d0;
            }
            else if (DAT_0043d754 == 4) {
              local_8 = FUN_0040de93(DAT_00438474,0x18);
            }
            else {
              local_8 = FUN_0040de93(DAT_0042c4d0,8);
            }
            local_c = local_8;
            local_838 = (**(code **)(*(int *)**(undefined4 **)
                                               (*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) +
                                    0x74))(**(undefined4 **)
                                             (*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc),8,
                                           &local_c);
            if (local_838 != 0) {
              FUN_00401f61(local_838);
              FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0043573c);
            }
            local_20 = (short *)FUN_0041531a(local_14,&local_834);
            switch(DAT_0043d754) {
            case 0:
              for (local_878 = 0;
                  local_878 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_878 = local_878 + 1) {
                FUN_0041f3be((char *)local_20,1,
                             *(uint *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4)
                             ,local_83c);
                local_20 = (short *)((int)local_20 + local_834);
              }
              break;
            case 1:
              for (local_85c = 0;
                  local_85c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_85c = local_85c + 1) {
                local_860 = local_20;
                for (local_858 = 0;
                    local_858 <
                    *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4);
                    local_858 = local_858 + 1) {
                  FUN_0041f3be((char *)&local_864,1,1,local_83c);
                  uVar3 = FUN_0040de93(local_864 & 0xff,8);
                  *local_860 = (short)uVar3;
                  local_860 = local_860 + 1;
                }
                local_20 = (short *)((int)local_20 + local_834);
              }
              break;
            case 2:
              for (local_86c = 0;
                  local_86c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_86c = local_86c + 1) {
                local_870 = local_20;
                for (local_868 = 0;
                    local_868 <
                    *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4);
                    local_868 = local_868 + 1) {
                  FUN_0041f3be((char *)&local_874,1,1,local_83c);
                  FUN_0040e0c3(local_874 & 0xff,8,local_870);
                  local_870 = (short *)((int)local_870 + 3);
                }
                local_20 = (short *)((int)local_20 + local_834);
              }
              break;
            case 4:
              for (local_850 = 0;
                  local_850 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 8)
                  ; local_850 = local_850 + 1) {
                local_854 = local_20;
                for (local_84c = 0;
                    local_84c <
                    *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_14 * 0xc) + 4);
                    local_84c = local_84c + 1) {
                  FUN_0041f3be((char *)&local_844,1,1,local_83c);
                  FUN_0041f3be((char *)&local_848,1,1,local_83c);
                  FUN_0041f3be((char *)&local_840,1,1,local_83c);
                  uVar3 = FUN_0040de93(local_844 & 0xff | (local_848 & 0xff) << 8 |
                                       (local_840 & 0xff) << 0x10,0x18);
                  *local_854 = (short)uVar3;
                  local_854 = local_854 + 1;
                }
                local_20 = (short *)((int)local_20 + local_834);
              }
            }
            FUN_00415412(local_14,local_20);
            FUN_004015a6((byte *)s_Data_read_to_surface__d___d__d__00435764);
            if ((local_83c[3] & 0x20U) != 0) {
              return 0x3e9;
            }
          }
        }
        *(undefined4 *)(DAT_0043db88 + 0x90) = 0x457;
        FUN_004152ad(local_18);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

