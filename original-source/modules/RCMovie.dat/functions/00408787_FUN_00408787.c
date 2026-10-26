/*
 * FUN_00408787 at 00408787
 * undefined4 __thiscall FUN_00408787(void * this, int param_1, undefined4 * param_2)
 * Address ranges: 00408787-0040887c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00408787(void *this,int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430598);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_004305d0);
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) &&
       (iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x4c))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),*param_2,param_2[1]
                           ,param_2[2],0,this), iVar1 != 0)) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_setting_sound_pos_00430618);
    }
  }
  return 0;
}

