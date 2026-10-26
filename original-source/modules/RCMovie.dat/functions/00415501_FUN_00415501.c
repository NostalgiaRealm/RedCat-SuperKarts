/*
 * FUN_00415501 at 00415501
 * undefined4 __cdecl FUN_00415501(LPCSTR param_1)
 * Address ranges: 00415501-00415dbc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00415501(LPCSTR param_1)

{
  undefined4 uVar1;
  HLOCAL pvVar2;
  uint uVar3;
  int local_174;
  uint local_170;
  short *local_16c;
  int local_168;
  int local_164;
  uint local_160;
  short *local_15c;
  int local_158;
  int local_154;
  short *local_150;
  int local_14c;
  int local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  int *local_138;
  int local_134;
  short local_130 [2];
  int local_12c;
  char *local_128;
  short local_124 [2];
  short local_120 [2];
  char local_11c [256];
  int local_1c;
  short *local_18;
  uint local_14;
  uint local_10;
  int local_c;
  short local_8 [2];
  
  local_138 = FUN_00409d69(param_1);
  if (local_138 == (int *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_004015a6((byte *)s_resetting_data_00435594);
    _memset(local_11c,0,0x100);
    FUN_004015a6((byte *)s_reading_init_data_004355a4);
    FUN_0041f3be(local_11c,1,0x100,local_138);
    FUN_0041f3be((char *)local_120,1,2,local_138);
    FUN_0041f3be((char *)local_8,1,2,local_138);
    FUN_0041f3be((char *)local_124,1,2,local_138);
    FUN_0041f3be((char *)local_130,1,2,local_138);
    FUN_004015a6((byte *)s_reading_init_data_done_004355b8);
    *(int *)(param_1 + 0x80) = (int)local_120[0];
    *(int *)(param_1 + 0x84) = (int)local_8[0];
    *(int *)(param_1 + 0x70) = (int)local_124[0];
    *(int *)(param_1 + 0x74) = (int)local_130[0];
    param_1[0x88] = '\0';
    param_1[0x89] = '\0';
    param_1[0x8a] = '\0';
    param_1[0x8b] = '\0';
    param_1[0x8c] = '\0';
    param_1[0x8d] = '\0';
    param_1[0x8e] = '\0';
    param_1[0x8f] = '\0';
    param_1[0x6c] = '\x01';
    param_1[0x6d] = '\0';
    param_1[0x6e] = '\0';
    param_1[0x6f] = '\0';
    param_1[100] = '\0';
    param_1[0x65] = '\x01';
    param_1[0x66] = '\0';
    param_1[0x67] = '\0';
    pvVar2 = LocalAlloc(0x40,0xc00);
    *(HLOCAL *)(param_1 + 0x68) = pvVar2;
    if (*(int *)(param_1 + 0x68) == 0) {
      uVar1 = 2000;
    }
    else {
      for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
        pvVar2 = LocalAlloc(0x40,0xc);
        *(HLOCAL *)(*(int *)(param_1 + 0x68) + local_1c * 0xc) = pvVar2;
        if (*(int *)(*(int *)(param_1 + 0x68) + local_1c * 0xc) == 0) {
          return 2000;
        }
      }
      local_128 = LocalAlloc(0x40,*(int *)(param_1 + 0x80) * *(int *)(param_1 + 0x84));
      if (local_128 == (char *)0x0) {
        uVar1 = 2000;
      }
      else {
        local_c = FUN_004152a3();
        FUN_004152ad((int)param_1);
        FUN_004015a6((byte *)s_resetting_types_004355d0);
        for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
          *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_1c * 0xc) = 0;
        }
        FUN_004015a6((byte *)s_reading_char_data_004355e4);
        for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
          if (local_11c[local_1c] == '\0') {
            FUN_004015a6((byte *)s___d__not_available_004355f8);
            FUN_0041f3be(local_128,*(int *)(param_1 + 0x80) * *(int *)(param_1 + 0x84),1,local_138);
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_1c * 0xc) = 0;
          }
          else {
            FUN_004015a6((byte *)s___d__WEL_available_0043560c);
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 4) =
                 *(undefined4 *)(param_1 + 0x80);
            *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 8) =
                 *(undefined4 *)(param_1 + 0x84);
            *(undefined4 *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_1c * 0xc) = 1;
            FUN_004015a6((byte *)s_creating_surface__d___d__d__00435620);
            uVar1 = FUN_004028e3(*(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 4),
                                 *(undefined4 *)
                                  (*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) + 8));
            **(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) = uVar1;
            if (**(int **)(*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) == 0) {
              return 2000;
            }
            if (DAT_0043d754 == 0) {
              local_10 = DAT_0042c4d0;
            }
            else if (DAT_0043d754 == 4) {
              local_10 = FUN_0040de93(DAT_00438474,0x18);
            }
            else {
              local_10 = FUN_0040de93(DAT_0042c4d0,8);
            }
            local_14 = local_10;
            FUN_004015a6((byte *)s_color_keying_surface__d___d__d__00435640);
            local_12c = (**(code **)(*(int *)**(undefined4 **)
                                               (*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc) +
                                    0x74))(**(undefined4 **)
                                             (*(int *)(DAT_0043db88 + 0x68) + local_1c * 0xc),8,
                                           &local_14);
            if (local_12c != 0) {
              FUN_00401f61(local_12c);
              FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_00435670);
            }
            FUN_004015a6((byte *)s_Reading_data_to_surface__d___d___00435698);
            local_18 = (short *)FUN_0041531a(local_1c,&local_134);
            switch(DAT_0043d754) {
            case 0:
              for (local_174 = 0; local_174 < *(int *)(param_1 + 0x84); local_174 = local_174 + 1) {
                FUN_0041f3be((char *)local_18,1,*(uint *)(param_1 + 0x80),local_138);
                local_18 = (short *)((int)local_18 + local_134);
              }
              break;
            case 1:
              for (local_158 = 0; local_158 < *(int *)(param_1 + 0x84); local_158 = local_158 + 1) {
                local_15c = local_18;
                for (local_154 = 0; local_154 < *(int *)(param_1 + 0x80); local_154 = local_154 + 1)
                {
                  FUN_0041f3be((char *)&local_160,1,1,local_138);
                  uVar3 = FUN_0040de93(local_160 & 0xff,8);
                  *local_15c = (short)uVar3;
                  local_15c = local_15c + 1;
                }
                local_18 = (short *)((int)local_18 + local_134);
              }
              break;
            case 2:
              for (local_168 = 0; local_168 < *(int *)(param_1 + 0x84); local_168 = local_168 + 1) {
                local_16c = local_18;
                for (local_164 = 0; local_164 < *(int *)(param_1 + 0x80); local_164 = local_164 + 1)
                {
                  FUN_0041f3be((char *)&local_170,1,1,local_138);
                  FUN_0040e0c3(local_170 & 0xff,8,local_16c);
                  local_16c = (short *)((int)local_16c + 3);
                }
                local_18 = (short *)((int)local_18 + local_134);
              }
              break;
            case 4:
              for (local_14c = 0; local_14c < *(int *)(param_1 + 0x84); local_14c = local_14c + 1) {
                local_150 = local_18;
                for (local_148 = 0; local_148 < *(int *)(param_1 + 0x80); local_148 = local_148 + 1)
                {
                  FUN_0041f3be((char *)&local_140,1,1,local_138);
                  FUN_0041f3be((char *)&local_144,1,1,local_138);
                  FUN_0041f3be((char *)&local_13c,1,1,local_138);
                  uVar3 = FUN_0040de93(local_140 & 0xff | (local_144 & 0xff) << 8 |
                                       (local_13c & 0xff) << 0x10,0x18);
                  *local_150 = (short)uVar3;
                  local_150 = local_150 + 1;
                }
                local_18 = (short *)((int)local_18 + local_134);
              }
            }
            FUN_00415412(local_1c,local_18);
            if ((local_138[3] & 0x20U) != 0) {
              return 0x3e9;
            }
          }
        }
        *(undefined4 *)(DAT_0043db88 + 0x90) = 0x457;
        FUN_004152ad(local_c);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

