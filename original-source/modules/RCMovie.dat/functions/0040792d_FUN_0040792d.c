/*
 * FUN_0040792d at 0040792d
 * undefined4 __thiscall FUN_0040792d(void * this, int param_1, int param_2)
 * Address ranges: 0040792d-00407a44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040792d(void *this,int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ffc8);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) == 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_00430000);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      if ((param_2 < -10000) || (10000 < param_2)) {
        FUN_0040187a((byte *)s__s__d____attempt_at_setting_buff_00430048);
      }
      iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x40))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),param_2,this);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430088);
      }
    }
  }
  return 0;
}

