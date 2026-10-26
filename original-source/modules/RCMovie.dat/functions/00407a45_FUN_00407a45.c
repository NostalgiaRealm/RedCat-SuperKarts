/*
 * FUN_00407a45 at 00407a45
 * undefined4 __cdecl FUN_00407a45(int param_1)
 * Address ranges: 00407a45-00407b29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00407a45(int param_1)

{
  undefined4 local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    local_c = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004300c4);
    }
    if (*(int *)(DAT_0043d420 + 0x34 + param_1 * 0x44) == 1) {
      FUN_0040187a((byte *)s__s__d____type_sound_buffer__d_in_004300fc);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      local_c = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x1c))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_00430144);
      }
    }
  }
  return local_c;
}

