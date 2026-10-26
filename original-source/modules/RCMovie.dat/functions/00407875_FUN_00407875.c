/*
 * FUN_00407875 at 00407875
 * undefined4 __cdecl FUN_00407875(int param_1)
 * Address ranges: 00407875-0040792c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00407875(int param_1)

{
  undefined4 local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    local_c = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ff54);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      local_c = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x18))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0042ff8c);
      }
    }
  }
  return local_c;
}

