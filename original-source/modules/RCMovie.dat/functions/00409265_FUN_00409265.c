/*
 * FUN_00409265 at 00409265
 * int __cdecl FUN_00409265(uint * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 00409265-00409534
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl
FUN_00409265(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0043d43c == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_00406ae8(1);
    if (iVar1 == -1) {
      iVar1 = -1;
    }
    else {
      FUN_004015a6((byte *)s_new_3d_buffer_used__d_00430c28);
      iVar2 = FUN_00407c85((LPCSTR)param_1,iVar1);
      if (iVar2 == 0) {
        *(undefined4 *)(DAT_0043d420 + 0x30 + iVar1 * 0x44) = 1;
        FUN_0041f7a0((uint *)(DAT_0043d420 + iVar1 * 0x44),param_1);
        *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) =
             *(int *)(DAT_0043d420 + 0x38 + iVar1 * 0x44) + 1;
        iVar2 = FUN_00406327(iVar1);
        if (iVar2 == 0) {
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + iVar1 * 0x44) + 0x30))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + iVar1 * 0x44),0,0,param_2);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_playing_sound__d___00430c4c);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x4c))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),param_3,param_4,
                             param_5,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430c80);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x44))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),0x41200000,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430cb8);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x40))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),0x461c4000,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430cf0);
          }
          iVar2 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + iVar1 * 0x44) + 0x48))
                            (*(undefined4 *)(DAT_0043d420 + 0x2c + iVar1 * 0x44),1,0);
          if (iVar2 != 0) {
            FUN_00405af0(iVar2);
            FUN_0040187a((byte *)s__s__d____error_setting_position___00430d28);
          }
        }
        else {
          FUN_0040187a((byte *)s__s__d____sound_buffer__d_type__d_00430d60);
        }
      }
      else {
        iVar1 = -1;
      }
    }
  }
  return iVar1;
}

