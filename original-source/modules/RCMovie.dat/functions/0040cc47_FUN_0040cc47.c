/*
 * FUN_0040cc47 at 0040cc47
 * undefined4 __cdecl FUN_0040cc47(LPCSTR param_1, uint param_2)
 * Address ranges: 0040cc47-0040d17a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040cc47(LPCSTR param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  short *local_64;
  int local_60;
  uint local_5c;
  short *local_58;
  int local_54;
  uint local_50;
  short *local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  short local_38 [2];
  FILE *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  short local_20 [2];
  short local_1c [2];
  short local_18 [2];
  int local_14;
  short *local_10;
  short local_c [2];
  uint local_8;
  
  local_8 = 0;
  local_24 = 4;
  local_34 = (FILE *)FUN_0041f4c6(param_1,&DAT_00432220);
  if (local_34 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_0041fdc2((int *)local_34);
    FUN_0041f3be((char *)local_18,1,2,(int *)local_34);
    DAT_00431b64 = local_18[0] + 1;
    FUN_004015a6((byte *)s__s_maxmemimages____d_00432224);
    local_8 = (uint)((param_2 & 1) == 1);
    local_24 = param_2 - local_8;
    iVar2 = FUN_0040be72(DAT_00431b64,local_24);
    if (iVar2 == 0) {
      if (local_8 == 0) {
        if (DAT_0043d6f0 != 0) {
          for (local_2c = 0; local_2c < DAT_00431b64; local_2c = local_2c + 1) {
            *(undefined4 *)(DAT_0043d6e8 + local_2c * 0x20) = 0;
            *(undefined4 *)(DAT_0043d6e8 + 0x1c + local_2c * 0x20) = 0;
            *(int *)(DAT_0043d6e8 + 0x18 + local_2c * 0x20) = local_24;
          }
        }
      }
      else {
        DAT_0043d6f4 = 1;
        FUN_004015a6((byte *)s__s_allocating_images_0043223c);
        for (local_2c = 0; local_2c < DAT_00431b64; local_2c = local_2c + 1) {
          FUN_004015a6((byte *)s__s_allocating_image__d_00432254);
          FUN_0041f3be((char *)local_38,1,2,(int *)local_34);
          FUN_0041f3be((char *)local_20,1,2,(int *)local_34);
          FUN_0041f3be((char *)local_1c,1,2,(int *)local_34);
          FUN_0041f3be((char *)local_c,1,2,(int *)local_34);
          *(int *)(DAT_0043d6e8 + 8 + local_2c * 0x20) = (int)local_38[0];
          *(int *)(DAT_0043d6e8 + 0xc + local_2c * 0x20) = (int)local_20[0];
          *(int *)(DAT_0043d6e8 + 0x10 + local_2c * 0x20) = (int)local_1c[0];
          *(int *)(DAT_0043d6e8 + 0x14 + local_2c * 0x20) = (int)local_c[0];
          local_14 = *(int *)(DAT_0043d6e8 + 8 + local_2c * 0x20) *
                     *(int *)(DAT_0043d6e8 + 0xc + local_2c * 0x20);
          FUN_0040bfec(local_2c);
          FUN_0040c4aa(local_2c,&local_30);
          local_10 = *(short **)(DAT_0043d6e8 + local_2c * 0x20);
          switch(DAT_0043d754) {
          case 0:
            for (local_28 = 0; local_28 < local_20[0]; local_28 = local_28 + 1) {
              FUN_0041f3be((char *)local_10,1,(int)local_38[0],(int *)local_34);
              local_10 = (short *)((int)local_10 + local_30);
            }
            break;
          case 1:
            for (local_28 = 0; local_28 < local_20[0]; local_28 = local_28 + 1) {
              local_58 = local_10;
              for (local_54 = 0; local_54 < local_38[0]; local_54 = local_54 + 1) {
                FUN_0041f3be((char *)&local_50,1,1,(int *)local_34);
                uVar3 = FUN_0040de93(local_50 & 0xff,8);
                *local_58 = (short)uVar3;
                local_58 = local_58 + 1;
              }
              local_10 = (short *)((int)local_10 + local_30);
            }
            break;
          case 2:
            for (local_28 = 0; local_28 < local_20[0]; local_28 = local_28 + 1) {
              local_64 = local_10;
              for (local_60 = 0; local_60 < local_38[0]; local_60 = local_60 + 1) {
                FUN_0041f3be((char *)&local_5c,1,1,(int *)local_34);
                FUN_0040e0c3(local_5c & 0xff,8,local_64);
                local_64 = (short *)((int)local_64 + 3);
              }
              local_10 = (short *)((int)local_10 + local_30);
            }
            break;
          case 4:
            FUN_004015a6((byte *)s_converting_from_24_to_16_bits_0043226c);
            for (local_28 = 0; local_28 < *(int *)(DAT_0043d6e8 + 0xc + local_2c * 0x20);
                local_28 = local_28 + 1) {
              local_4c = local_10;
              for (local_48 = 0; local_48 < *(int *)(DAT_0043d6e8 + 8 + local_2c * 0x20);
                  local_48 = local_48 + 1) {
                FUN_0041f3be((char *)&local_40,1,1,(int *)local_34);
                FUN_0041f3be((char *)&local_44,1,1,(int *)local_34);
                FUN_0041f3be((char *)&local_3c,1,1,(int *)local_34);
                uVar3 = FUN_0040de93(local_40 & 0xff | (local_44 & 0xff) << 8 |
                                     (local_3c & 0xff) << 0x10,0x18);
                *local_4c = (short)uVar3;
                local_4c = local_4c + 1;
              }
              local_10 = (short *)((int)local_10 + local_30);
            }
          }
          FUN_0040c531(local_2c);
          if ((local_34->_flag & 0x20U) != 0) {
            DAT_0043d6f4 = 0;
            FUN_0041f368(local_34);
            return 0x3e9;
          }
        }
        FUN_004015a6((byte *)s__s_allocating_images_done_0043228c);
      }
      FUN_0041f368(local_34);
      DAT_0043d6f4 = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 2000;
    }
  }
  return uVar1;
}

