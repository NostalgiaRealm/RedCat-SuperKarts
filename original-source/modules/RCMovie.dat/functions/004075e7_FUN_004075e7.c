/*
 * FUN_004075e7 at 004075e7
 * undefined4 __thiscall FUN_004075e7(void * this, int param_1, int param_2)
 * Address ranges: 004075e7-004076d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004075e7(void *this,int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fd58);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      if (((param_2 < 100) || (100000 < param_2)) && (param_2 != 0)) {
        FUN_0040187a((byte *)s__s__d____attempt_at_setting_buff_0042fd90);
      }
      iVar1 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x44))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),param_2,this);
      if (iVar1 != 0) {
        FUN_00405af0(iVar1);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042fde4);
      }
    }
  }
  return 0;
}

