/*
 * FUN_00408a61 at 00408a61
 * undefined4 __cdecl FUN_00408a61(int param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4)
 * Address ranges: 00408a61-00408b64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_00408a61(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_00409770(&local_14);
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004307cc);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) != 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_00430804);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 0x28))
                          (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44),&local_14);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____error_getting_sound_pos_0043084c);
      }
      *param_2 = local_14;
      *param_3 = local_10;
      *param_4 = local_c;
    }
  }
  return 0;
}

