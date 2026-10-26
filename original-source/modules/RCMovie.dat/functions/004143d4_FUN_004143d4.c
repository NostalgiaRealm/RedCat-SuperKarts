/*
 * FUN_004143d4 at 004143d4
 * undefined4 __cdecl FUN_004143d4(LPCSTR param_1, int * param_2, int param_3, int param_4)
 * Address ranges: 004143d4-0041461a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004143d4(LPCSTR param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  FILE *local_a0;
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
  
  local_a0 = (FILE *)FUN_00409d69(param_1);
  if (local_a0 == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    FUN_0041f3be(&local_8c,0x80,1,(int *)local_a0);
    FUN_004015a6((byte *)s__s__d____header_read__00434fdc);
    if ((local_a0->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00435004);
      FUN_0040312d(param_2,&local_94,&local_98);
      if ((local_8c == '\n') && (local_8b == '\x05')) {
        local_b8 = ((int)local_84 - (int)local_88) + 1;
        local_b4 = ((int)local_82 - (int)local_86) + 1;
        local_bc = 0;
        local_c0 = 0;
        local_ac = param_4;
        local_a4 = param_4 + local_b4;
        local_b0 = param_3;
        local_a8 = param_3 + local_b8;
        local_c = local_b8;
        local_8 = local_b4;
        local_90 = (int *)FUN_004028e3(local_b8,local_b4);
        FUN_004015a6((byte *)s_creation_succesfull_00435028);
        FUN_00414f40(local_90,&local_a0->_ptr,(int)local_4a,local_8);
        FUN_004015a6((byte *)s_blitting_to_destination_00435040);
        local_9c = (**(code **)(*param_2 + 0x14))(param_2,&local_b0,local_90,&local_c0,0x1000000,0);
        if (local_9c != 0) {
          FUN_00401f61(local_9c);
          FUN_0040187a((byte *)s__s__d____blitting_error___s__00435068);
        }
        FUN_004015a6((byte *)s_Release_buffer_surface_00435088);
        (**(code **)(*local_90 + 8))(local_90);
      }
      FUN_004015a6((byte *)s__s__d____closing_004350ac);
      FUN_00409f20(local_a0);
      uVar1 = 0;
    }
    else {
      FUN_00409f20(local_a0);
      uVar1 = 0;
    }
  }
  return uVar1;
}

