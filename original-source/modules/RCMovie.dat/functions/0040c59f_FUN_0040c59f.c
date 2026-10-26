/*
 * FUN_0040c59f at 0040c59f
 * undefined4 __cdecl FUN_0040c59f(LPCSTR param_1, LPCSTR param_2, int param_3)
 * Address ranges: 0040c59f-0040cae2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040c59f(LPCSTR param_1,LPCSTR param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  short *local_58;
  int local_54;
  uint local_50;
  short *local_4c;
  int local_48;
  uint local_44;
  short *local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  short local_2c [2];
  FILE *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  FILE *local_c;
  short *local_8;
  
  if (DAT_0043d6f4 == 0) {
    uVar1 = 0;
  }
  else {
    local_28 = (FILE *)FUN_0041f4c6(param_1,&DAT_00432144);
    if (local_28 == (FILE *)0x0) {
      uVar1 = 1000;
    }
    else {
      local_c = (FILE *)FUN_0041f4c6(param_2,&DAT_00432148);
      if (local_c == (FILE *)0x0) {
        FUN_0041f368(local_28);
        uVar1 = 1000;
      }
      else {
        DAT_0043d6ec = 0;
        for (local_20 = 0; -1 < *(int *)(param_3 + local_20 * 4); local_20 = local_20 + 1) {
          FUN_0041fd07((int *)local_c,*(int *)(param_3 + local_20 * 4) * 4 + -2,0);
          if ((local_c->_flag & 0x20U) != 0) {
            FUN_0040187a((byte *)s__s__d____index_file_seek_error___00432158);
          }
          FUN_0041f3be((char *)&local_1c,1,4,(int *)local_c);
          if ((local_c->_flag & 0x20U) != 0) {
            FUN_0041f368(local_28);
            return 0x3e9;
          }
          FUN_0041fd07((int *)local_28,local_1c,0);
          if ((local_28->_flag & 0x20U) != 0) {
            FUN_0041f368(local_28);
            return 0x3e9;
          }
          local_18 = *(int *)(param_3 + local_20 * 4);
          FUN_0041f3be((char *)(DAT_0043d6e8 + 8 + local_18 * 0x20),1,2,(int *)local_28);
          FUN_0041f3be((char *)(DAT_0043d6e8 + 0xc + local_18 * 0x20),1,2,(int *)local_28);
          FUN_0041f3be((char *)local_2c,1,2,(int *)local_28);
          *(int *)(DAT_0043d6e8 + 0x10 + local_18 * 0x20) = (int)local_2c[0];
          FUN_0041f3be((char *)local_2c,1,2,(int *)local_28);
          *(int *)(DAT_0043d6e8 + 0x14 + local_18 * 0x20) = (int)local_2c[0];
          local_10 = *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20) *
                     *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
          DAT_0043d6ec = DAT_0043d6ec + local_10;
          FUN_0040bfec(local_18);
          FUN_0040c4aa(local_18,&local_24);
          local_8 = *(short **)(DAT_0043d6e8 + local_18 * 0x20);
          switch(DAT_0043d754) {
          case 0:
            FUN_004015a6((byte *)s_pf_none_004321e4);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              FUN_0041f3be((char *)local_8,1,*(uint *)(DAT_0043d6e8 + 8 + local_18 * 0x20),
                           (int *)local_28);
              local_8 = (short *)((int)local_8 + local_24);
            }
            break;
          case 1:
            FUN_004015a6((byte *)s_converting_to_16_bits_004321b4);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              local_4c = local_8;
              for (local_48 = 0; local_48 < *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20);
                  local_48 = local_48 + 1) {
                FUN_0041f3be((char *)&local_44,1,1,(int *)local_28);
                uVar2 = FUN_0040de93(local_44 & 0xff,8);
                *local_4c = (short)uVar2;
                local_4c = local_4c + 1;
              }
              local_8 = (short *)((int)local_8 + local_24);
            }
            break;
          case 2:
            FUN_004015a6((byte *)s_converting_to_24_bits_004321cc);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              local_58 = local_8;
              for (local_54 = 0; local_54 < *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20);
                  local_54 = local_54 + 1) {
                FUN_0041f3be((char *)&local_50,1,1,(int *)local_28);
                FUN_0040e0c3(local_50 & 0xff,8,local_58);
                local_58 = (short *)((int)local_58 + 3);
              }
              local_8 = (short *)((int)local_8 + local_24);
            }
            break;
          case 4:
            FUN_004015a6((byte *)s_converting_from_24_to_16_bits_00432194);
            for (local_14 = 0; local_14 < *(int *)(DAT_0043d6e8 + 0xc + local_18 * 0x20);
                local_14 = local_14 + 1) {
              local_40 = local_8;
              for (local_3c = 0; local_3c < *(int *)(DAT_0043d6e8 + 8 + local_18 * 0x20);
                  local_3c = local_3c + 1) {
                FUN_0041f3be((char *)&local_34,1,1,(int *)local_28);
                FUN_0041f3be((char *)&local_38,1,1,(int *)local_28);
                FUN_0041f3be((char *)&local_30,1,1,(int *)local_28);
                uVar2 = FUN_0040de93(local_34 & 0xff | (local_38 & 0xff) << 8 |
                                     (local_30 & 0xff) << 0x10,0x18);
                *local_40 = (short)uVar2;
                local_40 = local_40 + 1;
              }
              local_8 = (short *)((int)local_8 + local_24);
            }
          }
          FUN_0040c531(local_18);
        }
        FUN_0041f368(local_c);
        FUN_0041f368(local_28);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

