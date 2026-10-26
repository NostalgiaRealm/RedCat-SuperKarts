/*
 * FUN_00414159 at 00414159
 * undefined4 __cdecl FUN_00414159(LPCSTR param_1, int * param_2)
 * Address ranges: 00414159-004143d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00414159(LPCSTR param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 local_3c0;
  undefined4 local_3bc;
  int local_3b8;
  int local_3b4;
  undefined4 local_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  undefined4 local_3a4;
  FILE *local_3a0;
  char local_39c [768];
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int *local_90;
  char local_8c;
  char local_8b;
  short local_88;
  short local_86;
  short local_84;
  short local_82;
  short local_4a;
  int local_c;
  int local_8;
  
  local_3a0 = (FILE *)FUN_00409d69(param_1);
  if (local_3a0 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    if (DAT_0043d754 != 0) {
      FUN_00413622((int *)local_3a0,local_39c);
    }
    FUN_00409b18((int *)local_3a0,0,0);
    FUN_0041f3be(&local_8c,0x80,1,(int *)local_3a0);
    FUN_004015a6((byte *)s__s__d____header_read__00434eec);
    if ((local_3a0->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434f14);
      FUN_0040312d(param_2,&local_94,&local_98);
      if ((local_8c == '\n') && (local_8b == '\x05')) {
        local_3b8 = ((int)local_84 - (int)local_88) + 1;
        local_3b4 = ((int)local_82 - (int)local_86) + 1;
        local_3bc = 0;
        local_3c0 = 0;
        local_3ac = 0;
        local_3a4 = local_98;
        local_3b0 = 0;
        local_3a8 = local_94;
        local_c = local_3b8;
        local_8 = local_3b4;
        local_90 = (int *)FUN_004028e3(local_3b8,local_3b4);
        FUN_004015a6((byte *)s_creation_succesfull_00434f38);
        FUN_00414f40(local_90,&local_3a0->_ptr,(int)local_4a,local_8);
        FUN_004015a6((byte *)s_blitting_to_destination_00434f50);
        local_9c = (**(code **)(*param_2 + 0x14))
                             (param_2,&local_3b0,local_90,&local_3c0,0x1000000,0);
        if (local_9c != 0) {
          FUN_00401f61(local_9c);
          FUN_0040187a((byte *)s__s__d____blitting_error___s__00434f78);
        }
        FUN_004015a6((byte *)s_Release_buffer_surface_00434f98);
        (**(code **)(*local_90 + 8))(local_90);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434fbc);
      FUN_00409f20(local_3a0);
      uVar1 = 0;
    }
    else {
      FUN_00409f20(local_3a0);
      uVar1 = 0;
    }
  }
  return uVar1;
}

