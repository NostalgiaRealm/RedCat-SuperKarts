/*
 * FUN_0040778d at 0040778d
 * undefined4 __thiscall FUN_0040778d(void * this, int param_1, int param_2)
 * Address ranges: 0040778d-00407874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040778d(void *this,int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fe94);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      if ((param_2 < -10000) || (-100 < param_2)) {
        FUN_0040187a((byte *)s__s__d____attempt_at_setting_buff_0042fecc);
      }
      iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x3c))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),param_2,this);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ff18);
      }
    }
  }
  return 0;
}

