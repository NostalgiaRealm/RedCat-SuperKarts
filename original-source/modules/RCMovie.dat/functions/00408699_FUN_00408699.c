/*
 * FUN_00408699 at 00408699
 * undefined4 __thiscall FUN_00408699(void * this, int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 00408699-00408786
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall
FUN_00408699(void *this,int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004304dc);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_00430514);
    }
    if ((*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) &&
       (iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x4c))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),param_2,param_3,
                           param_4,0,this), iVar1 != 0)) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_setting_sound_pos_0043055c);
    }
  }
  return 0;
}

